#include "main.h"

void printUser(book *pb, int num){
    printf("ID: %d\nFn: %s \nSn: %s\nPh: %s\nAd: %s\n\n", num, pb[num].firstName, pb[num].secondName, pb[num].phoneNumber, pb[num].address);
}

void unitClear(book *pb){
    for(int i = 0; i < sizeof(book); i++){
        *((char*)pb + i) = 0;
    }
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
    book phonebook[BOOK_LEN];

    for(int i = 0; i < BOOK_LEN; i++){
        unitClear(&phonebook[i]);
    }

    while(1){
        switch(getCmd(&cmd)){
            case 'w':
                if(checkNum(cmd.param1)){
                    int tmp = atoi(cmd.param1);
                    if(tmp < BOOK_LEN){
                        char* ptr_cmd = (char*)&cmd.bk;
                        char* ptr_book = (char*)&phonebook[tmp];
                        while(ptr_book < ((char*)&phonebook[tmp] + sizeof(book))){
                            if(!*ptr_book) 
                                *ptr_book = *ptr_cmd;
                            ptr_book++;
                            ptr_cmd++;
                        }
                    }
                    else 
                        printf("out of range\n");
                }
                break;
            case 'r':
                if(checkNum(cmd.param1)){
                    int tmp = atoi(cmd.param1);
                    if(tmp < BOOK_LEN)
                        printUser(phonebook, tmp);
                    else 
                        printf("out of range\n");
                }
                break;
            case 'd':
                if(checkNum(cmd.param1)){
                    int tmp = atoi(cmd.param1);
                    if(tmp < BOOK_LEN) 
                        unitClear(&phonebook[tmp]);
                }
                else 
                    printf("out of range\n");
                break;
            case 'l':
                for(int i = 0; i < BOOK_LEN; i++){
                    printUser(phonebook, i);
                }
                break;
            case 's':
                if(*cmd.param1){
                    for(int i = 0; i < BOOK_LEN; i++){
                        for(int b = 0; b < sizeof(book)/STR_LEN; b++){
                            int result = 0;
                            char* ptr = (char*)&phonebook[i] + STR_LEN*b;
                            for(int j = 0; j < STR_LEN; j++){
                                result += *(cmd.param1+j) - *(ptr+j);
                            }
                            if(!result)
                                printUser(phonebook, i);
                        }
                    }
                }
                break;
            case 'q':
                return 0;
                break;
            default:
                printf("help\nw - write [FirstName] [SecondName] [PhoneNumber] ...\nr - read [ID]\nd - delene [ID]\nl - list all\ns - search [PARAM]\nq - quit\n");
                break;
        }
    }
    return 0;
}