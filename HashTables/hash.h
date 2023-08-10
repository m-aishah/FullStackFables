#ifndef HASH_H
#define HASH_H

#include <stdio.h>

#define CAPACITY 10
/**
 * struct Employee - Data Structure of employees in FSF company.
 *
 * @first_name: The first name of the employee
 * @last_name: The last name of the employee
 * @salary: The employee's salary
 */

typedef struct Employee
{
    char *first_name;
    char *last_name;
    int salary;
} Employee;

/**
 * struct HashTable - Hash Table data structure
 *
 * @size: The size of the array.
 * @ArrayofEmployees: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaning collision handling.
 */
typedef struct HashTable
{
    unsigned long int size;
    Employee **ArrayOfEmployees;
} HashTable;

unsigned int hash(char *);
#endif