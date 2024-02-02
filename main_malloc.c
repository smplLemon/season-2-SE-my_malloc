#include "include/my_malloc.h"

int main()
{
    char* test_mem1 = (char*)my_malloc(7*sizeof(char));
    strcpy(test_mem1, "hello ");
    char*sec_mem = my_realloc(test_mem1, 14);
    strcat(sec_mem, "world");
    printf("%s\n", sec_mem); 
    
    char*test_mem2 = my_malloc(40*sizeof(char));
    strcpy(test_mem2, "kdvoflbmofbmpmfzdpbkmdfpkb[gmp") ;
    printf("%s\n", test_mem2);  

    char* test_mem3 = (char*)my_calloc(20, sizeof(char)) ;
    strcpy(test_mem3, "have a nice day");
    printf("%s\n", test_mem3);
    my_free(test_mem3);
    
    return 0;
}