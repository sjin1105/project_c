#include "personal.h"

void Delete(listNode *first_list)
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;
    int number = 0;
    int flag = 0;
    listNode *end;
    listNode *prev;
    listNode *cur;
    listNode *ptr;
    listNode *temp_list = (listNode *)malloc(sizeof(listNode));

    if (temp_list == NULL)
    {
        printf("malloc error");
        return;
    }
    memset(temp_list, 0, sizeof(listNode));
    temp_list->next = NULL;
    temp_list->num = 0;

    int choice_num = 0;
    prev = first_list;

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

            if (strstr(prev->next->data->szName, name) != NULL)
            {
                is_same(temp_list, prev);
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

            if (strstr(prev->next->data->szPhone, phone) != NULL)
            {
                is_same(temp_list, prev);
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
                is_same(temp_list, prev);
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
        return;
    }
    cur = temp_list;
    if (cur->next == NULL)
    {
        printf("일치하는 사람이 없습니다.\n");
        return;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
        printf("번호 : %d\n이름 : %s\n전화번호 : %s\n나이 : %d\n\n", cur->num, cur->data->szName, cur->data->szPhone, cur->data->nAge);
    }
    printf("번호 : ");
    scanf("%d", &number);
    clear_buffer();
    cur = temp_list;

    while (cur->next != NULL)
    {
        if (cur->next->num == number)
        {
            flag = 1;
            ptr = cur->next;
            cur->next = ptr->next;
            free(ptr);
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

    end = find_end(prev);
    end->next = temp_list->next;
    free(temp_list);

    Sort(first_list);
}

void is_same(listNode *temp_list, listNode *prev)
{
    listNode *end;
    listNode *cur;
    listNode *listnew = (listNode *)malloc(sizeof(listNode));

    if (listnew == NULL)
    {
        printf("malloc error\n");
        return;
    }
    memset(listnew, 0, sizeof(listNode));

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