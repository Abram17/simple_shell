#include "main.h"

/**
 * isbuilt - checks for builtin commands
 *
 * @cmd: input command
 *
 * Return: 1 if builtin
 *         0 if not
*/

int isbuilt(char *cmd)
{
	int i;
	char *built[] = {
		"exit", "env", "setenv", "cd", NULL
	};

	for (i = 0; built[i]; i++)
	{
		if (_strcmp(cmd, built[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * built - handles builtin commands
 *
 * @cmd: command
 * @argv: arguments
 * @s: status
 * @n: command number
 *
 * Return: void
*/

void built(char **cmd, char **argv, int *s, int n)
{
	if (_strcmp(cmd[0], "exit") == 0)
		_exitshell(cmd, argv, s, n);
	if (_strcmp(cmd[0], "env") == 0)
		_penv(cmd, s);
}

/**
 * is_positive - checks if string is positive int
 *
 * @s: input string
 *
 * Return: 1 if true
 *         0 if false
*/

int is_positive(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * conv - convert a string to an integer.
 *
 * @s: input string
 *
 * Return: num * sign
 */

int conv(char *s)
{
	int num = 0, i;

	for (i = 0; s[i]; i++)
	{
		num *= 10;
		num += (s[i] - '0');
	}

	return (num);
}
