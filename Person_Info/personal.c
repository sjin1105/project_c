#include "personal.h"

int main(void)
{
    listNode *first_list = (listNode *)malloc(sizeof(listNode));
    if (first_list == NULL)
    {
        printf("malloc error\n");
        return 0;
    }
    memset(first_list, 0, sizeof(listNode));

    first_list->next = NULL;
    first_list->num = 0;
    int choice_num;

    Load(first_list);

    while (1)
    {
        choice_num = 0;
        printf("\n===================== MENU =====================\n");
        printf("1. ADD\n");
        printf("2. DELETE\n");
        printf("3. MODIFY\n");
        printf("4. PRINT\n");
        printf("5. EXIT\n");

        printf("* Select Num. : ");
        scanf("%d", &choice_num);
        clear_buffer();
        switch (choice_num)
        {
        case MENU_ADD:
            ADD(first_list);
            break;

        case MENU_DELETE:
            Delete(first_list);
            break;

        case MENU_MODIFY:
            Modify(first_list);
            break;

        case MENU_SHOW:
            PrintInfo(first_list);
            break;

        case MENU_EXIT:
            Close(first_list);
            return 0;

        default:
            printf("\n* System : Invalid Num.\n");
            break;
        }
    }
    return 0;
}

void clear_buffer()
{
    while (getchar() != '\n')
        ;
}

void Close(listNode *first_list)
{
    listNode *tmp;
    PERSON_INFO *cur;
    tmp = first_list->next;
    FILE *pfile;
    FILE *ppfile;
    if ((pfile = fopen("data.txt", "wb")) == NULL)
    {
        printf("\nERROR : Cannot Open Data File\n");
        return;
    }
    while (tmp != NULL)
    {
        cur = tmp->data;
        if (fwrite(cur, sizeof(PERSON_INFO), 1, pfile) != 1)
        {
            printf("Write Fail\n");
            return;
        }
        tmp = tmp->next;
    }
    fclose(pfile);

    while (first_list->next != NULL)
    {
        tmp = first_list;
        first_list = first_list->next;
        free(tmp);
    }

    // NOTE print save data
    // if ((ppfile = fopen("data.txt", "rb")) == NULL)
    // {
    //     printf("\nERROR : Cannot Open Data File\n");
    //     return;
    // }

    // PERSON_INFO *temp_info = (PPERSON_INFO)malloc(sizeof(PERSON_INFO));
    // if (temp_info == NULL)
    // {
    //     printf("malloc error");
    //     exit(1);
    // }
    // memset(temp_info, 0, sizeof(PERSON_INFO));

    // while (fread(temp_info, sizeof(PERSON_INFO), 1, ppfile) == 1)
    // {
    //     printf("%s\n", temp_info->szName);
    //     printf("%s\n", temp_info->szPhone);
    //     printf("%d\n", temp_info->nAge);
    // }
    // fclose(ppfile);
    // free(temp_info);
}