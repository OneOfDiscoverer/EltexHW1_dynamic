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
    while(1){
        switch (getCmd(&cmd))
        {
            case 'w':{
                pushBack(&cmd.bk);
                break;
            }
            case 'r':{
                int i = 0;
                list* tmpPtr = getAt(i);
                while(tmpPtr){
                    printUser(&tmpPtr->bk, tmpPtr->id);
                    tmpPtr = getAt(++i);
                }
                break;
            }
            case 'd':{
                popBack();
                break;
            }
            case 's':
                int i = 0;
                list* tmpPtr = getAt(i);
                if(*cmd.bk.firstName){
                    while(tmpPtr){
                        for(int b = 0; b < sizeof(tmpPtr->bk)/STR_LEN; b++){
                            int result = 0;
                            char* ptr = (char*)&tmpPtr->bk + STR_LEN*b;
                            for(int j = 0; j < STR_LEN; j++){
                                result += *(cmd.bk.firstName+j) - *(ptr+j);
                            }
                            if(!result)
                                printUser(&tmpPtr->bk, tmpPtr->id);
                        }
                        tmpPtr = getAt(++i);
                    }
                }
                break;              
            case 'q':
                exit(0);
            default:
                printf("help\nw - write [FirstName] [SecondName] [PhoneNumber] [Address]\nr - read [ID]\nd - delene [ID]\nl - list all\ns - search [PARAM]\nq - quit\n");
                break;
        }
    }
    return 0;
}