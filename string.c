#include "main.h"

/**
 * _strlen - length of a string
 * @s: the string whose length to check
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int n = 0;

	if (!s)
		return (0);

	while (*s++)
		n++;
	return (n);
}

/**
 * _strdup - duplicates a string
 *
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *s)
{
	int len = 0;
	char *temp;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	for (len++; len--;)
		temp[len] = *--s;
	return (temp);
}

/**
 * _strcmp - compares two strangs.
 *
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2
 *         positive if s1 > s2
 *         zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
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
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (temp);
}

/**
 * _strcpy - copies a string
 *
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}