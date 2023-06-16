#include "personal.h"

void Modify(listNode *first_list)
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;
    int number = 0;
    int flag = 0;
    listNode *end;
    listNode *prev;
    listNode *cur;
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

            if (strcmp(prev->next->data->szName, name) == 0)
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

            if (strcmp(prev->next->data->szPhone, phone) == 0)
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
        break;
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
    if (temp_list->next != NULL)
    {
        end = find_end(prev);
        end->next = temp_list->next;
        temp_list->next->num = end->num + 1;
        temp_list = temp_list->next;
        while (temp_list->next != NULL)
        {
            temp_list->next->num = temp_list->num + 1;
            temp_list = temp_list->next;
        }
    }
}