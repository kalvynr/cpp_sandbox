// In this challenge, write a program that takes in three arguments, a start
// temperature (in Celsius), an end temperature (in Celsius) and a step size.
// Print out a table that goes from the start temperature to the end temperature,
// in steps of the step size; you do not actually need to print the final
// end temperature if the step size does not exactly match. You should perform
// input validation: do not accept start temperatures less than a lower limit
// (which your code should specify as a constant) or higher than an upper
// limit (which your code should also specify). You should not allow a step
// size greater than the difference in temperatures

// Sample run:
// Please give in a lower limit, limit >= 0: 10
// Please give in a higher limit, 10 > limit <= 50000: 20
// Please give in a step, 0 < step <= 10: 4
//
//  Celsius         Fahrenheit
//  -------         ----------
//  10.000000       50.000000
//  14.000000       57.200000
//  18.000000       64.400000

#include <iostream>

using namespace std;

int main()
{
    double lower, upper, step;
    const double LOWER_LIMIT = 0.0f;
    const double UPPER_LIMIT = 50000.0f;
    const double LOWER_STEP = 0.0f;
    const double UPPER_STEP = 10.0f;
    const double CELSIUS_TO_FARENHEIT_CONVERSION_MULTIPLIER = 1.8f;
    const double CELSIUS_TO_FARENHEIT_CONVERSION_ADDITION = 32.0f;

    do
    {
        cout << "Please give in a lower limit, limit >= 0:";
        cin >> lower;
    } while(lower < LOWER_LIMIT);

    do
    {
        cout << "Please give in a higher limit, 10 > limit <= 50000:";
        cin >> upper;
    } while(upper > UPPER_LIMIT);

    do
    {
        cout << "Please give in a step, 0 < step <= 10:";
        cin >> step;
    } while((step < LOWER_STEP) || (step > UPPER_STEP));

    cout << "Celsius\tFahrenheit" << endl;
    cout << "-------\t----------" << endl;
    while (lower <= upper)
    {
        printf("%.4f\t%.4f\n", lower, lower * CELSIUS_TO_FARENHEIT_CONVERSION_MULTIPLIER + CELSIUS_TO_FARENHEIT_CONVERSION_ADDITION);
        lower += step;
    }
}