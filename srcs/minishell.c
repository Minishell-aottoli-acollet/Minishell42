# include "minishell.h"

t_minish msh;

/*	
	el input podria ir directamente en la struct
	tipo-> msh.inputs.input = readline...
	O como gemartin hacemos una char* readline temporal
	para n escribir "msh.inputs.input" cada vez

	hay q cambiar el nombre de la estructura inputs entonces
	por input
*/
static void minishell_loop(void)
{

	while (1)
	{
		msh.input = readline("minishell> ");
		if (!msh.input)
			exit_error("Input error\n", 2);
		if (!ft_strcmp(msh.input, "exit"))
			return ;
		if ((check_only_spaces(msh.input) == -1 || msh.input[0] == '\0'))
			free(msh.input);
		else
		{
			add_history(msh.input);
			if (tokenize(msh, &msh->input, msh.input) && msh.flags->quote != 0)
		}	
	}
}

int	main(int as, char **av, char **env)
{
	(void)av;
	(void)env;

	if (1 != as)
		return (2); //hacer mensaje de error o constante
	msh = init_minishell(env);
	print_msg();
	minishell_loop();
	return (0);
}
