#include <stdio.h>
#include <ctype.h>



int main(){
    char name_str[81];
    int i = 0;
    
    printf("Введите строку символов произвольной длины(до 80):");
    scanf("%81[^\n]", name_str);
    
    while(name_str[i] != '\0'){
        name_str[i] = toupper(name_str[i]);
        i++;
    }
    
    printf("Заглавные буквы: %s\n", name_str);
    
    return 0;
}
