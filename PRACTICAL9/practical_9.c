/*
Assume that you have a seven-slot closed hash
table (the slots are numbered 0 through 6) Write program to final hash table
that would result if you used the hash function h(k) = k mod 7.
*/

#include <stdio.h>

#define TABLE_SIZE 7

int main() {
    int hash_table[TABLE_SIZE];
    int keys[] = {4, 32, 90, 1, 7, 54, 11};
    int n = sizeof(keys) / sizeof(keys[0]);
    int i, key, index;

    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
    }

    printf("Inserting keys using linear probing:\n");

    for (i = 0; i < n; i++) {
        key = keys[i];
        index = key % TABLE_SIZE;

        while (hash_table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }
        
        hash_table[index] = key;
        printf("Inserted %d (hash %d) at slot %d\n", key, key % TABLE_SIZE, index);
    }

    printf("\nFinal Hash Table (Slots 0-6):\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: %d\n", i, hash_table[i]);
    }

    return 0;
}

/*
Sample Output:

*/
