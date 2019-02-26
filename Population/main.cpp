#include <stdlib.h>

double calculate_population(int p,float b,float d, int n);

int get_starting_size() ;
int get_number_of_years() ;
float get_birth_rate();
float get_death_rate();

int main() {

    int starting_population = get_starting_size();
    float annual_birthrate = get_birth_rate();
    float annual_deathrate = get_death_rate();
    int number_of_years = get_number_of_years();
    
    double new_pop = calculate_population(starting_population, annual_birthrate, annual_deathrate, number_of_years);
    printf("The new population in %d year(s) is: %.2f\n", number_of_years, new_pop);

    return 0;
}
double calculate_population(int p, float b, float d, int n) {
    return n*(p+(b*p)-(d*p));
}
int get_starting_size() {
    int starting_population;

    do{
        printf("Enter the starting size of the population.\n");
        scanf("%d", &starting_population);
    }while(starting_population < 2);

    return starting_population;
}
int get_number_of_years() {
    int number_of_years = 0;

    do
    {
        printf("Enter the number of years to display.\n");
        scanf("%d", &number_of_years);
    }while(number_of_years < 1);

    return number_of_years;
}
float get_birth_rate() {
    float annual_birthrate = 0;

    do{
        printf("Enter annual birth rate.\n");
        scanf("%f", &annual_birthrate);
    }while(annual_birthrate < 0);

    return annual_birthrate;
}
float get_death_rate() {
    float annual_deathrate = 0;

    do{
        printf("Enter annual death rate.\n");
        scanf("%f", &annual_deathrate);
    }while(annual_deathrate < 0);

    return annual_deathrate;
}
