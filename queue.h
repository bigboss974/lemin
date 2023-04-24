#ifndef __QUEUE__H__
#define __QUEUE__H__

#ifndef TYPE_BOOL
#define TYPE_BOOL
typedef enum
{
    false,  //0
    true    //1
} Bool;
#endif

/* Définition d'un file */
/* Element d'une file*/
typedef struct QueueElement
{
    void *data;
    struct QueueElement *next;
} QueueElement;
/* File*/
typedef struct Queue
{
    QueueElement *first; // pointe sur le premier element de la file
} *Queue;

typedef struct
{
    int id;
    char *name;
} t_data;

/* Prototypes */
Bool is_empty_queue(Queue);                // Teste si la liste est vide
Queue init_queue(void);                    // Créer un file vide
void enqueue_queue(Queue, void *, size_t); // Enfile un élément
void *dequeue_queue(Queue);                // Défile un élément
void queue_print(Queue);                   // Affiche les éléments de la file
void delete_queue(Queue);                  // Vide la liste et libère la mémoire
int queue_length(Queue);                   // Renvoie le nb d"élément de la file
void queue_print_st(Queue);                // Affiche les éléments de la file (structure)

#endif