//
// Created by jorda on 4/27/2021.
//

#ifndef HASHTBL_HASHTBL_H
#define HASHTBL_HASHTBL_H
typedef struct
{
    char* key;
    char* value;
} item;

typedef struct
{
    int size;
    int count;
    item** items;
} hashtbl;


#endif //HASHTBL_HASHTBL_H
