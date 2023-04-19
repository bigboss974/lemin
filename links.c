// #include "links.h"
#include "lemin.h"

void add_link (t_lemin *lemin, int id_room1, int id_room2 )
{
    t_link *lnk = (t_link *) malloc(sizeof(t_link));
    if (lnk == NULL)
    {
        printf("add_link () : Memory error\n");
        exit(EXIT_FAILURE);
    }
    lnk->id_room1 = id_room1;
    lnk->id_room2 = id_room2;
    l_push_back(lemin->l_links, (void *)lnk, sizeof(t_link));
    free (lnk);
}

/*
    get_room_id
*/
int get_room_id (t_list *rooms, char *line)
{
   t_room *tmp = (t_room *)malloc(sizeof(t_room));
    if (rooms == NULL || tmp == NULL)
    {
        printf("get_room_id () : Memory error\n");
        exit(EXIT_FAILURE);
    }

    t_element *element = rooms->first;
    while (element != NULL)
    {
        tmp = (t_room *)element->data;

        if (strcmp(line, tmp->name) == 0)
        {
            return (tmp->id); //
        }
        element = element->next;
    } 
    printf ("get_room_id (): Room [%s] doesn't exist.\n", line);
    exit(EXIT_FAILURE);
}
/*
**================== create_link ===================
*/
void create_link(t_lemin *lemin)
{
#ifdef VERBOSE
    printf("Enter create_link ()\n");
#endif
    int i;
    t_line *tmp = (t_line *)malloc(sizeof(t_line));

    if (lemin->l_links == NULL || tmp == NULL)
    {
        printf("create_link () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = lemin->l_lines->first;
    while (element !=NULL)
    {
        tmp = (t_line *)element->data;
        if (tmp->line != NULL && my_get_line2(tmp->line) == LINK)
        {  
            i = -1;
            while (tmp->line && tmp->line[++i] != '-');
            tmp->line[i] = '\0';
            int rid1 = get_room_id(lemin->l_rooms, tmp->line);
            int rid2 = get_room_id (lemin->l_rooms, tmp->line + i + 1 );
            
            if ( rid1 != rid2) add_link(lemin, rid1, rid2);
                else 
                {
                    printf ("crate_link () : Error room [%d] = room[%d]\n", rid1, rid2);
                    exit (EXIT_FAILURE);
                }
            tmp->line[i] = '-';

        }
        element = element->next;
    }
   free (element);

#ifdef VERBOSE
        printf("Exit create_link ()\n");
#endif
}
