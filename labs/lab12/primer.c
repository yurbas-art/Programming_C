#include <stdio.h>
#include <time.h>
#include <string.h>

void print_month_calendar(int year, int month, int highlight_day) {
    printf("\nCalendar for %d-%02d:\n", year, month);
    printf(" Mo  Tu  We  Th  Fr  Sa  Su\n");

    // Находим первый день месяца и день недели
    struct tm first_day = {0};
    first_day.tm_year = year - 1900;
    first_day.tm_mon = month - 1;
    first_day.tm_mday = 1;
    first_day.tm_hour = 12;
    mktime(&first_day);

    // Корректируем день недели (0 - понедельник, 6 - воскресенье)
    int first_weekday = (first_day.tm_wday + 6) % 7;

    // Заполняем пробелы в начале календаря
    for (int i = 0; i < first_weekday; i++) {
        printf("    ");
    }
    // Печатаем дни месяца
    for (int d = 1; d <= 31; d++) {
        struct tm current = {0};
        current.tm_year = year - 1900;
        current.tm_mon = month - 1;
        current.tm_mday = d;
        current.tm_hour = 12;
        if (mktime(&current) == -1 || current.tm_mon != month - 1) {
            break; // День не принадлежит текущему месяцу
        }
        // Выделяем текущий день, если он совпадает с highlight_day
        if (d == highlight_day && month == first_day.tm_mon + 1) {
            printf("[%2d]", d);
        } else {
            printf(" %2d ", d);
        }
        // Переход на новую строку в конце недели
        if ((first_weekday + d) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char input[1806];
    int year, month, day;

    printf("Enter year (YYYY) or date (YYYY.MM.DD) or 'now': ");
    scanf("%s", input);

    if (strcmp(input, "now") == 0) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        year = tm.tm_year + 1900;
        month = tm.tm_mon + 1;
        day = tm.tm_mday;
    } else if (strchr(input, '.') != NULL) {
        // Введена дата в формате YYYY.MM.DD
        sscanf(input, "%d.%d.%d", &year, &month, &day);
    } else {
        // Введен только год
        sscanf(input, "%d", &year);
        month = -1; // Флаг, что месяц не указан
        day = -1;   // День тоже не указан
    }

    // Если введена полная дата, выводим день недели
    if (month != -1 && day != -1) {
        struct tm date = {0};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        date.tm_hour = 12;

        mktime(&date); // Нормализуем структуру tm

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
    }

    // Выводим календарь на все 12 месяцев
    printf("\nYearly calendar for %d:\n", year);
    for (int m = 1; m <= 12; m++) {
        // Если был указан конкретный день, выделяем его в соответствующем месяце
        print_month_calendar(year, m, (m == month) ? day : -1);
    }

    return 0;
}
