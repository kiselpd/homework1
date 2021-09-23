#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	
	char *mass;			// указатель на начало динамического масива
	int i, input, location_of_point, error=1, sign;
	//input: в неё с помощью getchar() считывается символ с клавиатуры
	//location_of_point: показывает на каком месте будет находиться точка, разделяющая дробную и целую части
	//error: при единицы цикл работает и программа не заканчивается, а при 0 выполняется выход из цикла
	//sign: проверяет положительно или отрицательно число
	double output;		//output: число, которое получается в конце программы

	printf("Enter integer and fractional parts. Fractional part must be no more 6 numbers.\nExample: 234 852\n");

	while (error) {								

		mass = (char*)malloc(sizeof(char));		//создание динамического масива
		i = 0;
		location_of_point = 0;
		output = 0;
		sign = 1;

		while ((input = getchar()) != '\n') {   //заполнение динамического масива

			if (input == '-') sign = -1;		//проверка какого знака число

			if ((input <= '9') && (input >= '0')) {
				mass[i++] = input;
				mass = (char*)realloc(mass, sizeof(char) * i);
			}
			else location_of_point = i;			//поиск позиции точки разделения
		}

		if (i - location_of_point <= 6) {		//условие на переполнение дробной части(не больше 6 цифр в ней)
			for (int j = 0; j < location_of_point; j++)			//формирование целой части
				output = output + (mass[j] - '0') * pow(10, location_of_point - j - 1);

			for (int j = location_of_point; j < i; j++)			//формирование дробной части
				output = output + ((mass[j] - '0') / pow(10, j - location_of_point + 1));

			output = output * sign;				//формирование числа с знаком
			printf("Double: %lf\n", output);
			error = 0;
		}
		else {									//ошибка переполнения => заход на новый круг цикла
			error = 1;
			printf("ERROR. You entered more than 6 numbers in fractional part. Try again.\n");
		}
		
		free(mass);								//освобождает место в памяти, выделенное под динамический масив
	}
	return 0;
}