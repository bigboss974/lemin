#include "lemin.h"

/*
**================== add_room ===================
room pointeur sur la iste de room
room_info donnees initialisation de la room
 */
void add_room(t_list *rooms, char **room_infos, t_room_type type)
{
#ifdef VERBOSE
    printf("Enter add_rooms ()\n");
#endif
    int x, y;
    t_room *tr = (t_room *)malloc(sizeof(t_room));

    if (tr == NULL)
    {
        printf("add_room () : Memory error\n");
        exit(EXIT_FAILURE);
    }

    if ((is_valid_number(room_infos[1])) && (is_valid_number(room_infos[2])))
    {
        x = str_to_int(room_infos[1]);
        y = str_to_int(room_infos[2]);

        if ((x != -1) && (y != -1))
        {

            tr->name = strdup(room_infos[0]);
            tr->type = type;
            tr->x = x;
            tr->y = y;
            tr->empty = 0;
            tr->id = l_lenght(rooms);
            l_push_back(rooms, (void *)tr, sizeof(t_room));
        }
    }
    else
    {
        printf("add_room : Numbers erreur. Not valid\n");
        exit(EXIT_FAILURE);
    }
    free(tr);
#ifdef VERBOSE
    printf("Sortie add_rooms ()\n");
#endif
}