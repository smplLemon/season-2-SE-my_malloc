#ifndef MALLOC_STRUCT
#define MALLOC_STRUCT

typedef struct mem_alloc
{
    int size;
    int free;
    void* user_pointer;
    struct mem_alloc* next;
} block;

short hash_iden(short size);
void init();
void mmap_additional_store();
void fill_null(void* mem_space, short over);
void* split_store(int size, int c_flag);

#endif