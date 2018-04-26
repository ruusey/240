#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bool.h"
#include "../include/alist.h"

#define SIZE 20

typedef unsigned int uint;

uint NUM_ERRORS = 0;

typedef struct box box_t;
struct box {
    uint item;
    uint tag;
};

void* mod_box(void* a_box);
bool last_three_quarters(void* a_box);
bool tag_too_big(void* a_box);
uint  randrange(uint);

uint  (*valid_rand)(void);
uint* rand_arr(int size);
void  print_box_lst(alist_t *lst);
void  init_rand(void);

int main() {
    init_rand();

    uint *tagof = rand_arr(SIZE);

    alist_t *lst = alalloc();

    { // --- Test Push ---
        uint i;
        for (i = 0; i < SIZE; i++) {
            box_t *new_box = malloc(sizeof(box_t));
            new_box->item = i;
            new_box->tag = tagof[i];
            push(lst, new_box);
        }
    }

    { // Shuffle again
        uint i;
        for (i = SIZE - 1; i > 1; i--) {
            uint j = randrange(i);
            lst->arr[i] = (void*) ((uintptr_t) lst->arr[j] ^ (uintptr_t) lst->arr[i]);
            lst->arr[j] = (void*) ((uintptr_t) lst->arr[i] ^ (uintptr_t) lst->arr[j]);
            lst->arr[i] = (void*) ((uintptr_t) lst->arr[i] ^ (uintptr_t) lst->arr[j]);
        }
    }

    // Copy the list.
    box_t *els[SIZE];
    {
        uint i;
        for (i = 0; i < SIZE; i++) {
            els[i] = lst->arr[i];
        }
    }

    // --- Test Pop ---
    int pre_pop_len = lst->len;
    {
        uint i;
        for (i = 0; i < 3 * SIZE / 4; i++) {
            if (pre_pop_len != lst->len) {
                printf("ERROR: Invalid Resize\n");
                NUM_ERRORS++;
            }
            box_t *popped = pop(lst);
            if (els[SIZE - i - 1] != popped) {
                printf("ERROR: `pop' did not return the last element.\n");
                NUM_ERRORS++;
            }
        }
    }
    int post_pop_len = lst->len;
    printf("Tagged List\n-----------\n");
    print_box_lst(lst);
    if (pre_pop_len != 2*post_pop_len) {
        printf("ERROR:\n");
        printf("\nBefore: size=%u, len=%u\n", pre_pop_len, pre_pop_len);
        printf("After: size=%u, len=%u\n\n", 2*post_pop_len, 2*post_pop_len);
        NUM_ERRORS++;
    }

    // --- Test Find ---
    box_t *exists = find(lst, last_three_quarters);
    box_t *not_exists = find(lst, tag_too_big);

    if (exists == NULL) {
        printf("ERROR: find returned NULL, but a value was expected\n");
        NUM_ERRORS++;
    } else if (exists->tag != tagof[exists->item]) {
        printf("ERROR: find did not return the original object.\n");
        NUM_ERRORS++;
    }

    if (not_exists != NULL) {
        printf("ERROR: find returned a value, but NULL was expected\n");
        NUM_ERRORS++;
    }

    // --- Test Map ---
    map(lst, mod_box);
    printf("\n");
    printf("Mapped & Tagged List\n--------------------\n");
    print_box_lst(lst);

    uint i;
    for (i = 0; i < lst->size; i++) {
        box_t *box = lst->arr[i];
        if (tagof[box->item - 1] != box->tag + 1) {
            printf("ERROR: `map' failed to apply the function correctly.\n");
            NUM_ERRORS++;
        }
    }

    printf("\n");

    if (NUM_ERRORS == 0) {
        printf("All checks passed.\n");
    } else {
        printf("%u errors encountered.\n", NUM_ERRORS);
    }

    return 0;
}

// increments item, decrements tag
void* mod_box(void* a_box) {
    box_t* actually_a_box = a_box;
    actually_a_box->item++;
    actually_a_box->tag--;
    return actually_a_box;
}

bool last_three_quarters(void* a_box) {
    box_t* actually_a_box = a_box;
    return actually_a_box->item > SIZE / 4 - 1;
}

bool tag_too_big(void* a_box) {
    box_t *actually_a_box = a_box;
    return actually_a_box->tag > SIZE;
}

void init_rand() {
   valid_rand=rand;
}

uint randrange(uint max) {
    while (true) {
        int value = valid_rand();
        if (value < RAND_MAX - RAND_MAX % max) {
            return value % max;
        }
    }
}

uint* rand_arr(int size) {
    // Generate a tag scheme
    uint *tagof = malloc(sizeof(uint) * size);
    { // Generate {1..size}
        int i;
        for (i = 0; i < size; i++) {
            tagof[i] = i;
        }
    }
    {
        uint i;
        for (i = size - 1; i > 1; i--) {
            uint j = randrange(i);
            tagof[i] = tagof[j] ^ tagof[i];
            tagof[j] = tagof[i] ^ tagof[j];
            tagof[i] = tagof[i] ^ tagof[j];
        }
    }
    return tagof;
}

void print_box_lst(alist_t *lst) {
    int i;
    box_t *elem = lst->arr[0];
    printf("{ (%3d, t=%-3d)", elem->item, elem->tag);
    for (i = 1; i < lst->size; i++) {
        elem = lst->arr[i];
        printf("\n, (%3d, t=%-3d)", elem->item, elem->tag);
    }
    printf("\n}\n");
}
