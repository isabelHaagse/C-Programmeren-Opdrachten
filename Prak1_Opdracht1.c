
#include <stdio.h>


double belastingCalculator(double inkomsten) {
	double belasting = 0;
	int max_belastbaar_inkomen_schijf1 = 38883;
	int max_belastbaar_inkomen_schijf2 = 78426;
	float belasting_percentage_schijf1 = 0.3575;
	float belasting_percentage_schijf2 = 0.3756;
	float belasting_percentage_schijf3 = 0.4950;

	if (inkomsten > max_belastbaar_inkomen_schijf2) {
		belasting = max_belastbaar_inkomen_schijf1 * belasting_percentage_schijf1 + (max_belastbaar_inkomen_schijf2 - max_belastbaar_inkomen_schijf1) * belasting_percentage_schijf2;
		inkomsten -= max_belastbaar_inkomen_schijf2;
		belasting += inkomsten * belasting_percentage_schijf3;
	}
	else if (inkomsten > max_belastbaar_inkomen_schijf1) {
		belasting = max_belastbaar_inkomen_schijf1 * belasting_percentage_schijf1;
		inkomsten -= max_belastbaar_inkomen_schijf1;
		belasting += inkomsten * belasting_percentage_schijf2;
	}
	else {
		belasting = inkomsten * belasting_percentage_schijf1;
	}

	return belasting;
}


void belastingCalc_main() {

	double inkomsten;
	double belasting = 0;
	
	printf("Voer uw inkomen in: \n");
	scanf_s("%lf", &inkomsten);

	printf("Dan is uw inkomst belasting %.2lf euro.\n", belastingCalculator(inkomsten));
}

