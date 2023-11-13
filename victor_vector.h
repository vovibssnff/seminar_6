#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

struct scalable_array;

int64_t get_value(struct scalable_array*, size_t);
size_t get_length(struct scalable_array*);
bool add_back(struct scalable_array*, int64_t);
bool copy(struct scalable_array*, struct scalable_array*);
void resize(struct scalable_array*, size_t);
void optimize(struct scalable_array*);
void destroy(struct scalable_array*);
void print(struct scalable_array*);
struct scalable_array create_array();
void print_elem(size_t);

struct scalable_array {
    int64_t* val;
    size_t capacity;
    size_t count;
};
