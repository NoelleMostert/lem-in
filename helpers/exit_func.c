#include "../includes/lem_in.h"

void	exit_func(t_map *m, int error)
{
	int i;

	free(m->e_list);
	free(m->a_list);
	free(m->r_list);
	if (m->initialise)
	{
		free(m->pathing);
		free_array(m->rooms, m, 0);
		i = -1;
		while (++i < m->r_no)
			free(m->edgetable[i]);
		free(m->edgetable);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
