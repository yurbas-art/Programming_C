#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    char input[1806];
    int year, month, day;

    printf("Enter(YYYY.MM.DD): ");
    scanf("%s", input);

    if (strcmp(input, "now") == 0) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1900;
        month = tm.tm_mon + 1;
        day = tm.tm_mday;
    } else {
        sscanf(input, "%d.%d.%d", &year, &month, &day);
    }

    // Day of the week if enter date
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_hour = 12;
    mktime(&date);// Normalize the structure tm

    printf("\nDay of the week: ");
    switch(date.tm_wday) {
        case 0: printf("Sunday\n"); break;
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
    }

    //calendar for all 12 months
    for (int m = 1; m <= 12; m++) {
        printf("\nCalendar for %d-%02d:\n", year, m);
        printf(" Mo  Tu  We  Th  Fr  Sa  Su\n");

       // find 1st day of mouth and day of the week
        struct tm first_day = {0};
        first_day.tm_year = year - 1900;
        first_day.tm_mon = m - 1;
        first_day.tm_mday = 1;
        first_day.tm_hour = 12;
        mktime(&first_day);

        //correct day of the week
        int first_weekday = (first_day.tm_wday + 6) % 7;

        // fill space in start calendar
        for (int i = 0; i < first_weekday; i++) {
            printf(" -- ");
        }

        // prind day of the mouth
        for (int d = 1; d <= 31; d++) {
            struct tm current = {0};
            current.tm_year = year - 1900;
            current.tm_mon = m - 1;
            current.tm_mday = d;
            current.tm_hour = 12;
            if (mktime(&current) == -1 || current.tm_mon != m - 1) {
                break; // The day does not belong to the current month
            }

            //  select the current day
            if (d == day && m == month) {
                printf("[%2d]", d);
            } else {
                printf(" %2d ", d);
            }

            // Switching to a new line at the end of the week
            if ((first_weekday + d) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}
// links on site
// mktime http://cppstudio.com/post/586/
//https://github.com/irina0519hhhh/programming-C/blob/main/lab%2012
