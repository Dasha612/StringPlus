#include "s21_string.h"


void *s21_to_upper(const char *str){
    char* low = S21_NULL;
    char * result = low;
   
    
    if (str != S21_NULL){
        low = malloc(s21_strlen(str) + 1);
        result = low;
        
         while (*str != '\0' ){
            if ('a' <= *str && *str <= 'z'){
                *low = *str ^ 0x20;

            }else {
                *low = *str; 
            }
            str++;
            low++;
        }
        *low = '\0';

    } 
    return (void *)result;

}