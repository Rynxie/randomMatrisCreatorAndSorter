/*

    Tunahan KAYA
    Akdeniz University
    13.04.2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void matrisCreator(bool typeOfOrder) {
    // Function that creates the matrix. It sorts the elements in ascending or descending order depending on the boolean parameter.
    int theArray[100]; // The array used to sort the elements before creating the matrix
    int theMatris[10][10]; // The matrix that will be created after sorting the array

    for (int i = 0; i < 100; i++) {
        theArray[i] = (rand() % (500 - 100 + 1)) + 100; // Generate random numbers between 100 and 500 and add them to the array
    }

    for (int i = 0; i < 99; i++) { // Bubble sorting algorithm used for sorting the array
        for (int j = 0; j < 99; j++){
            if (typeOfOrder == false) { // If boolean is false, sort the array in ascending order
                if (theArray[j] > theArray[j + 1]) {
                    int temp = theArray[j];
                    theArray[j] = theArray[j + 1];
                    theArray[j + 1] = temp;
                }
            }
            else { // If boolean is true, sort the array in descending order
                if (theArray[j] < theArray[j + 1]) {
                    int temp = theArray[j];
                    theArray[j] = theArray[j + 1];
                    theArray[j + 1] = temp;
                }
            }
        }
    }
    
    for (int row = 0; row < 10; row++) { // Convert the sorted array to a matrix
        for (int  col = 0; col < 10; col++){
            theMatris[row][col] = theArray[(row * 10) + col];
        }
    }

    for (int i = 0; i < 10; i++) { // Print the sorted matrix
        for (int j = 0; j < 10; j++) {
            printf("%d ", theMatris[i][j]);
            if (j == 9) {
                printf("\n");
            }
        }
    }
}

int main()
{
    int userIndex; // Variable that stores the user's selected sorting method
    srand(time(NULL)); // Seed the rand function with the current time
    for (;;) { // Infinite loop to allow the user to make another selection if they make an invalid choice
        printf("Select the sorting order for the matrix:\n");
        printf("1) Ascending\n");
        printf("2) Descending\n");
        scanf("%d", &userIndex); // Read the user's choice
        if (userIndex < 3 && userIndex > 0) {
            break; // If the user enters 1 or 2, break out of the loop and continue with the program
        }
        else {
            printf("Please enter 1 or 2.\n"); // If the user enters an invalid choice, print a warning and continue the loop to read another choice
        }
    }

    switch (userIndex)
    {
        case 1:
            matrisCreator(false); // If the user chooses 1, sort the array in ascending order
            break;
        case 2:
            matrisCreator(true); //If the user chooses 2, sort the array in descending order
			break;
		default:
			break;
	}
}

