#include <stdio.h>


//Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали.




int main() {
	double Console_Matrix[3][3];
	printf("Введите числа для заполения матрицы 3 х 3\n");
	for (int x = 0; x < 3 ; x++){
		for (int y = 0; y < 3; y++){
			printf("Введите элемент [%d][%d]:",x,y);
			scanf("%lf",&Console_Matrix[x][y]);
		}
	}
	
	printf("\nДанный Массив:\n");
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			printf("%.2lf ", Console_Matrix[x][y]);
		}
		printf("\n");
	} 
	
	double main, second;
	main = second = 0;
	
	for (int i = 0; i < 3; i++){
		main += Console_Matrix[i][i];
		second += Console_Matrix[i][2-i];
		
	}
	printf("Сумма элементов главной диагонали: %.2lf\n", main);
	printf("Сумма элементов побочной диагонали: %.2lf\n", second);
	
	return 0;
}




