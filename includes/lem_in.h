#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**rooms;		// array of room names
	char		*r_list;	// list of rooms that was passed at the beginning
	char		*a_list; //*ants_str;		// list of ants that was passed at the beginning
	char		*e_list; //*links;			// list of links that was passed at the beginning
	int			r_no; //q_rooms;		// quantity of rooms
	int			a_no; //ants;			// quantity of ants
	int			begun; //started;		// a part of validation
	int			room_index; //curr_room;		// an index of current room we're in
	int			path_index;			// last path index, current size of path
	int			*pathing;			// path
	int			**edgetable;			// edge table
	int			valid[2];		// a part of validation
	int			fd;		// a part of validation
	int			initialise;			// a part of validation
}				t_map;

void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m);
int				solution(t_map *m, int i);

char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			result(t_map *m);
void			print_matrix(t_map *m);
void			exit_func(t_map *m, int error);

#endif
