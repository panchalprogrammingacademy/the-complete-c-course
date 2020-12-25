#include <stdio.h>
int main() {
    // stores the user's input
    int month, year;
    // accept user's input
    scanf ("%d %d", &month, &year);
    // take decision
    switch (month) {
        case 1: printf ("31\n"); break;
        case 2:
            // depends on leap year! 
            if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))  
                printf ("29\n");
            else
                printf ("28\n");
            break;
        case 3: printf ("31\n"); break;
        case 4: printf ("30\n"); break;
        case 5: printf ("31\n"); break;
        case 6: printf ("30\n"); break;
        case 7: printf ("31\n"); break;
        case 8: printf ("31\n"); break;
        case 9: printf ("30\n"); break;
        case 10: printf ("31\n"); break;
        case 11: printf ("30\n"); break;
        case 12: printf ("31\n"); break;
    }
}