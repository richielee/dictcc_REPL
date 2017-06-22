#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char*	command;
	int		len;
	char*	word;

	while (1)
	{
		printf("dict.cc >>");
		if (fgets(word, 100, stdin) == NULL)
			break;
		if (word)
		{
			printf("\n");
			len = strlen(word);
			if (!(command = (char*)malloc(sizeof(char) * (len + 22))))
				return (1);
			strcpy(command, "(dictcc de en ");
			strcat(command, word);
			strcat(command, ") | head");
			system(command);
			free(command);
			printf("\n");
		}
	}
	printf("\nThanks for using dict.cc REPL.\n");
	printf("REPL wrapper written by Richie Li.\n");
	return (0);
}
