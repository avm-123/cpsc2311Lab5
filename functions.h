/*************************
*Aidan Militzer
*CPSC 2310 Spring 24
*amilitz
*Instructor: Dr. Yvon Feaster
*************************/
#include <stdio.h>
#include <stdlib.h>


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/* Struct Birthday is implemented through Struct student.
 * day, month, and year will all be initalized through student structure.
 * student.birthday.day is an example 
 * 
*/
typedef struct Birthday {
    int day;
    int month;
    int year;
    char monthName[12];
} Birthday;


/* Struct student contains all the private information that each node has stored
 * This information will be printed to output file if successfully stored as node from input file
 * 
*/
typedef struct student
{
    char firstName[50], lastName[50], major[10], classStand[15];
    Birthday birthday;
}student;

/* Struct node is used to create the linked list
 * Student struct is created in struct node because node will be accessing and storing student
 * 
*/
typedef struct Node {
    student data;
    struct Node* next;
} node_t;

/* Parameters:  FILE points to input file, and
 * node_t = head of the list 
 * 
 * Returns: a pointer to the list
 * This function reads in a file that iterates through file
 * and adds data to linked list
*/
    node_t* createList(FILE*, node_t**);

/* Parameters: node is the pointer to the node being added,
 * head is first node of the list
 *
 * Return: none
 * This function adds a node to the linked list 
*/
    void add(node_t** node,node_t** head);

/* Parameters: input is the input file that data is being 
 * retrieved from
 * 
 * Return: a node that contains data from FILE input
 * This function Allocates memory for a node that will be
 * stored in the linked list, so it can store info from a file
*/
    node_t* readNodeInfo(FILE* input);

/* Parameters: FILE* points to input file, node_t* points to a node
 *
 * Return: none
 * This function prints out data from the linked list
 * 
*/
    void printList(FILE*, node_t*);

/* Parameter: FILE* points to the file that the boarder will be printed to. 
 * 
 * Return: none
 * This function prints out the border bewtween node data in the output file
*/
    void printBorder(FILE*);
/* Parameter node_t** points to a node within the linked list
 * 
 * Return: none
 * This function deletes nodes created in linked list, freeing memory previously allocated
*/
    void deleteList(node_t** );

#endif
