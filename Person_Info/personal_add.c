#include "personal.h"

void ADD(listNode *first_list)
{
    int age;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    listNode *end;
    end = find_end(first_list);
    listNode *listnew = (listNode *)malloc(sizeof(listNode));
    if (listnew == NULL)
    {
        printf("malloc error");
        return;
    }
    memset(listnew, 0, sizeof(listNode));

    PERSON_INFO *newNode = (PERSON_INFO *)malloc(sizeof(PERSON_INFO));
    if (newNode == NULL)
    {
        printf("malloc error");
        return;
    }
    memset(newNode, 0, sizeof(PERSON_INFO));

    while (1)
    {
        printf("NAME : ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        if (strlen(name) == 1)
        {
            printf("이름은 비어있을수 없습니다.");
            clear_buffer();
        }
        else
        {
            name[strlen(name) - 1] = '\0';
            clear_buffer();
            break;
        }
    }

    printf("PHONE : ");
    fgets(phone, MAX_PHONE_LENGTH, stdin);
    phone[strlen(phone) - 1] = '\0';
    clear_buffer();

    printf("AGE : ");
    scanf("%d", &age);
    clear_buffer();

    strcpy(newNode->szName, name);
    strcpy(newNode->szPhone, phone);
    newNode->nAge = age;
    listnew->data = newNode;
    listnew->next = NULL;
    listnew->num = end->num + 1;
    end->next = listnew;
}

listNode *find_end(listNode *first_list)
{
    listNode *cur;
    cur = first_list;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return (cur);
}