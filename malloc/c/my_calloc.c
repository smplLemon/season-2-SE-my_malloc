#include "../h/my_stdlib.h"

void* my_calloc(size_t elements, size_t type) {
    int size = elements * type;
    if (big_chunk_mem == NULL) my_init();        
    short i = 0;
    while (i < 7) {
        if (LIST[i] != NULL) {
            block* ptr = LIST[i];
            while (ptr != NULL) {
                if (ptr->free && ptr->size >= size) {
                    ptr->free = 0;
                    return ptr->user_pointer;
                }
                ptr = ptr->next;
            }
        }
        i++;
    }
    return split_memory(size, 1);
}