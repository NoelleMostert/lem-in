#include "../includes/lem_in.h"

static void	is_number(char **r, t_map *m, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, m, 1);
		}
	}
	else
		free_array(r, m, 1);
}

static void	validate_room(t_map *m, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, m, 1);
	is_number(r, m, r[1]);
	is_number(r, m, r[2]);
	free_array(r, m, 0);
}

void		rooms(t_map *m, char *line)
{
	m->begun = 2;
	m->r_list = join_str(m->r_list, line, 0);
	if (line[0] == '#')
		return ;
	validate_room(m, line);
	m->r_no++;
}