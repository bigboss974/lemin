#include "lemin.h"

int main (void)
{   
 
    t_lemin *lemin = (t_lemin *) malloc(sizeof (t_lemin ));

    init_lemin(lemin);
    get_flux(lemin);
    create_rooms_list(lemin);
    create_link(lemin);

#ifdef VERBOSE
    printf ("====== Retour dans main () ======\n");
#endif

    if (!get_ants_number(lemin)) 
    {
        printf ("Ant number not found.Invalide file.");
        exit(EXIT_FAILURE);
    }
    printf ("Total ants number : [%d]\n\n", lemin->ant_nb);

    printf ("Flux STDIN ======\n");
    l_view_line(lemin->l_lines);
    printf ("Total lines: [%d]\n\n", l_lenght(lemin->l_lines));
    
 
    printf ("Rooms in anthill =======\n");
    l_view_struct(lemin->l_rooms);
    printf ("Total rooms: [%d]\n\n", l_lenght(lemin->l_rooms));

    printf ("Link in anthill ======\n");
    l_view_link(lemin->l_links);
    printf ("Total : [%d]\n", l_lenght(lemin->l_links));
/*
    printf ("\nMatrice adjacente ======\n");
    int **matrice = create_adj_list(lemin);
    display_adj_list(matrice, lemin->room_nb);

    free (matrice);
*/
    printf ("\nParcours BFS ======\n");
    bfs(lemin, 2, lemin->room_nb);

    clear_all(lemin);

  
 /*   free (lnk);
    free (l_links);
    l_clear(l_rooms);
    free (l_line);
   free (roomname);
*/
}