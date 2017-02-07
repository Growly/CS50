/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 * 
 * Comments: Adrian Arumugam
 * Date: 2016-12-04
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If CLI arguments(argc) are not a length of 2 or 3.
    // 
    // Print out the help statement that points
    // the user in the right direction to using the tool.
    //
    // Return a failure exit code.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Convert string argument for argv[1] to an integer
    int n = atoi(argv[1]);

    // When an initial seed is provided the argc length is 3.
    // Use the seed provided in argv[2] for srand48 which is
    // used to set a seed for drand48 (random number generation function).
    //
    // If argc is not 3 then the seed provided is set to the current time epoch.
    // this ensures different numbers are produced every time.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Iterate through the number of times provides by the user(n)
    //
    // Each iteration calls drand48() with a limit of 65536
    //
    // Print the number generated by drand48 to STDOUT after
    // typecasting to an integer.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}