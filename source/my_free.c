#include "../include/my_malloc.h"
extern Encipher_str *arr_encrypt[1024];
extern int size_fuse, arr_indicator;


void my_free(void* grab_elem){
    if(grab_elem != NULL){
        for(int j = 0; j < arr_indicator; j++){
            if(arr_encrypt[j]->point_ret == grab_elem){
                if(arr_encrypt[j]->absolve == false){
                   arr_encrypt[j]->absolve = true;
                    fill_wnull(arr_encrypt[j]->point_ret, arr_encrypt[j]->length_s);
                }   
                else{
                    perror("double free"); 
                }
            }
        }
    }
} 