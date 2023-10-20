#include "main.h"

/**
 * _exitshell - exits the shell
 *
 * @cmd: command
 * @argv: arguments
 * @s: status
 * @n: command number
 *
 * Return: void
*/

void _exitshell(char **cmd, char **argv, int *s, int n)
{
	int val = *s;
	char *idx;
	char msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive(cmd[1]))
		{
			val = conv(cmd[1]);
		}
		else
		{
			idx = _atoi(n);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			freea(cmd);
			*s = 2;

			return;
		}
	}

	freea(cmd);
	exit(val);
}

/**
 * _penv - prints env var for cmd
 *
 * @cmd: command
 * @s: status
 *
 * Return: void
*/

void _penv(char **cmd, int *s)
{
	int i, len;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	freea(cmd);
	*s = 0;
}

