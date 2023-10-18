#include "header_file.h"

/**
 * string_length - Calculates the length of a string.
 * @s: The input string to determine the length of.
 *
 * Return: The integer length of the string.
 */
int string_len(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * string_compare - Performs lexicographic comparison between two strings.
 * @s1: The first string for comparison.
 * @s2: The second string for comparison.
 *
 * Return: A negative value if s1 < s2, a positive value if s1 > s2, or zero if s1 == s2.
 */
int string_cmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * needle_starts - checks if the needle starts with the haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of the next character of the haystack or NULL
 */
char *needle_starts(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return NULL;
	return (char *)haystack;
}

/**
 * concatenate_strings - Concatenates two strings.
 * @destination: The destination buffer.
 * @source: The source buffer to append.
 *
 * Return: A pointer to the destination buffer.
 */
char *string_conc(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return ret;
}