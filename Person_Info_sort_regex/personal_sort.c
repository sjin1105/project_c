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

void regex_phone(char *msgbuf)
{
    regex_t regex;
    int reti;

    printf("PHONE : ");
    fgets(msgbuf, MAX_PHONE_LENGTH, stdin);
    msgbuf[strlen(msgbuf) - 1] = '\0';
    clear_buffer();

    reti = regcomp(&regex, "^01([0|1|6|7|8|9])-?([0-9]{3,4})-?([0-9]{4})$", REG_EXTENDED);
    if (reti)
    {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    /* Execute regular expression */
    reti = regexec(&regex, msgbuf, 0, NULL, 0);
    if (!reti)
    {
    }
    else if (reti == REG_NOMATCH)
    {
        puts("Not Phone Number form");
        regex_phone(msgbuf);
    }
    else
    {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        regfree(&regex);
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return;
    }

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
}