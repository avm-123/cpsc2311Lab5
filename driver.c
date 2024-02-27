/*************************
*Aidan Militzer
*CPSC 2310 Spring 24
*amilitz
*Instructor: Dr. Yvon Feaster
*************************/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char* argv[])
{
    //Program will expect command line arguments 1 ans 2 for input and output files
    //fp reads file 
    FILE* fp = fopen(argv[1], "r");
    //output writes to file 
    FILE* output = fopen(argv[2], "w");
    
    //initialize the linked list
    node_t* head = NULL;
    createList(fp, &head);

    // Print the list
    printList(output, head); 

   

    // Delete the list to free memory
    deleteList(&head);

    fclose(fp);
    fclose(output);
    return 0;
}
