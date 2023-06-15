#include "personal.h"

void Sort(listNode *first_list)
{
    listNode *cur;
    listNode *temp;
    int flag = 0;
    while (flag == 0)
    {
        flag = 1;
        cur = first_list;

        while (1)
        {

            if (cur->next->data->nAge > cur->next->next->data->nAge)
            {
                flag = 0;
                temp = cur->next;
                cur->next = cur->next->next;
                temp->next = cur->next->next;
                cur->next->next = temp;
            }
            cur = cur->next;
            if (cur->next->next == NULL)
            {
                break;
            }
        }
    }
    cur = first_list;
    while (1)
    {
        cur->next->num = cur->num + 1;
        cur = cur->next;

        if (cur->next == NULL)
        {
            break;
        }
    }
}