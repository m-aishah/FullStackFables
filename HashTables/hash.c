#include "hash.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash: randomly generate the index for a given first name.
 *
 * @first_name - pointer to the first name of the employee
 *
 * Return - randomly generated index,
 * corresponding to where employee details will be stored.
 */
unsigned int hash(char *first_name)
{
    unsigned int index, i;
    if (first_name == NULL || strlen(first_name) == 0)
    {
        fprintf(stderr, "hash(): Invalid first_name!");
        return (CAPACITY + 1);
    }

    for (i = 0; first_name[i]; i++)
    {
        index += i;
    }

    index % CAPACITY;
    return (index);
}

/**
 * create_hash_table: Create a hash table
 *
 * @size - size of the hash table
 * Return: pointer to the hash table
 */

HashTable *create_hash_table(unsigned int size)
{
    int i;
    /*Check that the size is valid i.e greater than 0*/
    if (size <= 0)
    {
        fprintf(stderr, "create_hash_table(): Invalid size");
        return (NULL);
    }

    /*Allocate memory for  hash table*/
    HashTable *hashTable = malloc(sizeof(HashTable));
    if (hashTable == NULL) /*If memory allocation fails*/
        return (NULL);

    hashTable->size = size;

    hashTable->ArrayOfEmployees = calloc(size, sizeof(Employee *));
    if (hashTable->ArrayOfEmployees == NULL) /*If memory allocation fails*/
        return (NULL);

    /*Initialize the ArrayOfEmployees to NULL*/
    for (i = 0; i < size; i++)
    {
        hashTable->ArrayOfEmployees[i] = NULL;
    }
    return (hashTable);
}

Employee *create_employee(char *first_name, char *last_name, int salary)
{
    Employee *employee = malloc(sizeof(Employee));
    if (employee == NULL)
        return (NULL);

    employee->first_name = malloc(sizeof(first_name));
    if (employee->first_name == NULL)
        return (NULL);
    employee->first_name = first_name;

    employee->last_name = malloc(sizeof(last_name));
    if (employee->last_name == NULL)
        return (NULL);
    employee->last_name = last_name;

    employee->salary = salary;

    return (employee);
}

void free_employee(Employee *employee)
{
    free(employee->first_name);
    free(employee->last_name);
    free(employee);
}

void free_hash_table(HashTable *table)
{
    int i;

    for (i = 0; i < table->size; i++)
    {
        Employee *employee = table->ArrayOfEmployees[i];
        if (employee != NULL)
        {
            free_employee(employee);
        }
    }
    free(table->ArrayOfEmployees);
    free(table);
}

int main(void)
{
    Employee *Employee1;
    HashTable *table;

    Employee1 = create_employee("Aishah", "Mabayoje", 17000000);
    printf("%s", Employee1->first_name);
    table = create_hash_table(CAPACITY);
    free_hash_table(table);
}
