#include <stdio.h>

struct humen{
    char name[20];
    char surname[20];
    int age;
};

int main(){
    int i, j, n = 4;
    struct humen arr1[n], arr2[n];
    FILE*input = fopen("input7.txt", "r");
    char buffer[128];
    for (i = 0; i < n; i++){
        fgets(buffer, 100, input);
        sscanf(buffer, "%s %s %d", &arr1[i].name, &arr1[i].surname, &arr1[i].age);
    }
    for (i = 0; i < n; i++) arr2[i] = arr1[i];

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1 - i; j++) {
            if (arr2[j].age > arr2[j + 1].age) {
                struct humen buffer = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = buffer;
            }
        }
    }
    printf("Отсортированный список:\n");
    for (i = 0; i<n; i++) printf("%d. %s %s %d\n", i+1, arr2[i].name, arr2[i].surname, arr2[i].age);

    return 0;
}
