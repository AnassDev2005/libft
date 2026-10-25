#include <stdio.h>
int ff(void *f){
	long a = (long)(int *)f;
	return (a);
}
int main(void)
{
    int value = 12;
    void *f = &value;

    printf("%d\n", ff(f));
    return (0);
}
