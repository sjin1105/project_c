#include "personal_cpp.h"

// #define print_data
using namespace std;
int main(void)
{
    int choice_num;
    LinkedList firstlist;

    firstlist.Load();

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
            firstlist.ADD(Create_Data());
            break;

        case MENU_DELETE:
        {
            LinkedList TempList;
            TempList.Search(firstlist.Get_Head());
            TempList.Delete(firstlist.Get_Head());
            break;
        }

        case MENU_MODIFY:
        {
            LinkedList TempList;
            TempList.Search(firstlist.Get_Head());
            TempList.Modify(firstlist.Get_Head());
            break;
        }

        case MENU_SHOW:
            firstlist.PrintInfo();
            break;

        case MENU_EXIT:
            firstlist.Close();
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

listNode *LinkedList::Get_Head()
{
    return head;
}

void LinkedList::Close()
{
    listNode *tmp;
    PERSON_INFO *cur;
    tmp = head->next;
    FILE *pfile;
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

    while (head->next != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}