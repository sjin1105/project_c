#include "personal_cpp.h"

using namespace std;

void LinkedList::Search(listNode *prev_head)
{
    listNode *prev = prev_head;
    listNode *temp_list = head;

    int choice_num = 0;

    if (prev->next == NULL)
    {
        printf("빈 리스트 입니다.\n");
        return;
    }

    printf("검색 옵션\n1. 이름\n2. 전화번호\n3. 나이\n* Select Num. : ");
    scanf("%d", &choice_num);
    clear_buffer();

    switch (choice_num)
    {
    case MENU_NAME:
        printf("NAME : ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strlen(name) - 1] = '\0';
        clear_buffer();

        while (1)
        {

            if (strcmp(prev->next->data->szName, name) == 0)
            {
                issame(temp_list, prev);
            }
            else
            {
                prev = prev->next;
            }
            if (prev->next == NULL)
            {
                break;
            }
        }
        break;

    case MENU_PHONE:
        printf("PHONE : ");
        fgets(phone, MAX_NAME_LENGTH, stdin);
        phone[strlen(phone) - 1] = '\0';
        clear_buffer();

        while (1)
        {

            if (strcmp(prev->next->data->szPhone, phone) == 0)
            {
                issame(temp_list, prev);
            }
            else
            {
                prev = prev->next;
            }
            if (prev->next == NULL)
            {
                break;
            }
        }
        break;

    case MENU_AGE:
        printf("나이 : ");
        scanf("%d", &age);
        clear_buffer();

        while (1)
        {

            if (prev->next->data->nAge == age)
            {
                issame(temp_list, prev);
            }
            else
            {
                prev = prev->next;
            }
            if (prev->next == NULL)
            {
                break;
            }
        }
        break;

    default:
        printf("\n* System : Invalid Num.\n");
        break;
    }
    head = temp_list;
}