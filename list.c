#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "list.h"
#include "lemin.h"
/*
        Front ==> NULL <- el1 -> el2 -> el3-> NULL <== Back
                          ^              ^
                         /|\            /|\
                          |              |
                        First           Last

    File : FIFO PushBack PopFront || Pushfront PopBack
    Pile : LIFO PushBack PopBack || PushFront PopFront
*/

/*
**================= l_init ========================
**Initialisation des pointeurs d'entrée et de sortie de la liste.
*/
void l_init(t_list *l)
{
    l->first = NULL;    // head
    l->last = NULL;    // tail
}


/*
**================= l_length ========================
* Retourne le bombre d'elements de la liste
*/
int l_lenght(t_list *l)
{
    int count = 0;
    t_element *pelem = l->first;
    while (pelem)
    {
        pelem = pelem->next;
        count++;
    }
    return (count);
}

/*
**================= l_push_back ========================
** Ajoute un élement data de taille size en fin de liste
*/
void l_push_back(t_list *l, void *data, size_t size)
{
    t_element *newone = malloc(sizeof(t_element));

    if (!newone)
        exit(EXIT_FAILURE);

    newone->data = malloc(size);
    if (!newone->data)
        exit(EXIT_FAILURE);
    memcpy(newone->data, data, size);

    newone->prev = l->last;
    newone->next = NULL;

    if (l->last)
        l->last->next = newone;
    else
        l->first = newone;

    l->last = newone;
}

/*
**================= l_push_front ========================
** Ajoute un élement data de taille size en début de liste
*/
void l_push_front(t_list *l, void *data, size_t size)
{
    t_element *newone = malloc(sizeof(t_element));

    if (!newone)
        exit(EXIT_FAILURE);

    newone->data = malloc(size);
    if (!newone->data)
        exit(EXIT_FAILURE);
    memcpy(newone->data, data, size);

    newone->next = l->first;
    newone->prev = NULL;

    if (l->first)
        l->first->prev = newone;
    else
        l->last = newone;

    l->first = newone;
}

/*
**================= l_pop_back ========================
** Retire un élement data de taille size en fin de liste
*/
void *l_pop_back(t_list *l)
{
    t_element *tmp = l->last;
    void *val;

    if (!tmp)
        return NULL;
    val = tmp->data;
    l->last = tmp->prev;

    if (l->last)
        l->last->next = NULL;
    else
        l->first = NULL;

    free(tmp);
    return val;
}

/*
**================= l_pop_front ========================
** Retire un élement data de taille size en début de liste
*/
void *l_pop_front(t_list *l)
{
    t_element *tmp = l->first;
    void *val;

    if (!tmp)
        return NULL;
    val = tmp->data;
    l->first = tmp->next;

    if (l->first)
        l->first->prev = NULL;
    else
        l->last = NULL;

    free(tmp);
    return val;
}

/*
**================= l_clear ========================
** Vide la liste libere la mémoire.
*/
void l_clear(t_list *l)
{
    t_element *pelem = l->first;
    t_element *tmp = NULL;
    while (pelem)
    {
        tmp = pelem->next;
        free (pelem->data);
        free(pelem);
        pelem = tmp;
    }
    free (tmp);
}

/*
**================= l_view ========================
** Affiche la file  (exemple a modifier en fonction des besoins (cast))
*/
void l_view(t_list *l)
{
    t_element *pelem = l->first;
    while (pelem)
    {
        printf("elem : [%d]\n", *(int *)pelem->data);
        pelem = pelem->next;
    }
}

/*
**================= l_get_first ========================
 Recupère le data du premier element de la liste
**/
void *l_get_first(t_list *l)
{
    void *val;
    t_element *tmp = l->first;

    if (!tmp)
        return NULL;

    val = tmp->data;
    return val;
}

/*
**================= l_get_last ========================
 Recupère le data du dernier element de la liste
*/
void *l_get_last(t_list *l)
{
    void *val;
    t_element *tmp = l->last;

    if (!tmp)
        return NULL;

    val = tmp->data;

    return val;
}


/*
**================= l_view_struct (l_line) ========================
** Affiche la file  data est une structuer(exemple a modifier en fonction des besoins (cast))
*/
void l_view_line(t_list *q)
{

    t_line *ptr = (t_line *)malloc(sizeof(t_line));

    if (q == NULL || ptr == NULL)
    {
        printf("l_view_line () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = q->first;
    while (element != NULL)
    {
        ptr = (t_line *)element->data;
        printf("[%s]\n", ptr->line);
       
        element = element->next;
    } // while
    free (ptr->line);
    free (element);
}


/*
**================= l_view_link(l_link) ========================
** Affiche la file  data est une structuer(exemple a modifier en fonction des besoins (cast))
*/
void l_view_link(t_list *q)
{
#ifdef VERBOSE
    printf ("====== Enter l_view_link () ======\n");
#endif

    t_link *ptr = (t_link *)malloc(sizeof(t_link));

    if (ptr == NULL)
    {
        printf("l_view_link () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = q->first;

    while (element != NULL)
    {
        ptr = (t_link *)element->data;
        printf("room [%d] => room [%d]\n", ptr->id_room1, ptr->id_room2);
        element = element->next;

    } // while
 #ifdef VERBOSE
    printf ("Exit l_view_link ()\n");
#endif
}


/*
**================= l_view_struct  (l_room)========================
** Affiche la file  data est une structuer(exemple a modifier en fonction des besoins (cast))
*/
void l_view_struct(t_list *q)
{
#ifdef VERBOSE
    printf ("====== Enter l_view_struct (), l_rooms ======\n");
#endif   
    t_room *ptr = (t_room *)malloc(sizeof(t_room));
    char *r[]= {"START", "NORMAL", "END"};
    if (q == NULL || ptr == NULL)
    {
        printf("queue_print_st () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = q->first;
    while (element != NULL)
    {
        ptr = (t_room *)element->data;
        printf("id: [%d] Name: [%s] \
                x: [%d] y: [%d] empty: [%d] [%s]\n",\
                ptr->id, ptr->name, ptr->x, ptr->y, ptr->empty, r[ptr->type]);
        
        element = element->next;
    } // while
#ifdef VERBOSE
    printf ("Exit l_view_struct (), l_rooms\n");
#endif
}


//=====================================

void l_view_node(t_list *q)
{
    t_node *ptr = (t_node *)malloc(sizeof(t_node));
    if (ptr == NULL)
    {
        printf("l_view_node () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = q->first;

    while (element != NULL)
    {
        ptr = (t_node *)element->data;
        printf("Vertex : [%d] \n", ptr->vertex);
        element = element->next;

    } // while
}


/*
**================= l_view_struct  (l_room)========================
** Affiche la file  data est une structuer(exemple a modifier en fonction des besoins (cast))
*/
/*
void l_view_struct(t_list *q)
{
    t_room *ptr = (t_room *)malloc(sizeof(t_room));
    char *r[]= {"START", "NORMAL", "END"};
    if (q == NULL || ptr == NULL)
    {
        printf("queue_print_st () : Erreur allocation\n");
        exit(EXIT_FAILURE);
    }
    t_element *element = q->first;
    while (element != NULL)
    {
        ptr = (t_room *)element->data;
        printf("id: [%d] Name: [%s] \
                x: [%d] y: [%d] empty: [%d] [%s]\n",\
                ptr->id, ptr->name, ptr->x, ptr->y, ptr->empty, r[ptr->type]);
        
        element = element->next;
    } // while
}
*/
