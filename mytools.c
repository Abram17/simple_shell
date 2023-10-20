#include "main.h"

/**
 * tokenize - tokenize input
 *
 * @l: input command
 *
 * Return: tokenized cmd
*/

char **tokenize(char *l)
{
	char *del = " \t\n", *token, *temp;
	char **cmd;
	int len = 0, i = 0;

	if (l == NULL)
		return (NULL);
	temp = _strdup(l);
	token = strtok(temp, del);
	if (token == NULL)
	{
		free(l);
		free(temp);
		return (NULL);
	}
	while (token)
	{
		token = strtok(NULL, del);
		len++;
	}
	free(temp);
	cmd = malloc(sizeof(char *) * (len + 1));
	if (cmd == NULL)
	{
		free(l);
		return (NULL);
	}
	token = strtok(l, del);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, del);
		i++;
	}
	cmd[i] = NULL;
	free(l);

	return (cmd);
}

/**
 * _exec - excutes a cmd
 *
 * @cmd: input cmd
 * @argv: arguments passed
 * @n: number of command
 *
 * Return: status
*/

int _exec(char **cmd, char **argv, int n)
{
	int s;
	pid_t p;
	char *full;

	full = _path(cmd[0]);
	if (full == NULL)
	{
		_error(argv[0], cmd[0], n);
		freea(cmd);
		return (127);
	}

	p = fork();
	if (p == 0)
	{
		if (execve(full, cmd, environ) == -1)
		{
			free(full);
			full = NULL;
			freea(cmd);
		}
	}
	else
	{
		waitpid(p, &s, 0);
		freea(cmd);
		free(full);
		full = NULL;
	}

	return (WEXITSTATUS(s));
}

/**
 * freea - frees an array
 *
 * @a: array to free
 *
 * Return: void
*/

void freea(char **a)
{
	int i;

	if (a == NULL)
		return;
	for (i = 0; a[i]; i++)
		free(a[i]);
	free(a);
}

/**
 * _error - handles errors
 *
 * @sh: shell name
 * @cmd: command
 * @n: number of cmd
 *
 * Return: void
*/

void _error(char *sh, char *cmd, int n)
{
	char *idx;
	char msg[] = ": not found\n";

	idx = _atoi(n);
	write(STDERR_FILENO, sh, _strlen(sh));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(idx);
}

/**
 * _atoi - converts number to string
 *
 * @n: input number
 *
 * Return: string
*/

char *_atoi(int n)
{
	int i = 0;
	char b[20];

	if (n == 0)
		b[i++] = '0';

	else
	{
		while (n > 0)
		{
			b[i] = (n % 10) + '0';
			n /= 10;
			i++;
		}
	}

	b[i] = '\0';
	rev_string(b);

	return (_strdup(b));
}
