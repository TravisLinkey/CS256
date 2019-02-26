#include <stdio.h>
#include <math.h>

void display_menu();
int get_input();
void calculate_circle();

void calculate_triangle();

void calculate_rectangle();

int main() {
	int input;

    do
    {
        display_menu();
        input = get_input();
        printf("\n");
    }
    while(input != 4);

    printf("Have a day\n");

	return 0;
}

void display_menu() {
	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n");
}

int get_input() {
    int ans;

    printf("Please enter an integer between 1-4.\n");
    fflush(stdout);
    scanf("%d", &ans);

    switch (ans) {

        case 1:
            calculate_circle();
            break;
        case 2:
            calculate_rectangle();
            break;
        case 3:
            calculate_triangle();
            break;
        case 4:
            return ans; //quit
        default:
            return 0;
    }

}

void calculate_rectangle() {
    float length, width;
    printf("Please enter the length and width of the rectangle.\n");
    printf("length = ");
    scanf("%1f", &length);
    printf("width = ");
    scanf("%1f", &width);
    printf("The area of the rectangle is: %f\n", length*width);
}

void calculate_triangle() {
    float base, height;
    printf("Please enter the base and height of the triangle.\n");
    printf("base = ");
    scanf("%1f", &base);
    printf("height = ");
    scanf("%1f", &height);
    printf("The area of the square is: %f\n", base * height * .5);
}

void calculate_circle() {
        float rad;
        printf("Please enter the radius of the circle.\n");
        scanf("%8f", &rad);
        printf("The area of the circle is: %f\n", (3.14159 * pow(rad,2)));
    }

