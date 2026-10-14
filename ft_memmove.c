#include "libft.h"

void *ft_memmove(void *dest , const void *src , size_t n){
    unsigned char *d;
    const unsigned char *s;
    size_t i;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (d > s){
    i = n;
    while(i > 0){
        i--;
        d[i] = s[i];
    }
    }else{
        i = 0;
        while(i<n){
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
