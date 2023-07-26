#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Receiver: framed_data -> original data
int receiver()
{
    char data[50][50], framed_data[50][50];
    int k = 0, len = 0, i = 0;
    char esc[] = "esc", flag[] = "flag", temp[50];
    int check = 0; // check determines whether esc is on or off while inputting framed data

    printf("Enter the frame values: ");    // input framed data
    scanf("%s", temp);                     // below procedure is to validate framed data
    if (strcmp(temp, flag) != 0 && i == 0) // if first word is not flag, terminate function
    {
        printf("Framed data must start with flag\n");
        goto end;
    }
    strcpy(framed_data[i], temp); // otherwise, word copied
    len++;                        // length of framed_data incremented

    for (i = 1; i < 50; i++) // for every word
    {
        scanf("%s", temp);                           // read word
        if ((strcmp(temp, flag) == 0) && check == 0) // if word is flag and esc is off, input complete
            break;
        else if ((strcmp(temp, flag) == 0) && check == 1) // if word is flag and esc is on, turn off esc
            check = 0;
        else if (strcmp(temp, esc) == 0) // if word is esc: if esc is on, turn off esc; if esc is off, turn on esc
            check = !check;
        else if (check == 1 && (strcmp(temp, esc) != 0 && strcmp(temp, flag) != 0)) // if esc is on and word is not esc or flag, invalid input-> terminate function
        {
            printf("Invalid framed data.\n");
            goto end;
        }
        strcpy(framed_data[i], temp); // copy word
        len++;                        // increment len
    }

    for (i = 1; i < len; i++) // iterate through framed data; skip framed_data[0] i.e. flag
    {
        if (strcmp(framed_data[i], esc) != 0)  // if word is anything other then esc
            strcpy(data[k++], framed_data[i]); // copy word as it is
        else
        {
            i++;                               // else skip esc
            strcpy(data[k++], framed_data[i]); // copy next word
        }
    }

    printf("Original data: "); // print original data
    for (i = 0; i < k; i++)
        printf("%s ", data[i]);
end:
    printf("\n\n");
}

// Function to perform byte stuffing
int sender()
{
    char framed_data[50][50], data[50][50];
    int k = 0, len, i;

    char flag[] = "flag", esc[] = "esc";

    printf("Enter length of String : "); // input length of string
    scanf("%d", &len);
    printf("Enter the String: "); // input string
    for (i = 0; i <= len; i++)
        gets(data[i]);

    strcpy(framed_data[k++], flag); // start with flag
    for (i = 1; i <= len; i++)      // iterate through data
    {
        if (strcmp(data[i], flag) != 0 && strcmp(data[i], esc) != 0) // if word is not flag or esc
            strcpy(framed_data[k++], data[i]);                       // copy as it is
        else
        {
            strcpy(framed_data[k++], esc);     // else insert esc word first
            strcpy(framed_data[k++], data[i]); // then copy word
        }
    }
    strcpy(framed_data[k++], flag);       // end with flag
    printf("Data after Byte stuffing: "); // print framed data
    for (i = 0; i < k; i++)
        printf("%s ", framed_data[i]);
    printf("\n\n");
}

int main()
{
    int c; // menu driven code
    while (1)
    {
        printf("Bytes stuffing\nMenu:\n1. Transmitter\n2. Receiver\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            sender();
            break;
        case 2:
            receiver();
            break;
        case 3:
            exit(0);
        default:
            printf("Enter valid choice.\n");
            break;
        }
    }
    return 0;
}
