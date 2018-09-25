#include "../includes/lem_in.h"

void	count_ants(t_map *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	m->begun = 1;
	m->a_list = join_str(m->a_list, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((m->a_no = ft_atoi(s)) <= 0)
		exit_func(m, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			exit_func(m, 1);
	}
}
