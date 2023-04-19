#ifndef __LEMIN__H__
#define __LEMIN__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "queue.h"
// #include "bfs.h"

// #define VERBOSE

#define EMPTY 0
#define NOT_EMPTY 1

#define FIRST_ROOM 1
#define SECOND_ROOM 2

/*
    Definition d'un type Bool
*/
#ifndef TYPE_BOOL
#define TYPE_BOOL
typedef enum
{
    false,
    true
} Bool;
#endif

typedef enum
{
    COMMENT = 1,
    START,
    END,
    ANTS,
    LINK,
    ROOM
} t_line_type;

/*
Flag pour le type de salle
*/
typedef enum
{
    START_ROOM,
    NORMAL_ROOM,
    END_ROOM
} t_room_type;

/*
Liste des lignes récupérés dans stdin
liste chainée l_input
*/
typedef struct s_line
{
    char *line;
} t_line;

/*
Définition type room
liste chainee l_rooms
*/
typedef struct s_room
{
    int id;           // id unique
    char *name;       // nom de la salle
    t_room_type type; // normal end start
    int x;
    int y;
    int empty; // contient des fourmis ou pas
} t_room;      // recupere le nom des ch pour links

/*
Définition type link pour la matrice d'adjacence
liste chainee l_links
*/
typedef struct s_link
{
    // t_room *room1;
    // t_room *room2;
    int id_room1;
    int id_room2;
} t_link;

typedef struct s_lemin
{
    t_room_type flags; // START_ROOM NORMAL_ROOM END_ROOM
    int room_nb;
    int ant_nb;
    t_list *l_lines;
    t_list *l_rooms; // l_rooms->first
    t_list *l_links;
} t_lemin;

/*
    Definition rooms
*/
char *get_rooms_name_for_link(char *, int);
void create_rooms_list(t_lemin *);
void test(void);
void test2(void);

/*
    Definition is_room
*/
int is_room(char *, t_list *, t_room_type);
t_room *is_room_exist(char *, t_list *);
int get_room_id(t_list *, char *); // l_rooms, l_line

/*
    Definition add_room
*/
void add_room(t_list *, char **, t_room_type);

/*
    Definition get_flux
*/
void get_flux(t_lemin *);
void my_get_line(t_lemin *);      // l_line, l_rooms
t_line_type my_get_line2(char *); // l_line, l_rooms
/*
    Definition is_func
*/
int is_link(char *);
int is_comment(char *);
Bool is_digit(char);
Bool is_valid_number(char *);

/*
    Definition links
*/
t_link *init_link(t_room *, t_room *);
void create_link(t_lemin *); // todo
void get_list_link(t_lemin *);

/*
    Definition parse
*/
t_line_type get_line_type(char *);
int str_to_int(char *);
int count_words(char *);
void parse_token(const char **, char **, int);
char *parse_str(const char **);
void parse_room(const char *, char **);

/*
    Definition lemin
*/
void init_lemin(t_lemin *);
void clear_all(t_lemin *);

/*
    Definition ants
*/
Bool get_ants_number(t_lemin *);

/*
    BFS
*/
typedef struct s_node
{
    int vertex;
} t_node;

int **create_adj_list(t_lemin *);
void bfs(t_lemin *, int, int); // (lemin *, src, dest)
void display_adj_list(int **, int);

#endif