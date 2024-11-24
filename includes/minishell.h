#ifndef MINISHELL_H
#define MINISHELL_H

//LIBRARIES
# include "libft/libft.h"
# include "colors.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

//STRUCTS

/*

	Esta struct guarda las variables de entorno
	del sistema.
	Path: es la variable que indica a los sistemas 
	operativos donde buscar los ejecutables cuando
	se invoca a un comando sin especificar su ruta completa
	(ej: nvim, vim, neofetch);
	Todo ello por tanto queda recogido en una ruta(char *);

*/

typedef struct s_env
{
	char	**env;
	char	*path;
	int		env_count;
}	t_env;

/* 
	lista enlazada para representar los
	comandos de shell
	Con esto conseguimos poder ejecutar los comandos
	de forma secuencial o en paral.lelo.

	struct es precisamente para hacer nodos de 
	estructuras.
*/

typedef struct s_inputs
{
	struct s_inputs *next;
	t_env	*env;
	t_flags	*flags;
	t_pipes	*pipes;
	char	*input;
	char	**input_arg;
	int		idx_arg;

}	t_inputs;

typedef struct	s_minishell
{
	t_input	*inputs;
	char	*input;
	
}   t_minish;
extern t_minish	msh;

/*Functions*/
void        print_msg(void);
int			check_only_spaces(char *str);
t_token		*tokenize(void);
void		*safe_malloc(size_t size);
void        free_minishell(char* input);
void		exit_error(char *error_message, int n_error);
#endif
