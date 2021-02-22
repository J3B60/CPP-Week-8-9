#include <stdio.h>
float CI(float IDEP, float IR); /*Decleration of float type funcion Calculate Interest*/
float IRD(float IDEP);

int main(void) {
	float IDEP, IR, NMA, NoM;	/*Inital Deposit, Interest Rate, Next months new amount, Number of Months Input*/
	char TQ;				/*Terminate Answer*/
	printf("---UoRFIRED - Interest Simulation---\n");
	do {
		printf("\nInput Initial Deposit: ");	scanf("%f", &IDEP);	/*User Input Inital Dep*/
		printf("Number of Months: ");			scanf("%f", &NoM);	/*Input number of Months*/
		NMA = IDEP;
		for (int C = 1; C <= NoM; C++) {
			IR = IRD(NMA);
			NMA = CI(NMA, IR);				/*Next months new amount after calc*/
			printf("Interest Rate: %c %f\n", 0x25, IR); /*IR now Pre-determined*/
			if (IR == 0) {
				printf("###Warning at Overdraft Max\n");
			}
			printf("Month %i Amount: %f\n", C, NMA);
		}
		printf("Amount after next %f months amount is %c%f \n", NoM, 0x9C, NMA); /*Requested Output*/
		printf("_________________________________________\n");
		printf("Continue?... (y/n): ");			 scanf(" %c", &TQ);	/*Termination Question*/
		if (TQ == 'Y' || TQ == 'y');					/*Decision based on input to Termination question*/
		else {
			if (TQ == 'N' || TQ == 'n') {
				break;
			}
			else {
				printf("Invalid input\nTerminating\n");
				break;
			}
		}

	} while (1);
	return 0;
}

float CI(float IDEP, float IR) { /*Calculate Interest*/
	return IDEP + IDEP*((IR / 100) / 12); /*Take Initial Deposit and add (Interest Amount = Initial Deposit x Interest Rate as decimal/Number of months*/
}

float IRD(float IDEP) {
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

//Assumptions: Is it Compound interest/Simple interest?
//should the interest change once the amount reaches that threshold during these blocks of months/Interest remain the same throughout.
//For a block of months do I output a block of values listing new amount each month or just a single value after n months
//