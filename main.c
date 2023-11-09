#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(Cshell) $ ";
	char *lineptr;
	size_t n = 0;

	/* variable declaration */
	(void)ac;
	(void)argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
