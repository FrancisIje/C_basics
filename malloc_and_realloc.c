#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate memory for 3 integers
    // malloc - Memory ALLOCation - reserves a block of memory
    // sizeof(int) - gets the size of an integer in bytes (typically 4 bytes)
    // list is a pointer that stores the address of the first byte of allocated memory
    int *list = malloc(3 * sizeof(int));

    // Error checking - if malloc fails, it returns NULL
    if (list == NULL)
    {
        free(list); // free - releases the memory (good practice even if allocation failed)
        return 1;   // Return error code
    }

    // Initialize the array with values
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Resize the memory block to hold 4 integers
    // realloc - RE-ALLOCate - resizes previously allocated memory block
    // It tries to extend the existing block, or finds a new block and copies old data
    // Important: realloc can return a different memory address than the original
    int *tmp = realloc(list, 4 * sizeof(int));

    // Error checking for realloc
    if (tmp == NULL)
    {
        free(tmp); // Free the temporary pointer if realloc failed
        return 1;  // Return error code
    }

    // Point list to the new memory location (in case realloc moved the data)
    list = tmp;

    // Add the fourth element to the resized array
    list[3] = 4;

    // Print all elements to verify
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    };

    // Free the memory to prevent memory leaks
    // Always free what you malloc/realloc
    free(list);

    return 0; // Success
}