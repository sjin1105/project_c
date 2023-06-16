#include "personal.h"

void PrintInfo(listNode *first_list)
{
    listNode *cur;
    cur = first_list->next;

    if (cur != NULL)
    {
        while (1)
        {
            printf("번호 : %d\n이름 : %s\n전화번호 : %s\n나이 : %d\n\n", cur->num, cur->data->szName, cur->data->szPhone, cur->data->nAge);
            if (cur->next == NULL)
            {
                printf("data end\n");
                break;
            }
            else
            {
                cur = cur->next;
            }
        }
    }
    else
    {
        printf("No DATA\n");
    }
}