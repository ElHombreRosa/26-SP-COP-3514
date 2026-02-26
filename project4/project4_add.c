#include <stdio.h>
#include <stdlib.h>

void compute(int *a1, int n1, int *a2, int n2){

    int *beginning = a1; // pointer for first element in array a1
    int *end = a1 + n1 - 1; // pointer for last element in array a1
    int *out = a2; // pointer to fill array a2 
    
    while (beginning < end){
        
        *out = *beginning + *end; // first & last element added and put into a2
        beginning++; // start pointer goes foward (left to right)
        end--; // end pointer goes backward in the array (right to left)
        out++; // out pointer move to next postion in the a2 array.
    }
    
    if (beginning == end){ //if array is odd amount, copy middle element
        
        *out = *beginning; // copy middle element to output a2
    }
    
}



int main(void){
    
    int n1, n2;  // lenght of input and output of array
    
    printf("Enter the length of the array: "); // ask user for lenght of array 
    scanf("%d", &n1);
    
    int a1[n1];
    
    printf("Enter the elements of the array: "); // ask user to enter elements of array
    for (int i = 0; i < n1; i++)
        scanf("%d", &a1[i]);
        
    if (n1 % 2 == 0)
        n2 =  n1 / 2; // if the array is an even amount
    else
        n2 = n1 / 2 + 1; // if the array is an odd ammount
      
    int a2[n2];
    
    compute(a1, n1, a2, n2);
    
    printf("Output: ");
    for(int i = 0; i < n2; i++)
        printf("%d ", a2[i]);
    
    return EXIT_SUCCESS;
}