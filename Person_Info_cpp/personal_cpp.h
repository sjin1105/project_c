// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
#include <istream>
#include <cstring>
#include <cctype>

#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 20

using namespace std;

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

class LinkedList
{
private:
    listNode *head;
    int age;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

public:
    LinkedList()
    {
        head = new listNode;
        head->data = NULL;
        head->next = NULL;
        head->num = 0;
    }

    void ADD(PERSON_INFO *temp);
    void PrintInfo();
    void Delete(listNode *prev_head);
    listNode *Get_Head();
    void Search(listNode *prev_head);
    void Load();
    void Close();
    void Modify(listNode *prev_head);
};

PERSON_INFO *Create_Data();
char *trim(char *str);
void clear_buffer();
listNode *find_end(listNode *first_list);
void issame(listNode *temp_list, listNode *prev);

// listNode *find_end(listNode *first_list);
// void Close(listNode *first_list);
// void ADD(listNode *first_list);
// void Delete(listNode *first_list);
// void PrintInfo(listNode *first_list);
// void Load(listNode *first_list);
// void Modify(listNode *first_list);
// void clear_buffer();
// void is_same(listNode *temp_list, listNode *prev);
// char *trim(char *str);