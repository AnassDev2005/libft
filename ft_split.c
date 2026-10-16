#include "libft.h"

int count_word(char const *s , char c){
    int i;
    int count;
    i = 0;
    count = 0;
    while(s[i]){
        if(s[i] == c)
            count++;
        i++;
    }
    return count;
}


char **ft_split(char const *s , char c){
    char **splited;
    char *copy ;
    copy = ft_strdup(s);
    splited = malloc(sizeof(*char) * count_word(s , c));
    if(!splited)
        return NULL;

    while(*copy){

    }
}
