#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, keylen, msglen, flag = 0;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];

    printf("Enter data: ");
    scanf("%s", input);

    printf("Enter key: ");
    scanf("%s", key);

    keylen = strlen(key);
    msglen = strlen(input);

    strcpy(key1, key);

    /* Append zeros */
    for (i = 0; i < keylen - 1; i++)
    {
        input[msglen + i] = '0';
    }
    input[msglen + keylen - 1] = '\0';

    /* Copy first bits to temp */
    for (i = 0; i < keylen; i++)
    {
        temp[i] = input[i];
    }
    temp[keylen] = '\0';

    /* CRC Calculation */
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];

        if (quot[i] == '0')
        {
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        }
        else
        {
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        }

        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }

        rem[keylen - 1] = input[i + keylen];
        rem[keylen] = '\0';

        strcpy(temp, rem);
    }

    strcpy(rem, temp);

    printf("\nQuotient is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", quot[i]);

    printf("\nRemainder is: ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);

    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", input[i]);

    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);

    printf("\n");

    char temp1[100];

    printf("Enter Received Data: ");
    scanf("%s", temp1);

    for (i = 0; i < keylen; i++)
        temp[i] = temp1[i];

    temp[keylen] = '\0';

    /* Receiver CRC Check */
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];

        if (quot[i] == '0')
        {
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        }
        else
        {
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        }

        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }

        rem[keylen - 1] = temp1[i + keylen];
        rem[keylen] = '\0';

        strcpy(temp, rem);
    }

    strcpy(rem, temp);

    printf("\nQuotient is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", quot[i]);

    printf("\nRemainder is: ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);

    flag = 0;
    for (i = 0; i < keylen - 1; i++)
    {
        if (rem[i] == '1')
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("\nNo Error\n");
    else
        printf("\nError is detected\n");

    return 0;
}