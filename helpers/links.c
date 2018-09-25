#include "../includes/lem_in.h"

void	links(t_map *m, char *line)
{
	if (m->begun == 2)
		m->begun = 3;
	if (m->begun != 3)
		exit_func(m, 1);
	m->e_list = join_str(m->e_list, line, 0);
}
