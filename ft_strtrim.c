#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1 , char const *set){
    int start;
    int end;
    start = 0;
    if(!s1 || !set)
        return NULL;

    while(s1[start] && ft_strchr(set , s1[start])){
        start++;
    }
    end = ft_strlen(s1);
    while(s1[end - 1] && ft_strchr(set , s1[end-1])){
        end--;
    }
    return (ft_substr(s1 , start , end - start));
}
