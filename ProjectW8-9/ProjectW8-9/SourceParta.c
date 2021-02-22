#include <stdio.h>
float CI(float IDEP, float IR); /*Decleration of float type funcion Calculate Interest*/

int main(void) {
	float IDEP, IR, NMA;		/*Inital Deposit, Interest Rate, Next months new amount*/
	printf("Input Initial Deposit: "); scanf("%f", &IDEP);	/*User Input Inital Dep*/
	printf("Input Interest Rate: %c", 0x25); scanf("%f", &IR);	/*User Input Interest Rate*/
	NMA = CI(IDEP, IR);				/*Next months new amount after calc*/
	printf("Next months amount is %c%f \n", 0x9C, NMA); /*Requested Output*/
	printf("-----------------------------------------\n"); return 0;
}

float CI(float IDEP, float IR) { /*Calculate Interest*/
	return IDEP + IDEP*((IR / 100)/ 12); /*Take Initial Deposit and add (Interest Amount = Initial Deposit x Interest Rate as decimal/Number of months*/
}
