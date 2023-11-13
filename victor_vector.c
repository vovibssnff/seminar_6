#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include "victor_vector.h"

size_t get_length(struct scalable_array* arr) {
    return arr->capacity;
}

int64_t get_value(struct scalable_array* arr, size_t i) {
    if (get_length(arr)<i) {
        return 0;
    } else {
        return (arr->val)[i];
    }
}

bool add_back(struct scalable_array* arr, int64_t new) {
    if (arr->capacity==arr->count) {
        return false;
    } else {
        (arr->val)[arr->count] = new;
        arr->count++;
        return true;
    }
}

bool copy(struct scalable_array* patient, struct scalable_array* donor) {
    if (patient->capacity<patient->count+donor->count) {
        return false;
    } else {
        for (size_t i=0; i<donor->count; i++) {
            patient->count++;
            (patient->val)[patient->count] = (donor->val)[i];
        }
        return true;
    }
}

void resize(struct scalable_array* arr, size_t new) {
    arr->val = realloc(arr->val, sizeof(int64_t) * new);
    arr->capacity = new;
}

void optimize(struct scalable_array* arr) {
    arr->val = realloc(arr->val, sizeof(int64_t) * arr->count);
    arr->capacity = arr->count;
}

void destroy(struct scalable_array* arr) {
    free(arr->val);
}


void print_elem(size_t elem) {
    printf("%zu", elem);
    printf(" ");
}

void print(struct scalable_array* arr) {
    
    for (size_t i=0; i<arr->capacity; i++) {
        print_elem((arr->val)[i]);
    }
    printf("\n");
    print_elem(arr->capacity);
    printf("\n");
}

static size_t read_size() { size_t sz = 0; scanf("%zu", &sz); return sz; }

int64_t read_int64() {
    int64_t value;
    scanf("%" SCNd64, &value);
    return value;
}

static void array_int_fill( int64_t* array, size_t sz ) {
    for( size_t i = 0; i < sz; i = i + 1 ) {
        array[i] = read_int64();
    }
}

struct scalable_array create_array() {
    size_t size = read_size();
    if (size > 0) {
        int64_t* array = malloc( sizeof(int64_t) * size);
        array_int_fill( array, size );
        return (struct scalable_array) { .val=array, .capacity=size, .count=size };
    } else return (struct scalable_array) {0};
}



