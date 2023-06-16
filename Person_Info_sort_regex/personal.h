#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

// #include <unistd.h>

#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 20

typedef struct _tPersonalInfo
{
    int nAge;
    char szName[MAX_NAME_LENGTH];
    char szPhone[MAX_PHONE_LENGTH];
} PERSON_INFO, *PPERSON_INFO;

typedef struct listNode
{
    struct listNode *next;
    PERSON_INFO *data;
    int num;
} listNode;

enum MENU_VALUE
{
    MENU_ADD = 1,
    MENU_DELETE,
    MENU_MODIFY,
    MENU_SHOW,
    MENU_EXIT
};

enum MENU_MOD
{
    MENU_NAME = 1,
    MENU_PHONE,
    MENU_AGE
};

listNode *find_end(listNode *first_list);
void Close(listNode *first_list);
void ADD(listNode *first_list);
void Delete(listNode *first_list);
void PrintInfo(listNode *first_list);
void Load(listNode *first_list);
void Modify(listNode *first_list);

void Sort(listNode *first_list);

void regex_phone(char *msgbuf);

void clear_buffer();
void is_same(listNode *temp_list, listNode *prev);
char *trim(char *str);