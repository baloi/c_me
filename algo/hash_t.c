#include <stdio.h>
#include "hash_t.h"

int main(int argc, char **argv) {
    // create a table
    hash_table_t *my_hash_table;
    int size_of_table = 12;
    unsigned int hsh;
    char name[] = "lohe world";
    int added;

    my_hash_table = create_hash_table(size_of_table);

    added = add_string(my_hash_table, name);
    printf("Added %s with return code %d\n", name, added);

    hsh = hash(my_hash_table, name);

    printf("The hash of %s is %d\n", "mystring", hsh);

    added = add_string(my_hash_table, name);
    printf("Added %s with return code %d\n", name, added);
    free_table(my_hash_table);

    return 0;
}
