#include "lemin.h"

Bool get_ants_number(t_lemin *lemin)
{
    t_line *tmp_line = (t_line *)malloc(sizeof(t_line));
    t_element *el = lemin->l_lines->first;
    while (el != NULL)
    {
        tmp_line = (t_line *)el->data;
        if (tmp_line != NULL && my_get_line2(tmp_line->line) == ANTS)
        {
            lemin->ant_nb = str_to_int(tmp_line->line);
            return true;
        }
        el = el->next;
    }
    return false;

}