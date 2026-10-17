// Task-2-1-en.c : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    unsigned int a; // Lower safe reading limit
    unsigned int b; // Upper safe reading limit
    unsigned int n; // Interference level readings
    unsigned int c = 0; // Safe reading counter
    unsigned int d = 0; // Variable for storing the length of the section where readings are safe
    unsigned int m; // local maximum length of the section where readings are safe.
    unsigned int max_len = 0; // maximum length of the section where readings are safe. Final result.
    // Data input
    printf("Enter the safe reading limits\r\n");
    printf("Lower limit: ");
    scanf("%u", &a);
    printf("Upper limit: ");
    scanf("%u", &b);
    printf("Enter the orbital station sensor readings\r\n");
    printf("0 - end of data input\r\n");
    scanf("%u", &n); // Enter the first interference level value
    while (n != 0) // Enter readings until the value is not equal to 0.
    {
        if ((n >= a) && (n <= b)) // safe reading condition
        {
            c++; // Increment the safe reading counter
        }
        else
        {
            d = c; // If readings are dangerous, remember the number of safe ones
            c = 0; // and reset the counter.
        }
        /* determine the maximum length of the section
        where readings are safe. If the counter was reset
        (the safe data chain was interrupted), then the maximum length
        will be the old counter value (variable "d").
        Otherwise, the current (new) counter value
        (variable "c"). Intermediate result*/
        if (d > c)
        {
            m = d;
        }
        else
        {
            m = c;
        }
        // Maximum length of the interval where readings are safe.
        // Final answer.
        if (m > max_len)
        {
            max_len = m;
        }
        scanf("%d", &n); // Input the next portion of data
    }
    // Display information on the screen.
    printf("Length of the interval where all readings are safe: %u\r\n",max_len);
    // Delay displaying until the "Enter" key is pressed
    getchar();
    getc(stdin);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
