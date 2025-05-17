#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y) ({\
	double r, res; \
	for(int j = 0; j < y-1; j++){ \
		if(x[j] < x[j+1]){ \
			r = x[j+1];}} \
	res = r; \
	printf("\nresult: %.2lf", res);})

/* Написать программу вычисления максимального числа из 
введенных пользователем в виде одной строки.  
Использовать для этого макрос (без функции), 
на вход которому подается массив чисел и их количество. 
max(x, y)((x > y)?x:y)
((x) >= (y) ? (x) : (y))
#define AVG(arr, n) ({\
int sum = 0; \
for (int i = 0; i < n; i++) { \
sum += arr[i]; \
} \
sum / n; \
})
typeof - ф-я опред. типа даных
понять что такое макрос+
применить знания +
отладить и проверить программу */

int main(){
	int n, i;
	double nums[16], res;
	char s[64];
	const char cu[2] = " ";
	fgets(s, 64 , stdin);
	char *c = strtok(s, cu);
	
	while(c != 0){
		for(i=0; i<16; i++){
			nums[i] = atof(c);
			//printf("%.2f\n", nums[i]);
			c = strtok(0, cu);}}
	for(i=0; ;i++){
        if(nums[i] == '\0'){
			break;}
        n++;}
		//res = max(atof(c), atof(strtok(0, cu)));)}
		
	max(nums, n);
	return 0;}