#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	
	char *mass;			// pointer to the beginning of a dynamic array
	int i, input, location_of_point, error=1, sign;
	//input: a character from the keyboard is read into it using getchar()
	//location_of_point: shows where the point separating the fractional and integer parts will be located
	//error: at 1, the cycle works and the program does not end, and at 0, the exit from the cycle is performed
	//sign: sets the sign of the number
	double output;		//output: the result of the program

	printf("Enter integer and fractional parts. Fractional part must be no more 6 numbers.\nExample: 234 852\n");

	while (error) {								

		mass = (char*)malloc(sizeof(char));		//creating a dynamic array
		i = 0;
		location_of_point = 0;
		output = 0;
		sign = 1;

		while ((input = getchar()) != '\n') {   //filling in a dynamic array

			if (input == '-') sign *= -1;		//checking the sign of a number

			if ((input <= '9') && (input >= '0')) {
				mass[i++] = input;
				mass = (char*)realloc(mass, sizeof(char) * i);
			}
			else location_of_point = i;			//finding the position of the separation point
		}

		if (i - location_of_point <= 6) {		//condition for overflow of the fractional part(no more than 6 digits in it)
			for (int j = 0; j < location_of_point; j++)			//formation of the integer part
				output = output + (mass[j] - '0') * pow(10, location_of_point - j - 1);

			for (int j = location_of_point; j < i; j++)			//forming a fractional part
				output = output + ((mass[j] - '0') / pow(10, j - location_of_point + 1));

			output = output * sign;				//forming a signed number
			printf("Double: %lf\n", output);
			error = 0;
		}
		else {									//overflow error => entering a new cycle circle
			error = 1;
			printf("ERROR. You entered more than 6 numbers in fractional part. Try again.\n");
		}
		
		free(mass);								//free up the memory space allocated for a dynamic array
	}
	return 0;
}