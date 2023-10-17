#include "header_file.h"

/**
 * bfree - Frees a pointer and sets it to NULL
 * @ptr: A pointer to a memory address
 *
 * This function frees the memory pointed to by 'ptr' and sets 'ptr' to NULL.
 * It is a safe way to release dynamically allocated memory.
 *
 * @ptr: A pointer to a memory address.
 *
 * Return: 1 if memory was freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return 1;
	}
	return 0;
}