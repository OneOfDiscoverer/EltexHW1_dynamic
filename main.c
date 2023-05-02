#include "stdio.h"
#include "stdlib.h"

//для изменения количества полей необходимо менять структуру book и вывод в функции PrintUser.
//Длина книги и длина строки в структуре изменяется макросами ниже.

#define BOOK_LEN 10
#define STR_LEN 16

struct book 
{
    char firstName[STR_LEN];
    char secondName[STR_LEN];
    char phoneNumber[STR_LEN];
    char address[STR_LEN];
}typedef book;

struct command
{
    char param0[STR_LEN];
    char param1[STR_LEN];
    book bk;
}typedef command;

//test

char GetCmd(command* cmd){
    int i = 0;
    char* ptr = (char*)cmd;
    while((i < STR_LEN) && ((ptr + i) < ((char*)cmd + sizeof(command)))){
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

void PrintUser(book *pb, int num){
    printf("ID: %d\nFn: %s \nSn: %s\nPh: %s\nAd: %s\n\n", num, pb[num].firstName, pb[num].secondName, pb[num].phoneNumber, pb[num].address);
}

void CmdClear(command* cmd){
    for(int i = 0; i < sizeof(command); i++){
        *((char*)cmd + i) = 0;
    }
}

void UnitClear(book *pb){
    for(int i = 0; i < sizeof(book); i++){
        *((char*)pb + i) = 0;
    }
}

int main(){
    command cmd;
    book phonebook[BOOK_LEN];

    CmdClear(&cmd);
    for(int i = 0; i < BOOK_LEN; i++){
        UnitClear(&phonebook[i]);
    }

    while(1){
        switch(GetCmd(&cmd)){
            case 'w':{
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
                break;
            }    
            case 'd':
                if(atoi(cmd.param1) < BOOK_LEN) 
                    UnitClear(&phonebook[atoi(cmd.param1)]);
                break;
            case 'l':
                for(int i = 0; i < BOOK_LEN; i++){
                    PrintUser(phonebook, i);
                }
                break;
            case 's':
                for(int i = 0; i < BOOK_LEN; i++){
                    for(int b = 0; b < sizeof(book)/STR_LEN; b++){
                        int result = 0;
                        char* ptr = (char*)&phonebook[i] + STR_LEN*b;
                        for(int j = 0; j < STR_LEN; j++){
                            result += *(cmd.param1+j) - *(ptr+j);
                        }
                        if(!result) 
                            PrintUser(phonebook, i);
                    }
                }
                break;
            case 'q':
                return 0;
                break;
            default:
                printf("help\nw - write [FirstName] [SecondName] [PhoneNumber] ...\nd - delene [ID]\nl - list all\ns - search [param]\nq - quit\n");
                break;
        }
        CmdClear(&cmd);
    }
    return 0;
}