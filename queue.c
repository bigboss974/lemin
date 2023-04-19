/*
    GESTION DE FILE FIFO
*/
//#include "queue.h"
#include "lemin.h"

/*------------------------------------------------------------------
    init_queue () : Initilise la file
------------------------------------------------------------------*/
Queue init_queue(void)
{
    Queue queue = malloc(sizeof(Queue));

    if (queue == NULL)
    {
        printf("Fonction init_queue () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    queue->first = NULL;
    return queue;
}

/*----------------------------------------------------------------*/
/*  is_empty_queue () : Teste si la file est vide
------------------------------------------------------------------*/
Bool is_empty_queue(Queue f)
{
    if (f == NULL)
        return true;
    return false;
}

/*----------------------------------------------------------------*/
/*  enqueue_queue () : Enfile un élémement dans la file
------------------------------------------------------------------*/
void enqueue_queue(Queue q, void *data, size_t size)
{
    QueueElement *new_element = malloc(sizeof(*new_element));

    if (q == NULL || new_element == NULL)
    {
        printf("enqueue_queue () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    new_element->data = malloc(size);
    if (!new_element->data) exit (EXIT_FAILURE);

    memmove(new_element->data, data, size);
    new_element->next = NULL;

    // new_element->data = data;
    // new_element->next = NULL;

    if (q->first != NULL) // la file n'est pas vide
    {
        /* On se positionne à la fin de la file*/
        QueueElement *current_element = q->first;
        while (current_element->next != NULL)
        {
            current_element = current_element->next;
        } // fin de while
        current_element->next = new_element;
    }
    else // la file est vide, le premier el est le nouvel el
    {
        q->first = new_element;
    }
}

/*----------------------------------------------------------------*/
/*  dequeue_queue () : Défile un élément dans la file
------------------------------------------------------------------*/
void *dequeue_queue(Queue q)
{
    void *data = NULL;

    if (q == NULL)
    {
        printf("queue_print () : Erreur queue null");
        exit(EXIT_FAILURE);
    }
    /* st ce qu'on a qq ch a defiler ?*/
    if (q->first != NULL)
    {
        QueueElement *element = q->first;
        data = element->data;
        q->first = element->next;
        free(element);
    }
    return data;
}

/*----------------------------------------------------------------*/
/*  queue_print () : Affiche les éléments de la file
    todo :  Fonction d'affichage pour type de base (int, char, float)
    todo :  Prototype queue_print (Queue, void (*pf)(Queue))
------------------------------------------------------------------*/
void queue_print(Queue q)
{
    if (q == NULL)
    {
        printf("queue_print () : Erreur queue null");
        exit(EXIT_FAILURE);
    }

    QueueElement *element = q->first;
    while (element != NULL)
    {
        printf("%s", (char *)element->data);
        element = element->next;
    } // while
    printf("\n");
}
/*----------------------------------------------------------------
    queue_length () ;  Nb d'element dans la liste.
------------------------------------------------------------------*/
int queue_length(Queue q)
{
    int nb_element = 0;
    if (q == NULL)
    {
        printf("queue_length () : Erreur queue null");
        exit(EXIT_FAILURE);
    }

    QueueElement *element = q->first;
    while (element != NULL)
    {
        // printf ("[%d]  ", *(int *)element->data);
        nb_element++;
        element = element->next;
    } // while
    return nb_element;
}

/*----------------------------------------------------------------
    delete_queue () ;   Fonction teste des appels de fonctions
------------------------------------------------------------------*/
void delete_queue(Queue q)
{
    if (q == NULL)
    {
        printf("delete_queue () ; Erreur liste vide\n");
        exit(EXIT_FAILURE);
    }

    while (q->first != NULL)
    {
        QueueElement *aSupprimer = q->first;
        q->first = q->first->next;
        free(aSupprimer);
    }
}

//! =============================================
void queue_print_st(Queue q)
{
    t_room *ptr = (t_room *)malloc(sizeof(t_room));

    if (q == NULL || ptr == NULL)
    {
        printf("queue_print_st () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }

    QueueElement *element = q->first;

    while (element != NULL)
    {
        ptr = element->data;

        printf("[%d] [%s] [%d] \n", ptr->id, ptr->name, ptr->empty);
        element = element->next;
    } // while
    printf("\n");
}

/*----------------------------------------------------------------
   menu () ;   Fonction teste des appels de fonctions
------------------------------------------------------------------*/
void menu(void)
{
    Queue my_queue = init_queue();
    t_data d1 = {1, "Chaine de 1\0"};
    t_data d2 = {2, "Chaine de 2\0"};
    t_data *ptr = (t_data *)malloc(sizeof(t_data));

    printf("Enfile [%s] [%d]\n", d1.name, d1.id);
    enqueue_queue(my_queue, &d1, sizeof(t_data));
    printf("Enfile [%s] [%d]\n", d2.name, d2.id);
    enqueue_queue(my_queue, &d2, sizeof(t_data));

    printf("Etat de la file : \n");
    queue_print_st(my_queue);
    printf("Nombre d'element de la liste : [%d]\n", queue_length(my_queue));

    ptr = (t_data *)(dequeue_queue(my_queue));
    printf("\n Defile name: [%s] id: [%d]\n", ptr->name, ptr->id);

    /* printf (" Defile %d \n", *(int *) dequeue_queue(my_queue));
     printf (" Defile %d \n", *(int *) dequeue_queue(my_queue));*/
    printf("\nEtat de la liste");
    queue_print_st(my_queue);

    printf("Nombre d'element de la liste : [%d]\n", queue_length(my_queue));

    delete_queue(my_queue);
    printf("\nLa liste a été vidée\n");
    free(ptr);
    free(my_queue);
}
/*----------------------------------------------------------------*/