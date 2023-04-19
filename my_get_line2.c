#include "lemin.h"

/*
**================= my_get_line ========================
*/
t_line_type my_get_line2(char *line)
{
    #ifdef VERBOSE
        printf ("===== Enter my_get_line () =====\n");
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

   //else printf ("Invalid line.\n"); 
        
    return -1;

    #ifdef VERBOSE
        printf ("Exit my_get_line2 ()\n");
    #endif
}