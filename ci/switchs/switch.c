
#include <stdio.h>

int main()
{
    // Switch Statement
    int day = 7;

    switch (day)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("Looking forward to the Weekend");
    }
    printf("---------------\n");

    // While Loop
    int i = 0;

    while (i < 5)
    {
        printf("%d\n", i);
        i++;
    }
    printf("---------------\n");

    // countdown
    int countdown = 3;

    while (countdown > 0)
    {
        printf("%d\n", countdown);
        countdown--;
    }

    printf("Happy New Year!!\n");
    printf("---------------\n");

    int dice = 1;

    while (dice <= 6)
    {
        if (dice < 6)
        {
            printf("No Yatzy\n");
        }
        else
        {
            printf("Yatzy!\n");
        }
        dice = dice + 1;
    }
    printf("---------------\n");
    // Do/While Loop
    int v = 0;

    do
    {
        printf("%d\n", v);
        v++;
    } while (v < 5);
    printf("---------------\n");

    //  For Loop
    int is;

    for (is = 0; is < 5; is++)
    {
        printf("%d\n", is);
    }
    printf("---------------\n");

    int k, j;

    // Outer loop
    for (k = 1; k <= 2; ++k)
    {
        printf("Outer: %d\n", k); // Executes 2 times

        // Inner loop
        for (j = 1; j <= 3; ++j)
        {
            printf(" Inner: %d\n", j); // Executes 6 times (2 * 3)
        }
    }
    printf("---------------\n");
    int number = 2;
    int t;

    // Print the multiplication table for the number 2
    for (t = 1; t <= 10; t++)
    {
        printf("%d x %d = %d\n", number, t, number * t);
    }
    printf("---------------\n");

    // This example jumps out of the for loop when i is equal to 4
    int iss;

    for (iss = 0; iss < 10; iss++)
    {
        if (iss == 4)
        {
            break;
        }
        printf("%d\n", iss);
    }
    printf("---------------\n");

    // skips the value of 4:
    int ic;

    for (ic = 0; ic < 10; ic++)
    {
        if (ic == 4)
        {
            continue;
        }
        printf("%d\n", ic);
    }
    printf("---------------\n");

    // This example jumps out of the for loop when i is equal to 4
    int ik = 0;

    while (ik < 10)
    {
        if (ik == 4)
        {
            break;
        }
        printf("%d\n", ik);
        ik++;
    }
    printf("---------------\n");
    // skips the value of 4:
    int ix = 0;

    while (ix < 10)
    {
        if (ix == 4)
        {
            ix++;
            continue;
        }
        printf("%d\n", ix);
        ix++;
    }
    return 0;
}