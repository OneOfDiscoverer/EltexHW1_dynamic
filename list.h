#ifndef _LIST_H
#define _LIST_H

#define STR_LEN 16
#define COMMAND_INS book bk

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

struct list
{
    void *ptr;
    COMMAND_INS;
}typedef list;

static list* head = 0;

list* getAt(int id);
int pushBack(void *ptr);
int popBack(void);
int remove_at(int num);
#endif