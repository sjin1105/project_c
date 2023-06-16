#include "personal.h"

void Load(listNode *first_list)
{
    listNode *end;
    FILE *fp = NULL;

    printf("\n\n* System : Data Loading...\n");

    if ((fp = fopen("data.txt", "rb")) == NULL)
    {
        printf("\nERROR : Cannot Open Data File\n");
        return;
    }
    int count = 0;

    while (1)
    {
        PERSON_INFO *temp_info = (PPERSON_INFO)malloc(sizeof(PERSON_INFO));
        if (temp_info == NULL)
        {
            printf("malloc error\n");
            return;
        }
        memset(temp_info, 0, sizeof(PERSON_INFO));

        if (fread(temp_info, sizeof(PERSON_INFO), 1, fp) != 1)
        {
            break;
        }

        listNode *listnew = (listNode *)malloc(sizeof(listNode));
        if (listnew == NULL)
        {
            printf("malloc error\n");
            return;
        }
        memset(listnew, 0, sizeof(listNode));

        end = find_end(first_list);
        end->next = listnew;
        listnew->data = temp_info;
        listnew->next = NULL;
    }
    fclose(fp);
    Sort(first_list);
}