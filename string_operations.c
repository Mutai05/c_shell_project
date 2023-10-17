#include "header_file.h"

/**
 * _strncpy - Copies a string up to a specified number of characters.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	char *s = dest;

	for (i = 0; i < n - 1 && src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return s;
}

/**
 * _strncat - Concatenates two strings up to a specified number of bytes.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to use for concatenation.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the first occurrence of 'c' in 's' or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return s;
	} while (*s++ != '\0');

	return NULL;
}