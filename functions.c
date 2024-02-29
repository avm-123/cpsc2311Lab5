/*************************
*Aidan Militzer
*CPSC 2310 Spring 24
*amilitz
*Instructor: Dr. Yvon Feaster
*************************/
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

// Define the month names
//const char* MONTH_NAMES[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Function to create a linked list from data in a file
node_t* createList(FILE* fp, node_t** head)
{
    node_t* newNode;
    while (!feof(fp)) {
// Read node information from the file
        newNode = readNodeInfo(fp);
// Add the newly created node to the list
        add(&newNode, head);
    }

    return *head;
}
// Function to add a node to the end of the linked list
void add(node_t** node,node_t** head)
{
// Check if the node is NULL
     if (*node == NULL) {
        return; 
    }
// Check if the list is empty
    if (*head == NULL)
    {
// If the list is empty, set the head to the new node
        *head = *node;
//Set the next pointer of the new node to NULL
        (*node)->next = NULL;
    }
    else
    {
// If the list is not empty, find the last node and append the new node
        node_t* temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = *node;
        (*node)->next = NULL;
    }
   
}
// Function to read node information from a file
node_t* readNodeInfo(FILE* input)
{
// Allocate memory for the new node
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
// Read node data from the file
    int result = fscanf(input, "%49[^,],%49[^,],%d,%d,%d,%9[^,],%14[^\n]%*c", 
                        newNode->data.lastName, newNode->data.firstName,
                        &newNode->data.birthday.month, &newNode->data.birthday.day, &newNode->data.birthday.year,
                        newNode->data.major, newNode->data.classStand);
// Check if all data fields were successfully read
    if (result != 7) { 
        fprintf(stderr, "Error reading data from file\n");
        free(newNode);
        return NULL;
    }
    

    return newNode;
}
// Function to print the linked list to a file
void printList(FILE* output, node_t* head)
{
    // Print border before printing the list
    printBorder(output);
    
    // Print a new line and the list header
    fprintf(output, "\nList Info:");
    
    // Iterate through the list
    while (head != NULL) {
        fprintf(output, "\n");
        fprintf(output, "Name:\t%s ", head->data.firstName);
        fprintf(output, "%s\n", head->data.lastName);
        fprintf(output, "Date of Birth:\t%d %d, %d\n", head->data.birthday.month,
        head->data.birthday.day, head->data.birthday.year);
        fprintf(output, "Major:\t%s\n", head->data.major);
        fprintf(output, "Year:\t%s\n", head->data.classStand);
        
        
        
        // Move to the next node
        head = head->next;
    }
    
    // Print border after printing the list
    printBorder(output);
}
// Function to delete the linked list and free memory
void deleteList(node_t** head) {
    node_t* current = *head;
    node_t* next;
// Loop through each node and free memory
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// Function to print a border to the output file
void printBorder(FILE* output) {
    fprintf(output, "********************************************************************************");
}
