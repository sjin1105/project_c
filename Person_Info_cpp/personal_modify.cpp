#include "personal_cpp.h"
using namespace std;

void LinkedList::Modify(listNode *prev_head)
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
            while (1)
            {
                printf("변경될 이름 : ");
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
            printf("변경될 전화번호 : ");
            fgets(phone, MAX_PHONE_LENGTH, stdin);
            phone[strlen(phone) - 1] = '\0';
            clear_buffer();

            while (1)
            {
                printf("변경될 나이 : ");
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

            strcpy(cur->next->data->szName, name);
            strcpy(cur->next->data->szPhone, phone);
            cur->next->data->nAge = age;
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