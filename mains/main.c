#include "../includes/lem_in.h"

static int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->initialise = 1;
	m->pathing = (int*)ft_memalloc(sizeof(int) * 1000);
	m->edgetable = (int**)ft_memalloc(sizeof(int*) * m->r_no);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->r_no + 1));
	while (++i < m->r_no)
	{
		m->pathing[i] = -1;
		m->rooms[i] = NULL;
		m->edgetable[i] = (int*)ft_memalloc(sizeof(int) * m->r_no);
		j = -1;
		while (m->edgetable[i][++j])
			m->edgetable[i][j] = 0;
	}
	m->rooms[i] = NULL;
	m->pathing[0] = 0;
	return (m);
}

static void		read_map(t_map *m)
{
	char *line;

	while (get_next_line(m->fd, &line) > 0)
	{
		if (m->a_no == 0)
			ant_counter(m, line);
		else if (ft_strchr(line, '-') || m->begun == 3)
			links(m, line);
		else if ((m->begun == 1 || m->begun == 2) && !is_empty(line))
			rooms(m, line);
		else
			leaveandfree(m, 1);
	}
	if (!m->a_no || !m->e_list[0])
		leaveandfree(m, 1);
	m = map_init_2(m);
}

static t_map	*map_init(void)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->e_list = ft_strnew(1);
	m->a_list = ft_strnew(1);
	m->r_list = ft_strnew(1);
	m->r_no = 0;
	m->a_no = 0;
	m->begun = 0;
	m->room_index = 0;
	m->path_index = 0;
	m->initialise = 0;
	m->valid[0] = 0;
	m->valid[1] = 0;
	m->rooms = NULL;
	m->edgetable = NULL;
	m->pathing = NULL;
	m->fd = 0;
	return (m);
}

int				main(void)
{
	t_map *m;

	m = map_init();
	read_map(m);
	room_adding(m);
	if (!m->valid[0] || !m->valid[1])
		leaveandfree(m, 1);
	make_edge_table(m);
	print_matrix(m);
	if (algo(m, 0))
		result(m);
	else
		leaveandfree(m, 1);
	leaveandfree(m, 0);
}