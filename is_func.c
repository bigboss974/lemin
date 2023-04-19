#include "lemin.h"
/*
**================== is_comment ===================
**en entree, chaine qui commence par un #,
**si ce n'est pas ##start ou ##end, retourne COMMENT (commentaire)
**Sinon retourne START_CMD ou END_CMD
*/
int is_comment(char *line)
{
    if (strcmp(line, "##start") == 0)
    {
        // printf ("Commande start\n");
        return START;
    }
    else if (strcmp(line, "##end") == 0)
    {
        // printf ("Commande end\n");
        return END;
    }

    return COMMENT; // commentaire
}

/*
**================== is_link ===================
**en entree, chaine Salle1-Salle2
**Si c'est un lien valide retourne 1 sinon retourne 0
*/
int is_link(char *line)
{
#ifdef VERBOSE
    printf ("====== Enter is_link () ======\n");
#endif

    int i = 0;
    int ok = 0;
    int err = 0;

    if (count_words(line) != 1) return 0;   // aucun espace dans la ligne

    while (line[i] && !err)
    {
        if (i > 0 && ok == 0 && line[i] == '-') //premier caractere != '-'
            ok = 1;
        else if (i > 0 && ok == 1 && line[i] == '-')
            err++;
        else if (i == 0 && line[i] == '-')
            err++;
        else if (i == strlen(line) - 1  && line[i] == '-')
            err++;
        i++;
    }
    if (!err)
        return (ok);
    else
        return 0;
}

/*
    Teste si un caractere est un chiffre
    retourne true en cas de succés sinon false
*/
Bool is_digit (char c)
{   
    if (c >= '0' && c <= '9')   return true;

    return false;
}

/*
    Test si la chaine est un nombre entier valide
    retourne true en cas de succés sinon false
*/
Bool is_valid_number (char *str)
{   
    int i = 0;
    while (str[i])
    {
        if (!is_digit(str[i])) return false;
        i++;
   }
    return true;
}
