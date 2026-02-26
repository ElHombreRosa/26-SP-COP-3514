#include <stdio.h>
#include <stdlib.h>

// This program combines two arrays recieved by the user into a third array,
// without duplicate elements from the this combination showing up in the third array. 

int find_elements(int *a, int n1, int *b, int n2, int *c){
 // Stored memory address  
    int *pa = a; // Pointer first array a
    int *pb = b; // Pointer second array b
    int *pc = c; // Pointer to move through third array , combination of first & second c
    
    int *end; // Pointer as stop boundary
    int duplicate; // alert (true or false) if a duplicate is found
    int totalcount = 0; // counts how many elements are stored
    
    end = a + n1; // end boundary at the last element of array a  
    while (pa < end){ // loop till last element of array a
        
        *pc = *pa; // element of a array copy to c array 
        pc++;
        pa++;
        totalcount++; // increase count of stored elements 
    }
    
    end = b + n2; // end boundary at the last element of array b
    while (pb < end){ // loop till last element of array b
        
        duplicate = 0;
        
        int *pcheck = c; // pointer use to check current elements put into c array 
        int *cend = c + totalcount; // end boundary for c array
        
        while (pcheck < cend){ // compare elements within c to b array 
            
            if (*pcheck == *pb){ // if element is the same 
                
                duplicate = 1; // mark as duplicate
                break;
            }
            pcheck++;
            
        }
        
        if (!duplicate){ // element was not found in c , add it 
            
            *pc = *pb; // copy element to array c 
            pc++;
            totalcount++;
        }
        
        pb++;
    }
     // return the # of unique elements 
    return totalcount;
}


int main(void){

    int n1, n2;
    // Ask user for size of first array
    printf("Enter length of the first array: ");
    scanf("%d", &n1);
    // Declare first array
    int a[n1];
    // User enters elements of first array
    printf("Enter elements in the first array: ");
    for(int i = 0; i <n1; i++)
    scanf("%d", &a[i]);
    
    // Ask user for size of second array
    printf("Enter length of the second array: ");
    scanf("%d", &n2);
    // Declare second array
    int b[n2];
     // User enters elements of second array
    printf("Enter elements in the second array: ");
    for(int i = 0; i <n2; i++)
    scanf("%d", &b[i]);    
    
    // c array (third array), carry the size of elements from first & second array 
    int c[n1+n2];
    
    // Calls find_elements for the final array 
    int new_array = find_elements(a, n1, b, n2, c);
    
    // Output, final array
    printf("Output: ");
    for(int i = 0; i < new_array; i++)
        printf("%d ", c[i]);
    
    
    
    return EXIT_SUCCESS;
}