#include "main.h"

void printUser(book *pb, int num){
    printf("ID: %d\nFn: %s \nSn: %s\nPh: %s\nAd: %s\n\n", num, pb->firstName, pb->secondName, pb->phoneNumber, pb->address);
}

int checkNum(char* str){
    const char *end = str + sizeof(str);
    if(!*str) 
        return 0;
    while(str < end){
        if((*str < '0') || (*str > '9'))
            return 0;
        str++;
        if(!*str) 
            break;
    }
    return 1;
}

char getCmd(command* cmd){
    int i = 0;
    int const size = sizeof(command);
    char* ptr = (char*)cmd;
    for(int i = 0; i < size; i++){
        *((char*)cmd + i) = 0;
    }
    while((i < STR_LEN) && ((ptr + i) < ((char*)cmd + size))){
        char tmp = (char)fgetc(stdin);
        if(tmp == '\n') 
            break;
        if(tmp == ' ') {
            i = 0;
            ptr = ptr + STR_LEN;
            continue;
        }
        *(ptr + i) = tmp;
        i++;
    }
    return *(char*)cmd; 
}

int main(){
    command cmd;
    list* head = 0;
    int size;

    while(1){

        switch (getCmd(&cmd))
        {
            case 'w':{
                list* cur_ptr = head;
                int cnt = 1;
                if(!head){
                    pushObj(&head);
                    cur_ptr = head;
                }
                else {
                    while(cur_ptr->ptr){
                        cnt++;
                        cur_ptr = cur_ptr->ptr;
                    }
                    pushObj(&cur_ptr->ptr);
                    cur_ptr = cur_ptr->ptr;
                    cur_ptr->id = cnt;
                }
                char* ptr_cmd = (char*)&cmd.bk;
                char* ptr_book = (char*)&cur_ptr->obj;
                while(ptr_book < ((char*)&cur_ptr->obj + sizeof(book))){
                    if(!*ptr_book) 
                        *ptr_book = *ptr_cmd;
                    ptr_book++;
                    ptr_cmd++;
                }
                break;
            }
                
            case 'r':{
                list* cur_ptr = head; 
                while(cur_ptr){
                    printUser(&cur_ptr->obj,cur_ptr->id);
                    cur_ptr = cur_ptr->ptr;
                }
                break;
            }

            case 'd':{
                list* cur_ptr = head;
                list* prev_ptr;
                while(cur_ptr->ptr){
                        prev_ptr = cur_ptr;
                        cur_ptr = cur_ptr->ptr;
                    }
                popObj(&cur_ptr);
                prev_ptr->ptr = 0;
                break;
            }              
            case 'q':
                exit(0);
            default:
                break;
        }
    }
    return 0;
}