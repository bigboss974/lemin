#include "lemin.h"

/*
**================= my_get_line ========================
*/
void my_get_line(t_lemin *lemin)
{
    #ifdef VERBOSE
        printf ("===== Enter my_get_line () =====\n");
    #endif

    t_line *ptr = (t_line *)malloc(sizeof(t_line));

    if (ptr == NULL)
    {
        printf("my_get_line () : malloc () error.\n");
        exit(EXIT_FAILURE);
    }

    t_element *element = lemin->l_lines->first;
    while (element != NULL)
    {
        ptr = (t_line *)element->data;
        
        #ifdef VERBOSE
            printf ("\nmy_get_line () Data = %s\n",ptr->line);
        #endif

        t_line_type type = get_line_type(ptr->line);
        if (type == START)
        {
            printf ("Type {%d} : %s\n", type, ptr->line);
        }
        else if (type == END)
        {
            element = element->next;
            //is_room(ptr->line, l_rooms, END_ROOM);  
            //is_room(ptr->line, lemin->l_rooms, END_ROOM);  
        }
        else if (type == COMMENT)
            printf("[%d] : Comment line : %s\n", type, ptr->line);
        
        else if (type == ANTS)
            printf("[%d] : Nombre de fourmis : %s\n", type, ptr->line);
        
        else if (type == LINK)
        {
            t_link *lnk = (t_link *)malloc (sizeof (t_link));

            //lnk = create_link(ptr->line, l_rooms);
            create_link(lemin);
            //l_push_back(l_link, (void *)lnk, sizeof (t_link));
            l_push_back(lemin->l_links, (void *)lnk, sizeof (t_link));
            
            #ifdef VERBOSE
                //l_view_link(lemin->l_links);
            #endif
        }
        
        else if(type == ROOM) 
        {
            #ifdef VERBOSE
            printf ("Type {%d} : %s\n", type, ptr->line);
            #endif
            //is_room(ptr->line, l_rooms, NORMAL_ROOM);
            is_room(ptr->line, lemin->l_rooms, NORMAL_ROOM);
        }
        //else exit (EXIT_FAILURE);

        //        printf(" l_view_struc2 () : %s", ptr->line);

        element = element->next;
    } // while
    printf("\n");
    #ifdef VERBOSE
        printf ("Exit my_get_line ()\n");
    #endif
}