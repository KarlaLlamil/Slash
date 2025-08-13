#ifndef	AST_H
# define AST_H

# include <stdbool.h>
# include "Libft/libft.h"

typedef enum	e_node_type
{
	COMMAND,
	PIPE,
	AND,
	OR,
	PARENTHESES,
	ASSIGNMENT
}	t_node_type;

typedef enum	e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
}	t_redir_type;


// Despues de algunas conversasiones con Chatgpt, me dijo que es mejor que todas las redirecciones esten pegadas al comando
// en una lista para luego solo recorrer la lista y aplicar las redirecciones antes de hacer excve al comando
typedef struct	s_command
{
	char	**arguments;
	t_list	*redirs; // lista de t_redir or t_heredoc
}	t_command;

typedef struct	s_heredoc
{
	char	*delimiter;
	bool	expand_vars;
	char	*tmp_file;

}	t_heredoc;

typedef struct s_redir
{
	t_redir_type	type;
	char		*file;
}	t_redir;

typedef struct s_assignment
{
	char	*name;
	char	*value;
	bool	export_env;
}	t_assignment;

// Como, PIPE, OR y AND, solo necesitan tener a los hijos, no requieren mas datos (data = NULL)
// En el caso de PARENTHESES solo tendria un nodo hijo (right = NULL, data = NULL)
//que seria la raiz de un subarbol que representa la lista
typedef struct s_ast_node
{
	t_node_type			type;
	void				*data;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

#endif