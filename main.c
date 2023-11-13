#include <stdint.h>
#include <stdio.h>
#include "victor_vector.h"

int main() {
    struct scalable_array lol = create_array();     // 3
                                                    // 1 2 3

    print_elem(get_value(&lol, 1));                 // 2
    printf("\n");
    print_elem(get_length(&lol));                   // 3
    printf("\n");

    resize(&lol, 5);                                // 1 2 3 0 0

    add_back(&lol, 54);                             // 1 2 3 54 0

    optimize(&lol);                                 // 1 2 3 54

    print(&lol);
    destroy(&lol);
    return 0;
}
