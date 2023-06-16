#include "personal_cpp.h"

using namespace std;

void LinkedList::Delete(listNode *prev_head)
{
    if (head->next == NULL)
    {
        printf("빈 리스트 입니다.\n");
        return;
    }

    int number = 0;
    int flag = 0;
    listNode *end;
    listNode *cur;
    listNode *ptr;

    cur = head;

    while (cur->next != NULL)
    {
        cur = cur->next;
        printf("번호 : %d\n이름 : %s\n전화번호 : %s\n나이 : %d\n\n", cur->num, cur->data->szName, cur->data->szPhone, cur->data->nAge);
    }
    printf("번호 : ");
    scanf("%d", &number);
    clear_buffer();
    cur = head;

    while (cur->next != NULL)
    {
        if (cur->next->num == number)
        {
            flag = 1;
            ptr = cur->next;
            cur->next = ptr->next;
            delete (ptr);
            while (cur->next != NULL)
            {
                cur->next->num = cur->next->num - 1;
                cur = cur->next;
            }
            break;
        }
        else
        {
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        printf("일치하는 번호가 없습니다.\n");
    }
    if (head->next != NULL)
    {
        end = find_end(prev_head);
        end->next = head->next;
        head->next->num = end->num + 1;
        head = head->next;
        while (head->next != NULL)
        {
            head->next->num = head->num + 1;
            head = head->next;
        }
    }
}

void issame(listNode *temp_list, listNode *prev)
{
    listNode *end;
    listNode *cur;
    listNode *listnew = new listNode;

    end = find_end(temp_list);
    end->next = listnew;
    listnew->data = prev->next->data;
    listnew->next = NULL;
    listnew->num = end->num + 1;
    cur = prev->next;
    prev->next = cur->next;
    free(cur);
    while (prev->next != NULL)
    {
        prev->next->num = prev->next->num - 1;
        prev = prev->next;
    }
}