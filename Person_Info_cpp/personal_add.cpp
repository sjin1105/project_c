#include "personal_cpp.h"

using namespace std;

void LinkedList::ADD(PERSON_INFO *temp)
{
    listNode *newlist = new listNode;
    listNode *end = find_end(head);

    newlist->data = temp;
    newlist->next = NULL;
    newlist->num = end->num + 1;
    end->next = newlist;
}

PERSON_INFO *Create_Data()
{
    PERSON_INFO *temp = new PERSON_INFO;
    int age;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
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
    strcpy(temp->szName, name);
    strcpy(temp->szPhone, phone);
    temp->nAge = age;
    return temp;
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

char *trim(char *str)
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