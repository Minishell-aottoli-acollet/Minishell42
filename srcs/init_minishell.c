# include "minishell.h"


static	void	forge_env(t_env *env, char **user_env)
{
	char 	**tmp;
	int		i;

	i = 0;
	while (env[i] != '\0')
		i++;
	env->env_count = i;





}

void	init_minishell(char **user_env)
{
	if (!msh = ft_calloc(sizeof(t_msh), 1))
		exit_error("Error initializing Minishell Struct\n", 2);
	if (!msh->env = ft_calloc(sizeof(t_env), 1))
		exit_error("Error initializing Env Struct\n", 2);
	forge_env(msh->env, user_env);
}