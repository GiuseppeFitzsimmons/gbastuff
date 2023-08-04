#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    uint64_t** arr = malloc(3 * sizeof(uint64_t *)); // Malloc d'un tableau de pointeurs
    for (uint8_t i = 0; i < 3; i++)
    {
        arr[i] = malloc(4 * 8 * sizeof(uint64_t));
    }

    arr[2][2] = 420;

    uint64_t val = arr[2][2];

    printf("%llu blaze it!\n", val);

    printf("Size comparison: %d\n", sizeof(uint64_t) == sizeof(uint64_t *)); // Sur une archi 64 bits

    printf("Address comparison 1: %d\n", arr[2][2] == *(arr[2] + 2));

    uint64_t * second_row = *(arr + 2);

    printf("Address comparison 2: %d\n" , arr[2][2] == second_row[2]);

    printf("Address comparison 3: %d\n", arr[2][2] == *(*(arr + 2) + 2));
}