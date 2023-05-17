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

int pushBack(void *ptr){
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

int popBack(void){ //удалить метод
    list* cur_ptr = head;
    list* prev_ptr = 0;
    int cnt = 0;
    if(cur_ptr){
        while(cur_ptr->ptr){
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->ptr;
            cnt++;
        }
        free(cur_ptr);
        if(prev_ptr)
            prev_ptr->ptr = 0;
        else 
            head = 0;
    }
    return cnt;
}

int remove_at(int num){ //доработать до значения по умолчанию
    list* cur_ptr = head;
    list* prev_ptr = 0;
    if(cur_ptr){
        for(int i = 0; i < num; i++){
            if(cur_ptr->ptr == 0) 
                return 0;
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->ptr;
        }
        if(prev_ptr) 
            prev_ptr->ptr = cur_ptr->ptr;
        else{
            if(head->ptr) 
                head = head->ptr;
            else
                head = 0;    
        }
        free(cur_ptr);
    }
    return 1;
}

void add_at(){
    

}
