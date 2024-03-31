#ifndef MALLOC_STRUCT
#define MALLOC_STRUCT

typedef struct mem_alloc {
    int size;
    int free;
    void* user_pointer;
    struct mem_alloc* next;
} block;

short hash_identify(short size);
void my_init();
void mmap_additional_memory();
void fill_null(void* mem_space, short over);
void* split_memory(int size, int c_flag);

#endif
