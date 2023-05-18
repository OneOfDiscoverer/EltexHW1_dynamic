#include "main.h"

void printUser(book *pb, int num){
    printf("Number: %d\nFn: %s \nSn: %s\nPh: %s\nAd: %s\n\n", num, pb->firstName, pb->secondName, pb->phoneNumber, pb->address);
}

int checkNum(char* str){
    const char *end = str + STR_LEN;
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
                if(*cmd.bk.firstName){ //search in list
                    while(tmpPtr){
                        for(int b = 0; b < sizeof(tmpPtr->bk)/STR_LEN; b++){
                            int result = 0;
                            char* ptr = (char*)&tmpPtr->bk + STR_LEN*b;
                            for(int j = 0; j < STR_LEN; j++){
                                result += *(cmd.bk.firstName+j) - *(ptr+j);
                            }
                            if(!result)
                                printUser(&tmpPtr->bk, i);
                        }
                        tmpPtr = getAt(++i);
                    }
                }
                else{
                    while(tmpPtr){ //out all
                        printUser(&tmpPtr->bk, i);
                        tmpPtr = getAt(++i);
                    }
                }
                break;
            }
            case 'd':{
                if(checkNum(cmd.bk.firstName)){
                    if(remove_at(atoi(cmd.bk.firstName)))
                        printf("removed %d\n", atoi(cmd.bk.firstName));
                    else
                        printf("member %d does not exist\n", atoi(cmd.bk.firstName));
                }
                break;
            }          
            case 'q':
                while(remove_at(0));
                exit(0);
            default:
                printf(HELP_STR);
                break;
        }
    }
    return 0;
}