#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	
	char *mass;
	int i, input, location_of_point, error=1, sign;
	double output;

	printf("Enter integer and fractional parts. Fractional part must be no more 6 numbers.\nExample: 234 852\n");

	while (error) {

		mass = (char*)malloc(sizeof(char));
		i = 0;
		location_of_point = 0;
		output = 0;
		sign = 1;

		while ((input = getchar()) != '\n') {

			if (input == '-') sign = -1;

			if ((input <= '9') && (input >= '0')) {
				mass[i++] = input;
				mass = (char*)realloc(mass, sizeof(char) * i);
			}
			else location_of_point = i;
		}

		if (i - location_of_point <= 6) {
			for (int j = 0; j < location_of_point; j++)
				output = output + (mass[j] - '0') * pow(10, location_of_point - j - 1);

			for (int j = location_of_point; j < i; j++)
				output = output + ((mass[j] - '0') / pow(10, j - location_of_point + 1));

			output = output * sign;
			printf("Double: %lf\n", output);
			error = 0;
		}
		else {
			error = 1;
			printf("ERROR. You entered more than 6 numbers in fractional part. Try again.\n");
		}
		
		free(mass);
	}
	return 0;
}