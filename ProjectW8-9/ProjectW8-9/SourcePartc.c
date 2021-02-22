#include <stdio.h>
float CI(float IDEP, float IR); /*Decleration of float type funcion Calculate Interest*/

int main(void) {
	float IDEP, IR, NMA;	/*Inital Deposit, Interest Rate, Next months new amount*/
	char TQ;				/*Terminate Answer*/
	printf("---UoRFIRED - Interest Simulation---\n");
	do {
		printf("\nInput Initial Deposit: "); scanf("%f", &IDEP);	/*User Input Inital Dep*/
		if (IDEP < 100) {
			IR = 10;
		}
		else {
			if (IDEP < 200) {
				IR = 50;
			}
			else {
				if (IDEP < 500) {
					IR = 80;
				}
				else {
					if (IDEP >= 500) {
						IR = 90;
					}
				}
			}
		}
		printf("Interest Rate: %c %f\n", 0x25, IR);
		NMA = CI(IDEP, IR);				/*Next months new amount after calc*/
		printf("Next months amount is %c%f \n", 0x9C, NMA); /*Requested Output*/
		printf("_________________________________________\n");
		printf("Continue?... (y/n): ");
		scanf(" %c", &TQ);
		if (TQ == 'Y' || TQ == 'y');
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
