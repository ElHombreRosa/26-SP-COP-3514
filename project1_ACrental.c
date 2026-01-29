#include <stdio.h>
#include <stdlib.h>

int main(void){

	int selection;
	int days;
	int charge = 0;
	int firstDay, dailyRate, perWeekMax;
	
	// Taking User Input for AC type
	printf("Please select from four types of AC: 1, 2, 3, and 4\n");
	printf("Enter selection: ");
	scanf("%d", &selection);

	// If User Input Less Than 1 and over 4 its invalid
	if (selection < 1 || selection > 4){
	printf("Invalid selection. Select from 1 to 4.\n");
	return EXIT_SUCCESS;	
}	
	// User Input for days
	printf("Enter days: ");
	scanf("%d", &days);
	// If days negative its invalid
	if (days < 0){
		printf("Invalid days.\n");
		return EXIT_SUCCESS;

}
	// Selection price for each AC type
	if (selection == 1){
		firstDay = 50; dailyRate = 30; perWeekMax = 160;
}	else if (selection == 2){
		firstDay = 60; dailyRate= 35; perWeekMax = 200;
}	else if (selection == 3){
		firstDay = 80; dailyRate = 50; perWeekMax = 280;
}	else if (selection == 4){
		firstDay = 200; dailyRate = 120; perWeekMax  = 550;
}	
	// Calc the Price that is charge base on number of days users wants the AC for
	if (days == 0){
		charge = 0;
}	else if (days < 7){ // 1 to 7 day charge //
		charge = firstDay + (days - 1) * dailyRate;
		if (charge > perWeekMax){
			charge = perWeekMax; // if charge is more than per week max cost within the 7 days put the cap //
}
}	else {
		charge = (days/7) * perWeekMax; // if days over 7 days charge per weekmax each week plus remanding days //
		int remainderDays = days % 7;
		if (remainderDays > 0) {
			int pricebeforecap = remainderDays * dailyRate;
			if (pricebeforecap > perWeekMax){
				pricebeforecap = perWeekMax;
			}
			charge += pricebeforecap;
}
}
	printf("Charge($): %d\n", charge);

	return EXIT_SUCCESS;
}
