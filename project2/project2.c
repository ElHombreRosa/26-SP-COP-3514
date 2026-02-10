// Class: COP3514.002S26

// Descprtion Of Code: Project 2, To create a code that reads characters using getchar() and to classified them by their ASCII value.
// As well to convert lower case to upper case and upper to lower while using a do while loop , with another loop within it.
// This will cont to loop until the character # is press , which will terminated the loop & our code will ignore \n when the user input Enter.

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int charc_input;
	
	do{
		// Ask user to type out characters and to exit with # 

		printf("Enter 1 or more characters then ENTER:\n");
		printf("(NOTE: a character # will exit the program):\n");
		
		// Read charcters until enter or # is pressed 
		while ((charc_input = getchar()) != '\n' && charc_input != '#'){
			// Let user know what they have type in and ASCII Value
			printf("\nYou typed: '%c' (ASCII %d)\n", charc_input, charc_input);

			// If it ASCII Value is between 65 to 90 its uppercase
			if(charc_input >= 65 && charc_input <= 90){
				printf("Class: Uppercase Letter\n");
				printf("Converted to: '%c'\n", charc_input + 32); // add 32 to make it lowercase
			}
			// If it ASCII Value is between 97 to 122 its lower case
			else if(charc_input >= 97 && charc_input <= 122){
				printf("Class: Lowercase Letter\n");
				printf("Converted to: '%c'\n", charc_input - 32); // subtract 32 to make it upper case
			}
			// If it ASCII Value is between 48 to 57 its a digit
			else if(charc_input >= 48 && charc_input <= 57){
				printf("Class: Digit\n");
				printf("No conversion done\n"); // no conversion
			}
			// If its ASCII Value betwenn 32 to 126 it is all printable characters 
			else if (charc_input >= 32 && charc_input <= 126){
				printf("Class: Printable Symbol\n");
				printf("No conversion done\n");
			}
			// If its ASCII value falls out of range of all previous statments which is less than  32 or greater/equal to  127 , NON-PRINTABLE
			else {
				printf("Class: Non-printable or extended ASCII\n");
				printf("No conversion done\n");
			} 
		}
		// add blank line before ask user again 
		if (charc_input != '#') {
			printf("\n");
		}


	} while (charc_input != '#'); // Keep looping till # is enter , ending loop 


	return EXIT_SUCCESS;
}
