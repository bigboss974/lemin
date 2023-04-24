#include "lemin.h"

int main (void)
{   
 
    t_lemin *lemin = (t_lemin *) malloc(sizeof (t_lemin ));

    init_lemin(lemin);
    get_flux(lemin);
    l_view_line(lemin->l_lines);

 
    create_rooms_list(lemin);
    create_link(lemin);

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

    printf ("\nParcours BFS ======\n");
    bfs(lemin, 0, lemin->room_nb);
   clear_all(lemin);
}