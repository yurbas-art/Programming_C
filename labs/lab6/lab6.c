#include <stdio.h>

int main(){
    int year1 = 1980;
    FILE*input;
    FILE*output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    if (input == NULL || output == NULL) {
        printf("Ошибка открытия файла.");
        return 1;
    }
    
    char buffer[100];
    while((fgets(buffer, 100, input))!=NULL) {
        int year; char name[50];
        sscanf(buffer, "%s %*s %*s %*s %d", name, &year);
        if (year > year1){
            printf("%s", buffer);
            fprintf(output, buffer);
        }
    } fclose(input); fclose(output);
    getchar();
    return 0;

}
