#include "lemin.h"
/*
**================== is_room_exist ===================
**Verifie si la salle [room] existe déja
**Si la salle existe retourne un pointeur sue celle ci sinon retourne NULL.

retourne t_room si existe et NULL sinon
*/
t_room *is_room_exist(char *room, t_list *lr)
{

#ifdef VERBOSE
    printf("Enter is_room_exist ()\n");
#endif

    t_room *ptr = (t_room *)malloc(sizeof(t_room));

    if (lr == NULL || ptr == NULL)
    {
        printf("is_room _exist () : Memory error\n");
        exit(EXIT_FAILURE);
    }

    t_element *element = lr->first;
    while (element != NULL)
    {

        ptr = (t_room *)element->data;
        printf("Enter is_room_exist ()\n");
       // printf ("%s\n", ptr->name);

        if (strcmp(room, ptr->name) == 0)
        {
            return (ptr); //
        }
        element = element->next;
#ifdef VERBOSE
        printf("Is_room_exist () \n ptd => id [%d] name [%s] x [%d] y [%d]\n", ptr->id, ptr->name, ptr->x, ptr->y);
#endif
    } // while
    free(element);

#ifdef VERBOSE
    printf("Exit is_room_exist ()\n");
#endif

    return NULL;
}

/*
**================== is_room ===================
**Verifie si la ligne est de la forme Salle 10 10
** renvoie un tableau avec les splits
*/
//int is_room(char *line, t_list *l_rooms, t_room_type type)
int is_room(char *line, t_list *l_rooms, t_room_type type)
{
#ifdef VERBOSE
    printf("====== Enter is_room () ======\n");
#endif
    t_room *r1 = (t_room *)malloc(sizeof(t_room));
    char **r_infos = malloc(sizeof(char *));

    if (r1 == NULL)
    {
        printf("is_room () : Malloc error (t_room).\n");
        exit(EXIT_FAILURE);
    }

    if (r_infos == NULL)
    {
        printf("is_room () : Malloc error (r_infos).\n");
        exit(EXIT_FAILURE);
    }

    // Verifie si on a bien 3 arg name X Y
    if (count_words(line) != 3)
    {
        printf("is_room () : Invalid line.\n");
        exit(EXIT_FAILURE);
    };

    // Recupére les infs de la ligne split
    parse_room(line, r_infos);

    r1 = is_room_exist(r_infos[0], l_rooms);



    if (r1 == NULL) // room n'existe pas
    {
        printf("Is_Room : [%s] don't exist. Create it.\n", r_infos[0]);
        add_room(l_rooms, r_infos, type);
 //       printf("is_room (1)\n");
 //       l_view_struct(l_rooms);
        // todo recupere le dernier index
    }
    else // room existe deja
    {
        printf("Room : [%s] alredady exist. File error.\n", r_infos[0]);
        exit(EXIT_FAILURE);
    }
    //      printf ("Test : [%s]\n", r_infos[0]);
#ifdef VERBOSE
    printf("Exit is_room ()\n");
#endif
    return 0;
}