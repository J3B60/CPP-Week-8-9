#include <stdio.h>
#include <string.h>
float CI(float IDEP, float IR); /*Decleration of float type funcion Calculate Interest*/
float IRD(float IDEP);			/*Declare an Interest Rate*/
int DEP(float *BA, float DEPA);	/*Deposit*/
int WID(float *BA, float WIDA, int TYPE);	/*Withdraw*/

int main(void) {
	float IDEP, IR, NMA, NoM, DEPA, BAC, WIDA, SA, IRS, TRA, HIS[1000][6];	/*Inital Deposit, Interest Rate, Next months new amount, Number of Months Input, Bank Account, Withdraw Amount, Savings Account, Savings Interest, Transfer Value*/
	char TQ;			/*Terminate Answer*/
	int Q, MO, END, SKIP;						/*break outside function, QuestionAnswer*/
	printf("---UoRFIRED - Interest Simulation---\n");
	printf("\nInput Initial Deposit for Current Account: ");	scanf("%f", &IDEP);	/*User Input Inital Dep*/
	printf("Input Initial Deposit for Savings Account: ");		scanf("%f", &SA);	/*User Input Initial Savings*/
	printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
	NMA = IDEP;
	MO = 0;
	END = 0;
	do {
		for (int C = 1; C <= NoM; C++) {	/*Repeat for each month to get results fpr each*/
			MO++;
			IR = IRD(NMA);					/*Get Current Acc Interest Rate*/
			IRS = IRD(SA);					/*Get Savings Interest  Rate*/
			NMA = CI(NMA, IR);				/*Next months new amount after calc*/
			SA = CI(SA, IRS);				/*Next months savings ammount after calc*/
			printf("Current Account Interest Rate: %c %.2f\n", 0x25, IR);		/*IR Current Pre-determined*/
			printf("Savings Account Interest Rate: %c %.2f\n", 0x25, IRS);	/*IR Savings Pre-determined*/
			if (IR == 0) {
				printf("Warning at Overdraft Max");		/*Overdraft limit limit*/
			}
			printf("Month %i Current Amount: %.2f\n", MO, NMA);	/*Output Current for each month*/
			printf("Month %i Savings Amount: %.2f\n\n", MO, SA);	/*Output Savings for each month*/
			HIS[END][0] = (float)MO;		/*HISTORY SAVE*/
			HIS[END][1] = NMA;
			HIS[END][2] = IR;
			HIS[END][3] = SA;
			HIS[END][4] = IRS;
			HIS[END][5] = 1;
			END = END + 1;					/*JUMP TO NEXT LINE*/
		}
		printf("Current Amount after next %i months amount is %c%.2f \n", (int)NoM, 0x9C, NMA);	/*Requested Output Current*/
		printf("Savings Amount after next %i months amount is %c%.2f \n", (int)NoM, 0x9C, SA);	/*Requested Output Savings*/
		printf("_________________________________________\n");
		printf("Continue?...\n y = Continue with previous number of months and deposit\n n = Exit\n r = Reset\n d = Deposit & continue with new number of months\n w = Widthdraw & Continue\n t = Transfer Between Accounts\n h = Account History(y/n/r/d/w/t/h): ");	scanf(" %c", &TQ);	/*Termination Question*/
		switch (TQ) {
		case 'y':	/*Y CONTINUE*/
		case 'Y':
			break;
		case 'N':	/*N TERMINATE*/
		case 'n':
			return 0;
		case 'R':	/*R RESET*/
		case 'r':
			printf("\nInput Initial Current Deposit: ");	scanf("%f", &IDEP);	/*User Input Inital Current Dep*/
			printf("Input Initial Savings Deposit: ");		scanf("%f", &SA);	/*User Input Savings Dep*/
			printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
			NMA = IDEP;
			MO = 0;
			END = -1;
			break;
		case 'D':	/*D DEPOSIT*/
		case 'd':
			printf("Input deposit into Current Account: ");
			scanf("%f", &DEPA);				/*Deposit Input*/
			if (DEP(&NMA, DEPA) == -1) {	/*Input Checking*/
				printf("Error #Invalid Deposit input");
			}
			else {
				printf("Deposit Successful \nCurrent Bank Account: %f\n", NMA); /*Deposit Successful*/
				printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
				END = END + 1;						/*Saved in History*/
				HIS[END][5] = 2;
				HIS[END][0] = (float)MO;
				HIS[END][1] = NMA;
				HIS[END][3] = SA;
			}
			break;
		case 'W':	/*W WITHDRAW*/
		case 'w':
			printf("Input Withdraw from Current Account:");
			scanf("%f", &WIDA);					/*Withdraw Input*/
			if (WID(&NMA, WIDA, 1) == -1) {		/*Input Checking*/
				printf("Error #Invalid Withdraw input");
			}
			else {
				printf("Widthdraw Successful\nCurrent Bank Account: %f\n", NMA);	/*Withdraw Successful*/
				printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
				END = END + 1;						/*Saved in History*/
				HIS[END][5] = 3;
				HIS[END][0] = (float)MO;
				HIS[END][1] = NMA;
				HIS[END][3] = SA;
			}
			break;
		case 'T':	/*T TRANSFER*/
		case 't':
			printf("\n-Bank Transfer-\n1.Current to Savings\n2.Savings to Current\nInput Number:"); scanf("%i", &Q);	/*Transfer Options*/
			if (Q == 1) {
				TRA = 0;
				printf("Input Transfer Amount: "); scanf("%f", &TRA);	/*Transfer Input*/
				if (WID(&NMA, TRA, 2) == -1||DEP(&SA, TRA) == -1) {		/*Input Checking*/
					printf("Error #Transfer not made\nTerminating Program\n");
					return 0;
				}
				else {													/*Transfer*/
					printf("Transfer Successful\nCurrent Bank Account: %f\n", NMA);
					printf("Transfer Successful\nSavings Bank Account: %f\n", SA);
					END = END + 1;				/*Saved in History*/
					HIS[END][5] = 4;
					HIS[END][0] = (float)MO;
					HIS[END][1] = NMA;
					HIS[END][3] = SA;
				}
			}
			else {
				if (Q == 2) {
					TRA = 0;
					printf("Input Transfer Amount: "); scanf("%f", &TRA);	/*Transfer Input*/
					if (WID(&SA, TRA, 2) == -1 || DEP(&NMA, TRA) == -1) {	/*Input Checking*/
						printf("Error #Transfer not made\nTerminating Program\n");
						return 0;
					}
					else {													/*Transfer*/
						printf("Transfer Successful\nCurrent Bank Account: %f\n", NMA);
						printf("Transfer Successful\nSavings Bank Account: %f\n", SA);
						END = END + 1;			/*Saved in History*/
						HIS[END][5] = 5;
						HIS[END][0] = (float)MO;
						HIS[END][1] = NMA;
						HIS[END][3] = SA;
					}
				}
				else {
					printf("Invalid Input-Terminating\n");	/*Terminate if Q is invalid*/
					return 0;
				}
			}
			printf("Next Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
			break;
		case 'H':	/*H HISTORY*/
		case 'h':
			printf("\n\n---HISTORY---\n");
			printf("KEY:\n INT = Interest\n DEP = Deposit\n WID = Withdraw\n TRAC = Transfer From Current\n TRAS = Transfer From Savings\n\n");
			for (int Z = 0; Z <= END; Z++) {	/*History Output*/
				if (HIS[Z][5] == 1) {
					printf("INT: Month %.f |Current Account: %.2f |Current Interest: %.2f |Savings Account: %.2f |Savings Interest: %.2f\n", HIS[Z][0], HIS[Z][1], HIS[Z][2], HIS[Z][3], HIS[Z][4]); /*INTEREST*/
				}
				else {
					if (HIS[Z][5] == 2) {
						printf("DEP: Month %.f |Current Account: %.2f |Savings Account: %.2f\n", HIS[Z][0], HIS[Z][1], HIS[Z][3]);	/*DEPOSIT*/
					}
					else {
						if (HIS[Z][5] == 3) {
							printf("WID: Month %.f |Current Account: %.2f |Savings Account: %.2f\n", HIS[Z][0], HIS[Z][1], HIS[Z][3]);	/*WITHDRAW*/
						}
						else {
							if (HIS[Z][5] == 4) {
								printf("TRAC: Month %.f |Current Account: %.2f |Savings Account: %.2f\n", HIS[Z][0], HIS[Z][1], HIS[Z][3]);	/*TRANSFER CURRENT*/
							}
							else {
								if (HIS[Z][5] == 5) {
									printf("TRAS: Month %.f |Current Account: %.2f |Savings Account: %.2f\n", HIS[Z][0], HIS[Z][1], HIS[Z][3]);	/*TRANSFER SAVINGS*/
								}
							}
						}
					}
				}
			}
			printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
			break;
		default:
			return 0;				/*Default Terminate*/
		}
		END++;						/*END++*/
	} while (1);
}

float CI(float IDEP, float IR) { /*Calculate Interest*/
	return IDEP + IDEP*((IR / 100) / 12); /*Take Initial Deposit and add (Interest Amount = Initial Deposit x Interest Rate as decimal/Number of months*/
}

float IRD(float IDEP) {			/*Declare an Interest Rate*/
	if (IDEP <= -1000) {
		return 0;
	}
	else {
		if (IDEP < -500) {
			return 80;
		}
		else {
			if (IDEP < -100) {
				return 40;
			}
			else {
				if (IDEP < 0) {
					return 20;
				}
				else {
					if (IDEP < 100) {
						return 10;
					}
					else {
						if (IDEP < 200) {
							return 50;
						}
						else {
							if (IDEP < 500) {
								return 80;
							}
							else {
								if (IDEP >= 500) {
									return 90;
								}
							}
						}
					}
				}
			}
		}
	}
}

int DEP(float *BA, float DEPA) {	/*Deposit function*/
	if (DEPA <= 0) {				/*Check input*/
		return -1;
	}
	else {
		*BA = *BA + DEPA;		/*Make Deposit*/
		return 0;
	}
}

int WID(float *BA, float WIDA, int TYPE) {	/*Withdraw Function| *BA = NMA, WIDA = Withdraw Amount, TYPE = ?Current/Savings Cannot go bellow zero */
	if (TYPE == 1) {
		if (WIDA <= 0) {					/*Current*/
			return -1;
		}
		else {
			*BA = *BA - WIDA;				/*Make Withdraw/Transfer*/
			return 0;
		}
	}
	if (TYPE == 2) {						/*Savings*/
		if (WIDA <= 0 || (*BA - WIDA) < 0 || *BA <= 0) {	/*Savings cannot go bellow 0*/
			return -1;
		}
		else {
			*BA = *BA - WIDA;			/*Make Transfer*/
			return 0;
		}
	}
}