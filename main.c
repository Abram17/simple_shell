#include "main.h"

/**
 * main - entry point
 *
 * Description: my own simple shell
 *
 * @argc: arguments count
 * @argv: arguments passed
 *
 * Return: always 0 (success)
*/

int main(int argc, char **argv)
{
	int s = 0, n = 0;
	char *l = NULL;
	char **cmd = NULL;
	(void) argc;

	while (1)
	{
		l = readl();
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (s);
		}
		n++;
		cmd = tokenize(l);
		if (cmd == NULL)
			continue;
		if (isbuilt(cmd[0]) == 1)
			built(cmd, argv, &s, n);
		else
			s = _exec(cmd, argv, n);
	}
}
