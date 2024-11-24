# include "minishell.h"

void	exit_error(char *error_message, int n_error)
{
	printf("%s", error_message);
	exit(n_error);
}