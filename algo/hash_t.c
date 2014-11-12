#include <stdio.h>
#include "hash_t.h"

int main(int argc, char **argv) {
    // create a table
    hash_table_t *my_hashtable;
    int size_of_table = 12;
    unsigned int hsh;
    char name[] = "lohe world";
    int added;
    int num_items;
    int deleted;

    my_hashtable = create_hash_table(size_of_table);

    added = add_string(my_hashtable, name);
    printf("\nAdded %s with return code %d\n", name, added);

    hsh = hash(my_hashtable, name);

    printf("The hash of %s is %d\n", "mystring", hsh);

    added = add_string(my_hashtable, name);
    printf("\nAdded '%s' with return code %d\n", name, added);

    num_items = count_strings(my_hashtable); 
    printf("Number of items in hashtable = %d\n", num_items);

    added = add_string(my_hashtable, "Jaworms");
    printf("\nAdded '%s' with return code %d\n", "Jaworms", added);

    num_items = count_strings(my_hashtable); 
    printf("Number of items in hashtable = %d\n", num_items);

    printf("\nDeleting '%s' from hashtable\n", name);
    deleted = delete_string(my_hashtable, name); 
    if (deleted != 0) {
        printf("Error deleting '%s'", name);
    }

    num_items = count_strings(my_hashtable); 
    printf("Number of items in hashtable = %d\n", num_items);

    free_table(my_hashtable);

    return 0;
}
