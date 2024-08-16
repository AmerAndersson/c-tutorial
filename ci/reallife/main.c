#include <stdio.h>

//  Real-Life
int calculateArea(int length, int width);
// Different data types to calculate and output the total cost of a number of items:
int calculateTotalCost(int items, float cost_per_item, char currency);

int main()
{
    // Create integer variables
    int length = 4;
    int width = 6;

    int area = calculateArea(length, width);
    // Print the variables
    printf("Area of the rectangle is: %d\n", area);
    printf("----------------------------\n");

    // Create variables of different data types
    int items = 50;
    float cost_per_item = 9.99;
    char currency = '$';

    float total_cost = calculateTotalCost(items, cost_per_item, currency);

    // Print variables
    printf("Number of items: %d\n", items);
    printf("Cost per item: %.2f %c\n", cost_per_item, currency);
    printf("Total cost = %.2f %c\n", total_cost, currency);
    printf("----------------------------\n");

    // Set the maximum possible score in the game to 500
    int maxScore = 500;

    // The actual score of the user
    int userScore = 420;

    // Calculate the percantage of the user's score in relation to the maximum available score
    float percentage = (float)userScore / maxScore * 100.0;

    // Print the percentage
    printf("User's percentage is %.2f\n", percentage);
    printf("----------------------------\n");

    // Check whether the user enters the correct code:
    int doorCode = 1337;

    if (doorCode == 1337)
    {
        printf("Correct code.\nThe door is now open.\n");
    }
    else
    {
        printf("Wrong code.\nThe door remains closed.\n");
    }
    printf("----------------------------\n");
    // A variable with some specific numbers
    int numbers = 12345;

    // A variable to store the reversed number
    int revNumbers = 0;

    // Reverse and reorder the numbers
    while (numbers)
    {
        // Get the last number of 'numbers' and add it to 'revNumber'
        revNumbers = revNumbers * 10 + numbers % 10;
        // Remove the last number of 'numbers'
        numbers /= 10;
    }
    // Output the reversed numbers
    printf("%d\n", revNumbers);
    printf("----------------------------\n");

    // An array storing different ages
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};

    float avg, sum = 0;
 
    // Get the length of the array
    int lengths = sizeof(ages) / sizeof(ages[0]);

    // Loop through the elements of the array and accumulate the sum
    for (int i = 0; i < lengths; i++)
    {
        sum += ages[i];
    }

    // Calculate the average by dividing the sum by the length
    avg = sum / lengths;

    // Print the average
    printf("The average age is: %.2f", avg);

    return 0;
}

int calculateArea(int length, int width)
{
    // Calculate the area of a rectangle
    return length * width;
}

// Different data types to calculate and output the total cost of a number of items:
int calculateTotalCost(int items, float cost_per_item, char currency)
{
    return items * cost_per_item;
}