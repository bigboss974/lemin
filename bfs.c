#include "lemin.h"
/*
    create_adj_list ()
    Création de la matrice d'adjacense
*/
int **create_adj_list (t_lemin *lemin)
{
    int nbSommets = lemin->room_nb;
    int **adj;
    t_link *ptr = (t_link *)malloc(sizeof(t_link));

    if (ptr == NULL)
    {
        printf("create_adj_list () : malloc error.\n");
        exit(EXIT_FAILURE);
    }
    /*
        Initialisation / allocation mémoire matrice
    */

    adj =  (int **) malloc (nbSommets*sizeof(int *));
    if (adj == NULL)
    {
        printf ("create_adjlist () : Malloc error.\n");
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i <nbSommets ; i++)
    {
        adj[i] = (int *) malloc(nbSommets*sizeof(int ));

        if (adj[i] == NULL)
        {
            printf ("create_adjlist () : Malloc error.\n");
            exit (EXIT_FAILURE);
        }
    }//for

    /*
        RAZ liste
    */
    for ( int i = 0; i < nbSommets ; i++)
        for ( int j = 0; j < nbSommets ; j++) adj[i][j] = 0;
    
    /*
        Parcous des liens et affectation de la matrice
    */
    t_element *element = lemin->l_links->first;
    while (element != NULL)
    {
        ptr = (t_link *)element->data;
        int src = (int)ptr->id_room1;
        int dest = (int)ptr->id_room2;
        
        printf("[%d] - [%d]\n", src, dest);
        adj[src][dest] = 1;
        //todo a voir si on garde oou pas le symetrique
        adj[dest][src] = 1;

        element = element->next;
    } // while   
    return adj;
}

/*
    bfs
*/
void bfs (t_lemin *lemin, int src, int dest)
{
    int *visited = (int *)malloc(lemin->room_nb*sizeof(int ));
    t_node *node = (t_node *)malloc (sizeof(t_node));
    t_list *queue = (t_list *)malloc (sizeof(t_list));
    int **adj = create_adj_list(lemin);
    display_adj_list(adj, lemin->room_nb);

    if (visited == NULL || node == NULL || queue == NULL)
    {
        printf ("bfs () : malloc () error.\n");
        exit(EXIT_FAILURE);
    }
    l_init(queue);

    visited[src] = 1;
    node->vertex = src;
    l_push_front(queue, (void *)node, sizeof(node));
    int tab[lemin->room_nb];
    int j = 0;
    while (queue->first != NULL)
    {
        
        printf ("Node queue ======\n");
        l_view_node(queue);

        //pop oldest node
        node = (t_node *)l_pop_front(queue);
        //t <- v
        int curVertex = (int)node->vertex; 
        printf ("Visited %d\n", curVertex);
        tab[j]  = curVertex;
        j++;

        for (int i = 0; i < lemin->room_nb; i++)
        {

            if (adj[curVertex][i] == 1)
            {
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    node->vertex = i;
                    l_push_front(queue,(void *) node, sizeof(node));
                }
            }
        }
    }//while
    printf ("Result : ");
    for (int i = 0; i < lemin->room_nb; i++)
        printf ("(%d)", tab[i]);
    printf ("\n");
}


/*
    display_adj_list ()
    max : nb element a afficher (lemin->room_nb)
*/
void display_adj_list (int **adj, int max)
{
    /*
        Affichage de la matrice.
    */
    for ( int i = 0; i < max ; i++)
    {
        for ( int j = 0; j < max ; j++) 
        {
            printf(" %d, ", adj[i][j]);
        }
    printf("\n");
    }
}
