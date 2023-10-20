#include "main.h"

/**
 * readl - reads an input line
 *
 * Return: line
*/

char *readl(void)
{
	size_t len = 0;
	int i;
	char *l = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	i = getline(&l, &len, stdin);
	if (i == -1)
	{
		free(l);
		return (NULL);
	}
	return (l);
}

/**
 * _getenv - find the env var for cmd
 *
 * @cmd: input cmd
 *
 * Return: env var of cmd
*/

char *_getenv(char *cmd)
{
	int i;
	char *temp, *key, *val, *ret;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, cmd) == 0)
		{
			val = strtok(NULL, "\n");
			ret = _strdup(val);
			free(temp);

			return (ret);
		}
		free(temp);
		temp = NULL;
	}

	return (NULL);
}

/**
 * _path - handles path
 *
 * @cmd: input command
 *
 * Return: path
*/

char *_path(char *cmd)
{
	int i;
	char *env, *full, *k;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			else
				return (NULL);
		}
	}
	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);
	k = strtok(env, ":");
	while (k)
	{
		full = malloc(_strlen(k) + _strlen(cmd) + 2);
		if (full != NULL)
		{
			_strcpy(full, k);
			_strcat(full, "/");
			_strcat(full, cmd);
			if (stat(full, &st) == 0)
			{
				free(env);
				return (full);
			}
			else
			{
				free(full);
				k = strtok(NULL, ":");
			}
		}
	}
	free(env);
	return (NULL);
}
