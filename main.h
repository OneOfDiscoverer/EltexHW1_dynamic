#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>

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

#endif