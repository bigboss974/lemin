#include "lemin.h"



void clear_all(t_lemin *lemin)
{
    l_clear(lemin->l_lines);
    l_clear(lemin->l_links);
    l_clear(lemin->l_rooms);
    free(lemin->l_lines);
    free (lemin->l_links);
    free(lemin->l_rooms);
    free(lemin);
}

void init_lemin(t_lemin *lemin)
{
    t_list *l_links = (t_list *)malloc(sizeof(t_list)); // tunnels
    t_list *l_rooms = (t_list *)malloc(sizeof(t_list)); // rooms
    t_list *l_lines = (t_list *)malloc(sizeof(t_list)); // flux de données STDIN

    if (l_lines == NULL || l_links == NULL || l_rooms == NULL)
    {
        printf("init_lemin () : Error malloc.\n");
        exit(EXIT_FAILURE);
    }

    l_init(l_links);
    l_init(l_rooms);
    l_init(l_lines);

    lemin->flags = NORMAL_ROOM;
    lemin->room_nb = 0;
    lemin->l_lines = l_lines;
    lemin->l_links = l_links;
    lemin->l_rooms = l_rooms;
    lemin->ant_nb = 0;
}