#include "personal_cpp.h"
using namespace std;

void LinkedList::Load()
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
        PERSON_INFO *temp_info = new PERSON_INFO;

        if (fread(temp_info, sizeof(PERSON_INFO), 1, fp) != 1)
        {
            break;
        }

        listNode *newlist = new listNode;
        listNode *end = find_end(head);

        newlist->data = temp_info;
        newlist->next = NULL;
        newlist->num = end->num + 1;
        end->next = newlist;
    }
    fclose(fp);
}