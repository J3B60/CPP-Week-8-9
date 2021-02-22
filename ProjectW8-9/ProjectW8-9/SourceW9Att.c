#include <stdio.h>
float CI(float IDEP, float IR); /*Decleration of float type funcion Calculate Interest*/
float IRD(float IDEP);			/*Declare an Interest Rate*/
int DEP(float *BA, float NMA);

int main(void) {
	float IDEP, IR, NMA, NoM, DEPA;	/*Inital Deposit, Interest Rate, Next months new amount, Number of Months Input*/
	char TQ;					/*Terminate Answer*/
	int EB;						/*break outside switch or function*/
	printf("---UoRFIRED - Interest Simulation---\n");
	printf("\nInput Initial Deposit: ");	scanf("%f", &IDEP);	/*User Input Inital Dep*/
	printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
	NMA = IDEP;
	do {
		for (int C = 1; C <= NoM; C++) {	/*Repeat for each month to get results fpr each*/
			IR = IRD(NMA);					/*Get Interest Rate*/
			NMA = CI(NMA, IR);				/*Next months new amount after calc*/
			printf("Interest Rate: %c %f\n", 0x25, IR); /*IR now Pre-determined*/
			if (IR == 0) {
				printf("Warning at Overdraft Max");		/*Overdraft limit limit*/
			}
			printf("Month %i Amount: %f\n\n", C, NMA);	/*Output for each month*/
		}
		printf("Amount after next %i months amount is %c%f \n", (int)NoM, 0x9C, NMA); /*Requested Output*/
		printf("_________________________________________\n");
		printf("Continue?... \nr#reset \nd#deposit \n(y/n/r/d): ");			 scanf(" %c", &TQ);	/*Termination Question*/
		switch(TQ){
			case 'y':
			case 'Y':
				EB = 0;
				break;
			case 'N':
			case 'n':
				return 0;
			case 'R':
			case 'r':
				printf("\nInput Initial Deposit: ");	scanf("%f", &IDEP);	/*User Input Inital Dep*/
				printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
				NMA = IDEP;
				break;
			case 'D':
			case 'd':
				printf("Input deposit into account: ");
				scanf("%f", &DEPA);
				NMA = DEP(&NMA, DEPA);
			default:
				return 0;
		}
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

int DEP(float* NMA, float DEPA) {
	if (DEPA <= 0) {
		return -1;
	}
	else {
	    &NMA = &NMA+DEPA;
		return 0;
	}
}