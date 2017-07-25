#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KYEL "\x1B[33m"

void	print_arrow(void)
{
	printf(KRED "»");
	printf(KNRM " ");
}

int		main(void)
{
	char*	command;
	int		len;
	char	word[100];
	char	input[4];
	char	output[4];

	printf("Welcome to dict.cc REPL.\nPlease input the source language.\n");
	print_arrow();
	if (fgets(input, 4, stdin) == NULL)
			return (0);
	input[2] = '\0';
	printf(KNRM "Please input the target language.\n");
	print_arrow();
	if (fgets(output, 4, stdin) == NULL)
			return (0);
	output[2] = '\0';
	while (1)
	{
		printf(KYEL "dict.cc ");
		print_arrow();
		if (fgets(word, 100, stdin) == NULL)
			break;
		if (word)
		{
			printf("\n");
			len = strlen(word);
			if (!(command = (char*)malloc(sizeof(char) * (len + 22))))
				return (1);
			strcpy(command, "(dictcc ");
			strcat(command, input);
			strcat(command, " ");
			strcat(command, output);
			strcat(command, " ");
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
