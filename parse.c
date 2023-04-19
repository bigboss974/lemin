#include "lemin.h"
/*
** appelle la fonction parse_token
** infos de la room dans room_infos (name X Y)
*/
void parse_room (const char *line, char **room_infos)
{
    parse_token(&line, room_infos, 0);
}

/*
**================= parse_token ========================
* Recupére les mots separés par un espace dans une chaine
*  str contient est un pointeur sur un tableau contenant les mots trouvés
*/
void parse_token(const char **expr, char **str, int inc)
{
    str[inc] = (char *)parse_str(expr);
//    printf("token : [%s] [%d]\n", str[inc], inc);

    if (**expr == ' ')
    {
        if (**expr == ' ') 
            *expr += 1;
        inc++;
        parse_token(expr, str, inc);
    }
}

/*
**================= parse_token ========================
* Retourne une chaine de caracteres 
*/
char *parse_str(const char **ptr)
{
    char *str;
    str = malloc(sizeof(char*));
    const char *expr = *ptr;
    int i = 0;

    while (expr[i] != ' ' && expr[i] != '\0')
    {
        str[i] = expr[i];
        i = i + 1;
    }
    str[i] = '\0';
    *ptr = expr + i; // ce qui reste a parser
    return str;
}

/*
**================= str_to_int ========================
* Compte le nombre de mots dans une chaine de caractere
*  retourne le nombre de mot 
*/
int count_words (char *line)
{
    int i;
    int nb;

    i = nb = 0;
    while (line && line[i])
    {
        if (i > 0 && (line[i] == ' ') && line[i - 1] != ' ')    nb++;
        else if (i == 0 && line[i] != ' ')  nb++;

        i++;
    }
    return (nb);
}
/*
**================= str_to_int ========================
* Convertir une chaine de caractere en entier positif
*  retourne -1 en cas d'erreur
*/
int str_to_int (char *str)
{
    int num = 0;
    int i = 0;
    while (str[i])
    {
        if (!is_digit(str[i])) return -1;
        num = num * 10 + str[i] - '0';
        i++;
   }
    return num;
}


t_line_type get_line_type (char *line)
{   
    #ifdef VERBOSE
        printf ("Enter get_line_type ()\n");
    #endif

    if (!strcmp(line, "##start"))
        return (START);
    
    else if (!strcmp(line, "##end"))
        return (END);
    
    else if (line[0] == '#')
        return (COMMENT);
    
    else if (is_link(line))
        return (LINK);

    else if (count_words(line) == 3)
        return (ROOM); 
    
    else if (is_valid_number(line))
        return (ANTS);
    else printf ("Invalid file\n"); 
        
    return -1;
}


