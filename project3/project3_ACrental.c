// Name: Gabriel A Rosado Class: COP3514.002S26

// The program calc the rental cost of an AC unit based on it type and --
// number for days its purchase for. We put the price info in an arrays
// These arrays are taken to charge firstday cost , daily rate and put
// a weekly cost cap to get the total cost for that AC unit.


#include <stdio.h>
#include <stdlib.h>

int main(void){

	int selection;
	int days;
	int charge = 0;
	// Arrays added to store the price for each type of AC
	int firstDay[4] = {50, 30, 80, 200};
	int dailyRate[4] = {60, 35, 50, 120};
	int perWeekMax[4] = {160, 200, 280, 550};
	
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
// Take user input of AC type selected and make it start at range 0 for array index
 int ac_index = selection - 1;

    if (days == 0){ // no charge if no amount of days selected
        charge = 0;
    }
    else if (days < 7){  // 1 to 7 day charge //
        charge = firstDay[ac_index] + (days - 1) * dailyRate[ac_index]; // first day + remaining days before week cap 

        if (charge > perWeekMax[ac_index]){ //if charge is more than per week max cost within the 7 days put the cap //
            charge = perWeekMax[ac_index];
        }
    }
    else { // if days over 7 days charge per weekmax each week plus remanding days //
        charge = (days / 7) * perWeekMax[ac_index];

        int remainderDays = days % 7;

        if (remainderDays > 0){
            int priceBeforeCap = firstDay[ac_index] + (remainderDays - 1) * dailyRate[ac_index]; // cost of remainder days 

            if (priceBeforeCap > perWeekMax[ac_index]){
                priceBeforeCap = perWeekMax[ac_index];
            }

            charge += priceBeforeCap; // Add remainder cost to total 
        }
    }
	printf("Charge($): %d\n", charge);

	return EXIT_SUCCESS;
}
