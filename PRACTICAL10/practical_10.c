/*Aim:
Write a C program that copies the contents of one file to a
destination file. This program will read data from one file ("input.txt")
and copy them to another ("output.txt").
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *source_filename = "input.txt";
    const char *dest_filename = "output.txt";

    FILE *source = fopen(source_filename, "r");
    if (!source) {
        perror("Failed to open source file");
        return 1;
    }

    FILE *dest = fopen(dest_filename, "w");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(source);
        return 1;
    }

    int ch;
    while ((ch = getc(source)) != EOF) {
        putc(ch, dest);
    }

    printf("Copied contents from '%s' to '%s'.\n", source_filename, dest_filename);

    fclose(source);
    fclose(dest);
    return 0;
}

/*
Output:

(First, create 'input.txt' with the content:
My Name is Kshitij
This is a test file.
)

After running the program:

Sample Output:
Copied contents from input.txt to output.txt.

(This will create a new file 'output.txt' with the exact same content
as 'input.txt'.)
*/
