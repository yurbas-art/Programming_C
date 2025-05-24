#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PEOPLE 100
#define MAX_NAME_LEN 50
#define FILENAME "people.txt"

typedef struct {
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    int birth_year;
    char gender;
    float height;
} Person;

void print_people(Person people[], int count) {
    printf("\n%-15s %-15s %-10s %-6s %s\n",
           "Imya", "Familiya", "God_roj", "Pol", "Rost");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-15s %-10d %-6c %.2f\n",
               people[i].first_name,
               people[i].last_name,
               people[i].birth_year,
               people[i].gender,
               people[i].height);
    }
}

void sort_people(Person people[], int count, int criteria[], int criteria_count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            bool should_swap = false;

            for (int k = 0; k < criteria_count; k++) {
                int cmp = 0;

                switch (criteria[k]) {
                    case 1:
                        cmp = people[j].birth_year - people[j+1].birth_year;
                        break;
                    case 2:
                        cmp = strcmp(people[j].first_name, people[j+1].first_name);
                        break;
                    case 3:
                        cmp = strcmp(people[j].last_name, people[j+1].last_name);
                        break;
                    case 4:
                        cmp = people[j].gender - people[j+1].gender;
                        break;
                    case 5:
                        cmp = (people[j].height > people[j+1].height) ? 1 :
                              (people[j].height < people[j+1].height) ? -1 : 0;
                        break;
                }

                if (cmp > 0) {
                    should_swap = true;
                    break;
                }
                else if (cmp < 0) {
                    should_swap = false;
                    break;
                }
            }

            if (should_swap) {
                Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }
}

int main() {
    Person people[MAX_PEOPLE];
    int count = 0;

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Oshibka: File %s ne nayden\n", FILENAME);
        printf("Ubejdites, chto file nahoditsya v pravilnoy papke\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) && count < MAX_PEOPLE) {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) continue;

        int result = sscanf(line, "%49s %49s %d %c %f",
                            people[count].first_name,
                            people[count].last_name,
                            &people[count].birth_year,
                            &people[count].gender,
                            &people[count].height);

        if (result == 5) {
            people[count].gender = toupper(people[count].gender);
            if (people[count].gender != 'M' && people[count].gender != 'F') {
                printf("Oshibka: Nepravilniy pol v zapisi %d\n", count+1);
                continue;
            }

            count++;
        }
        else {
            printf("Oshibka: Nepravilniy format dannyh v stroke: %s\n", line);
        }
    }
    fclose(file);

    if (count == 0) {
        printf("File pust ili soderzhit oshibki\n");
        return 1;
    }

    printf("Uspeshno zagrujeno %d zapisey:\n", count);
    print_people(people, count);

    printf("\nKriterii sortirovki (vvedite chisla cherez probel):\n");
    printf("1 - God rozhdeniya\n2 - Imya\n3 - Familiya\n4 - Pol\n5 - Rost\n");
    printf("Vvedite kriterii: ");

    char input[100];
    if (!fgets(input, sizeof(input), stdin)) {  // Исправленная строка
        printf("Oshibka pri chtenii vvoda\n");
        return 1;
    }

    int criteria[5] = {0};
    int criteria_count = 0;

    char *token = strtok(input, " \n");
    while (token != NULL && criteria_count < 5) {
        int num = atoi(token);
        if (num >= 1 && num <= 5) {
            criteria[criteria_count++] = num;
        }
        token = strtok(NULL, " \n");
    }

    if (criteria_count == 0) {
        printf("Ne vvedeny kriterii. Po umolchaniyu: god rozhdeniya\n");
        criteria[0] = 1;
        criteria_count = 1;
    }

    sort_people(people, count, criteria, criteria_count);
    printf("\nRezultat sortirovki:\n");
    print_people(people, count);

    return 0;
}
