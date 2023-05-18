#ifndef _MAIN_H
#define _MAIN_H

#ifndef STR_LEN
#define STR_LEN 16
#endif

#define HELP_STR "help\nw - write [FirstName] [SecondName] [PhoneNumber] [Address]\nr - read, option:[search param]\nd - delene [Number]\nq - quit\n"

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct command
{
    char param0[STR_LEN];
    COMMAND_INS;  
}typedef command;

#endif