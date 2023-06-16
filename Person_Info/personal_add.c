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
        printf("malloc error\n");
        return;
    }
    memset(newNode, 0, sizeof(PERSON_INFO));

    while (1)
    {
        printf("NAME : ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        strcpy(name, trim(name));
        if (strlen(name) == 0)
        {
            printf("이름은 비어있을수 없습니다.\n");
            clear_buffer();
        }
        else
        {
            clear_buffer();
            break;
        }
    }

    printf("PHONE : ");
    fgets(phone, MAX_PHONE_LENGTH, stdin);
    phone[strlen(phone) - 1] = '\0';
    clear_buffer();

    while (1)
    {
        printf("AGE : ");
        scanf("%d", &age);
        clear_buffer();
        if ((age < 0) | (age > 200))
        {
            printf("나이는 0이상 200이하여야 합니다.\n");
        }
        else
        {
            break;
        }
    }

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

char *trim_left(char *str)
{
    while (*str)
    {
        if (isspace(*str))
        {
            str++;
        }
        else
        {
            break;
        }
    }
    return str;
}

char *trim_right(char *str)
{
    int len = (int)strlen(str) - 1;

    while (len >= 0)
    {
        if (isspace(*(str + len)))
        {
            len--;
        }
        else
        {
            break;
        }
    }
    *(str + ++len) = '\0';
    return str;
}

char *trim(char *str)
{
    return trim_left(trim_right(str));
}