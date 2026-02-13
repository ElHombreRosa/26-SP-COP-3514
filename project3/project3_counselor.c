// Name: Gabriel A Rosado Class: COP3514.002S26 
// Program takes the input of use of the total number of counselors
// read what counselors have been assigned to a postion and outputs which one hasn't been assigned yet.

#include <stdio.h>
#include <stdlib.h>


int search(int counselors[], int n){
    
    int total_counselors = n * (n + 1) / 2; // gives the sum of n(n+1)/2 if no counselors is missing
    int assigned_counselors = 0;
    
    for(int i = 0; i < n - 1; i++){ // loops through the array for each assigned counselors (size n - 1) "assigned all counselors expect one"
        assigned_counselors += counselors[i]; // each counselor input is assigned to assigned_counselors
    }
    
    return total_counselors - assigned_counselors; // gives the missing counselors number 
}


int main(void){
    
    int n;
    // take the total of counselors
    printf("Enter number of counselors: ");
    scanf("%d", &n);
    
    int counselors[n-1]; // array to store assigned counselors
    
    printf("Enter counselors assigned: ");
    // read each assigned counselors in array 
    for(int i = 0; i < n - 1; i++){
        scanf("%d", &counselors[i]);
    }
    
    int non_assigned = search(counselors, n); // call search function 
    
    printf("Counselor has not been assigned: %d", non_assigned);
    
    return EXIT_SUCCESS;
}