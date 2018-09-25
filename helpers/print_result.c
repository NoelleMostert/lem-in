#include "../includes/lem_in.h"

static void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	print_result(t_map *m, int n)
{
	int ants;

	if (n == (m->path_index + m->a_no + 1))
		return ;
	ants = m->a_no + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= m->path_index)
			print_ant(ants, m->rooms[m->pathing[n - ants]]);
	}
	ft_putchar('\n');
	print_result(m, ++n);
}

void		result(t_map *m)
{
	int i;

	i = -1;
	ft_putendl(m->a_list);
	ft_putendl(m->r_list);
	ft_putendl(m->e_list);
	ft_putchar('\n');
	while (++i <= m->path_index)
	{
		ft_putchar('[');
		ft_putnbr(m->pathing[i]);
		ft_putchar(']');
		if (i != m->path_index)
			ft_putchar('-');
	}
	ft_putstr("\n\n");
	print_result(m, 2);
}
