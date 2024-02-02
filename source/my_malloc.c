#include "../include/my_malloc.h"
const int SAVE_MAXMEM = 2048;
Encipher_str *arr_encrypt[1024];
void* special_points = NULL;
int size_fuse = 0, arr_indicator = 0;


void fill_wnull(void* ray1, int g_sz) {
    char* ptr = (char*)ray1;
    for (int i = 0; i < g_sz; ++i) {
        ptr[i] = 0;
    }
}

void give_mem(){ 
    special_points = mmap(NULL, SAVE_MAXMEM, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0) ;
}
 
void* scaning_free(size_t bulk_sz){
    if(arr_indicator == 0){ 
        return NULL;
    }
    if(arr_encrypt[arr_indicator] && arr_encrypt[arr_indicator]->absolve == true){
        return NULL;
    }
    else{
        for(int i = 0; i < arr_indicator; i++){
            if(arr_encrypt[i]->length_s == bulk_sz){
                if(arr_encrypt[i]->absolve == false){
                    continue;
                }
                return arr_encrypt[i]->point_ret;
            }
        }
        return NULL;
    }
}

void encrypt_part(size_t amount_arr){
    arr_encrypt[arr_indicator] = (Encipher_str*)special_points;
    arr_encrypt[arr_indicator]->point_ret = sizeof(Encipher_str) + special_points;
    special_points += (sizeof(Encipher_str) + amount_arr);
    arr_encrypt[arr_indicator]->absolve = false;
    arr_encrypt[arr_indicator]->length_s = amount_arr;
    size_fuse += (sizeof(Encipher_str) + amount_arr);
    arr_indicator++;
}

void* my_malloc(size_t dimention_arr){
    if(special_points == NULL){
        give_mem();
    }
    void* res_searchingp = scaning_free(dimention_arr);
    if(res_searchingp == NULL){
        encrypt_part(dimention_arr);
    }
    res_searchingp = arr_encrypt[arr_indicator-1]->point_ret;
    return res_searchingp;
}