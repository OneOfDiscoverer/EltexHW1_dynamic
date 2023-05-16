#include "list.h"

list* getAt(int id){
    list* tmp = head;
    for(int i = 0; i < id; i++){
        if(tmp->ptr == 0) 
            return 0;
        tmp = tmp->ptr;
    }
    return tmp;
}

void pushBack(void *ptr){
    list* cur_ptr;
    if(!head){
        head = calloc(1, sizeof(list));
        cur_ptr = head;
    }
    else {
        cur_ptr = head;
        while(cur_ptr->ptr){
            cur_ptr = cur_ptr->ptr;
        }
        cur_ptr->ptr = calloc(1, sizeof(list));
        cur_ptr = cur_ptr->ptr;
    }
    char* ptr_book = (char*)&cur_ptr->bk;
    while(ptr_book < ((char*)&cur_ptr->bk + sizeof(cur_ptr->bk))){
        if(!*ptr_book) 
            *ptr_book = *(char*)ptr;
        ptr_book++;
        (char*)ptr++;
    }
}

void popBack(void){
    list* cur_ptr = head;
    list* prev_ptr = 0;
    if(cur_ptr){
        while(cur_ptr->ptr){
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->ptr;
        }
        free(cur_ptr);
        if(prev_ptr)
            prev_ptr->ptr = 0;
        else 
            head = 0;
    }
    
}

void add_at(){
    

}
