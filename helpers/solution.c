#include "../includes/lem_in.h"

static int	is_last_room(t_map *m, int i)
{
	if (m->edgetable[i][m->r_no - 1])
	{
		m->pathing[++(m->path_index)] = i;
		m->pathing[++(m->path_index)] = m->r_no - 1;
		return (1);
	}
	return (0);
}

static void	erase_element(t_map *m, int i, int path)
{
	m->edgetable[m->room_index][i] = 0;
	m->edgetable[i][m->room_index] = 0;
	if (path)
	{
		m->pathing[m->path_index] = -1;
		m->path_index--;
	}
}

static int	find_door(t_map *m, int r_index, int d_index)
{
	while (d_index < m->r_no)
	{
		if (m->edgetable[r_index][++d_index] == 1)
			return (d_index);
	}
	return (0);
}

static int	is_in_path(t_map *m, int r_index)
{
	int i;

	i = -1;
	while (m->pathing[++i] != -1)
	{
		if (m->pathing[i] == r_index)
			return (1);
	}
	return (0);
}

int			solution(t_map *m, int i)
{
	if (m->edgetable[0][m->r_no - 1])
	{
		m->pathing[++(m->path_index)] = m->r_no - 1;
		return (1);
	}
	while ((i = find_door(m, m->room_index, i)))
	{
		if (is_last_room(m, i))
			return (1);
		else if (is_in_path(m, i))
			erase_element(m, i, 0);
	}
	if ((m->room_index = find_door(m, m->room_index, 0)) == 0)
	{
		if (m->path_index == 0 || m->room_index == 0)
			return (0);
		m->room_index = m->pathing[m->path_index - 1];
		erase_element(m, m->pathing[m->path_index], 1);
		if (solution(m, 0))
			return (1);
	}
	m->pathing[++(m->path_index)] = m->room_index;
	if (solution(m, 0))
		return (1);
	return (0);
}
