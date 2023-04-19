#include "lemin.h"
/*
Recupere les lignes en entree stdin et les stocke dans une liste chainéé
*/
void get_flux(t_lemin *lemin)
{
    #ifdef VERBOSE
        printf ("====== Enter get_flux () ======\n");
    #endif

    char *line = NULL;
    size_t line_buf_size = 0;
    int line_size = 0;
    t_line *tmp = malloc(sizeof(t_line *));

    line_size = getline(&line, &line_buf_size, stdin);
    tmp->line = strndup(line, line_size-1);
    l_push_back(lemin->l_lines, (void *)tmp, sizeof(tmp));

    while (line_size != -1)
    {
        line_size = getline(&line, &line_buf_size, stdin);
        if (line_size != -1)
        {
           tmp->line = strndup(line, line_size-1);
           l_push_back(lemin->l_lines, (void *)tmp, sizeof(tmp));
        }
    }

   #ifdef VERBOSE
        l_view_line(lemin->l_lines);
        printf ("Exit get_flux ()\n");
    #endif
}

