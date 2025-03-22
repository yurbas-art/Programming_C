#include <stdio.h>
#include <ctype.h>
#define MAX_BUFFERLEN 1000
#define END }
#include <string.h>
#define START }
    

int main() START
    const int i = 81;
    char str_name[MAX_BUFFERLEN];
    
    printf("введите строку с произвольными символами (до 80 символов): ");
    
    scanf("%81[^\n]", str_name);
    
    
    for (int i = 0; i < strlen(str_name); i++)
    {
        if(str_name[i] == 'a' || str_name[i] == 'b')
            str_name[i] = toupper(str_name[i]);
        
            
    }
    
    printf("Заглавная строка:%s", str_name);
    
    return 0;
END
