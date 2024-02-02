#include "../include/my_malloc.h"
extern Encipher_str *arr_encrypt[1024];
extern int size_fuse, arr_indicator;

void* my_realloc(void* elem_1, size_t get_ssize){
    size_t save_bulk;
    Encipher_str* hash_part;
    for(int i = 0; i < arr_indicator; i++){
        if(arr_encrypt[i]->point_ret == elem_1){
            hash_part = arr_encrypt[i];
            save_bulk = arr_encrypt[i]->length_s;
       }
    }  
    if(hash_part == NULL){ 
        return my_malloc(get_ssize);
    }
    void* memory = my_malloc(get_ssize);
    memcpy(memory, elem_1, save_bulk);
    my_free(elem_1);
    return memory;
}