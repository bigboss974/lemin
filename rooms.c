// #include "rooms.h"
#include "lemin.h"
/*
**================== get_rooms_name ===================
** Recupere le nom des salles dans un char* pour les linker
r_number indique quelle salle doit être traitée (1  ou 2)
* appel de la fonction de 2 fois (c1 & c2)
*/
char *get_rooms_name_for_link(char *line, int r_number)
{
    char *room;
    int room_length;
    room_length = 0;
    if (r_number == FIRST_ROOM)
        while (line[room_length] != '-' && line[room_length] != '\0')
            room_length++;
    else if (r_number == SECOND_ROOM)
    {
        line = strchr(line, '-') + 1; //+1 caractere de fin de chaine
        while (line[room_length] != '\0')
            room_length++;
    }
    room = strndup(line, room_length);
    return (room);
}

/*
**================== create_rooms_list ===================
** Recupere le nom des salles et les stockent dans lemin->l_rooms
 todo Bugs
 todo  si ##start ou ##end suivi d'un commentaire
*/
void create_rooms_list(t_lemin *lemin)
{
#ifdef VERBOSE
    printf("====== Enter get_rooms_list() ======\n");
#endif

    t_line *tmp_line = (t_line *)malloc(sizeof(t_line));
    char **roomstab = (char **)malloc(sizeof(char *));
    int flag=0;

    t_element *el = lemin->l_lines->first;
    while (el != NULL)
    {
        tmp_line = (t_line *)el->data;

        if (tmp_line->line && (my_get_line2(tmp_line->line) == ROOM\
                            || my_get_line2(tmp_line->line) == START\
                            || my_get_line2(tmp_line->line) == END))
        {
            flag = 0;
            int i = my_get_line2(tmp_line->line);
            if ( i == START ) flag = START;
            if ( i == END)   flag = END;
            if ( i == COMMENT)flag = COMMENT;
            
            if ( flag != 0 && el->next != NULL)
            { 
                el = el->next;
                tmp_line = (t_line *)el->data;
            }

            parse_room (tmp_line->line , roomstab);
            if (flag == START ) add_room(lemin->l_rooms, roomstab, START_ROOM);
            else if (flag == END) add_room(lemin->l_rooms, roomstab, END_ROOM);
            else if (flag == COMMENT) add_room(lemin->l_rooms, roomstab, NORMAL_ROOM);
                else add_room(lemin->l_rooms, roomstab, NORMAL_ROOM);
        }
        el = el->next;
    }
    lemin->room_nb = l_lenght(lemin->l_rooms);
#ifdef VERBOSE
    printf("Exit get_rooms_list ()\n\n");
#endif
}
