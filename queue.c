/*
    GESTION DE FILE FIFO
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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
    if (f->first == NULL)
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
    QueueElement *tmp = new_element->data;
    if (!new_element->data) exit (EXIT_FAILURE);

    //memmove(new_element->data, data, size);
    //new_element->next = NULL;

    new_element->data = data;
    new_element->next = NULL;

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

    free (tmp);
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
        free(aSupprimer->data);
        free(aSupprimer);
    }
    free(q);
}

//! =============================================
void queue_print_st(Queue q)
{
    //t_data *ptr = (t_data *)malloc(sizeof(t_data));
    t_data *ptr =  NULL;

    if (q == NULL )
    {
        printf("queue_print_st () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }

    QueueElement *element = q->first;
    while (element != NULL)
    {
        ptr = element->data;

        printf("[%d] [%s]\n", ptr->id, ptr->name);
        element = element->next;
    } // while
    printf("\n");
}