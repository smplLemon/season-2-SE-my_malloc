#ifndef MAIN_MALLOC
#define MAIN_MALLOC
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>
typedef struct Encipher_str
{
    size_t length_s;
    bool absolve;
    void* point_ret;
} Encipher_str;
#endif


//------------------------------------MALLOC
#ifndef MY_MALLOC
#define MY_MALLOC
    void fill_wnull(void* ray1, int g_sz);
    void give_mem();
    void* scaning_free(size_t bulk_sz);
    void encrypt_part(size_t amount_arr);
    void* my_malloc(size_t dimention_arr);
#endif

//------------------------------------REALLOC
#ifndef MY_REALLOC
#define MY_REALLOC
    void* my_realloc(void* elem_1, size_t get_ssize);
#endif

//------------------------------------CALLOC
#ifndef MY_CALLOC
#define MY_CALLOC
    void* my_calloc(size_t get_bulk, size_t take_sz);
#endif

//------------------------------------FREE 
#ifndef MY_FREE
#define MY_FREE
    void my_free(void* grab_elem);
#endif