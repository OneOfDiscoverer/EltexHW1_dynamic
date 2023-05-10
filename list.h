#ifndef _LIST_H
#define _LIST_H

#define STR_LEN 16

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
    book bk;  
}typedef command;

struct list
{
    int id;
    void *ptr;
    book obj;
}typedef list;

void pushObj(list **ptr);
void popObj(list **ptr);

#endif