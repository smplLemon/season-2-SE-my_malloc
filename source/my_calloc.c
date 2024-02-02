#include "../include/my_malloc.h"

void* my_calloc(size_t get_bulk, size_t take_sz){
    int overal_ssize = get_bulk + take_sz;
    size_t size_box = overal_ssize; 
    void* mem_m_alloc = my_malloc(size_box);
    fill_wnull(mem_m_alloc, size_box);
 
    return mem_m_alloc; 
} 