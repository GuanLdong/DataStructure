
#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    char test_str[] = "this,is,a,,,test";
    char *ptr,*retptr;
    int i=0;
 
    ptr = test_str;
 
    while ((retptr=strtok(ptr, ",")) != NULL) {
        printf("substr[%d]:%s\n", i++, retptr);
        ptr = NULL;
    }
 
    return 0;
}

