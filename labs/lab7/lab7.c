#include <stdio.h>


#define SIZE 89

// Объявление структуры humen
struct humen {
    char name[50];
    char surname[50];
    int birthYear;
};
int comparefirstletter(char a,char b) {
    if (a >= 'A' && a <= 'Z') a = a;
    if (b >= 'A' && b <= 'Z') b = b;
    return a > b;
}

// Функция для сортировки массива по первой букве
void sortByFirstLetter(struct humen arr[], int size) {
    struct humen temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (comparefirstletter(arr[j].name[0], arr[j+1].name[0])) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    struct humen people[SIZE];
    struct humen sortedPeople[SIZE];

    // Открываем файл для чтения
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("can`t open in.txt\n");
        return 1; // Завершаем программу, если файл не открыт
    }

    // Чтение данных из файла в массив people
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%s %s %d", people[i].name, people[i].surname, &people[i].birthYear);
    }

    // Закрываем файл
    fclose(file);

    // Копируем данные в массив sortedPeople
    for (int i = 0; i < SIZE; i++) {
        sortedPeople[i] = people[i];
    }

    // Сортируем массив sortedPeople по годам рождения
    sortByFirstLetter(sortedPeople, SIZE);

    // Вывод результатов
    printf("\n sorted by first letter in name:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("name: %s, surname: %s, birthYear: %d\n",
               sortedPeople[i].name, sortedPeople[i].surname, sortedPeople[i].birthYear);
    }

    return 0;
}
