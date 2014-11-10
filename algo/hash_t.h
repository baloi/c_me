#include <string.h>
#include <stdlib.h>

// Taken from: www.sparknotes.com/cs/searching/hashtables/section3.rhtml
// Linked list structure
// typedef allows you to declare instances of a struct without using
// the keyword "struct"
typedef struct _list_t_ {
    // a pointer to a char?
    char *string;
    // a pointer to a structure of type _list_t_
    struct _list_t_ *next;
} list_t;

// Hash table structure
typedef struct _hash_table_t_ {
    int size;        // the size of the table    
    list_t **table;  // the table of elements
} hash_table_t;

/* 
 * Why did we make the table as list_t **table? We do not know up front how big
 * we want the table to be. Therefore we need to make the table a dynamic array
 * . Remember that an array is just a big block of memory and is basically
 * synonymous with a pointer. What we have is a pointer to a pointer to a
 * linked list; thus list_t **table.
 */

// basic operations:
// 1. create a table
// 2. be able to hash, thus a hash function
// 3. be able to free a table
// 4. be able to insert into table
// 5. be able to lookup an element

hash_table_t * create_hash_table(int size) {
    int i;
    hash_table_t *new_table;

    if (size < 1) return NULL; /* invalid size for table */

    /* Attempt to allocate memory for the table structure */
    if ( (new_table = malloc(sizeof(hash_table_t))) == NULL) {
        return NULL;
    }

    /* Attempt to allocate memory for the table itself */
    if ( (new_table->table = malloc(sizeof(list_t *) * size)) == NULL) {
        return NULL;
    }

    /* Initializes the elements of the table */
    for (i=0; i < size; i++) {
        new_table->table[i] = NULL;
    }

    /* set the table's size */
    new_table->size = size;

    return new_table;
}

/*
 * Now for a simple hash function
 */
unsigned int hash(hash_table_t *hashtable, char *str) {
    unsigned int hashval;

    /* we start our hash out at 0 */
    hashval = 0;

    /* for each character, we multiply the old hash by 31 and add the current
     * character. Remember that shifting a number left is equivalent to
     * multiplying it to 2 rasied to the number of places shifted. So we 
     * are in effect multiplying hashval by 32 and then subtracting hashval.
     * Why do we do this? Because shifting and subtraction are much more 
     * efficient operations than multiplication.
     */
    for(; *str != '\0'; str++) {
        hashval = *str + (hashval << 5) - hashval;
    }

    /* We then return the hash value mod the hashtable size so that it will
     * fit into the necessary range
     */
    return hashval % hashtable->size;
}


/* Freeing up memory for the table we created */
void free_table(hash_table_t *hashtable) {
    int i;
    list_t *list, *temp;

    if (hashtable == NULL) return;

    /* Free memory for every item in the table, including the strings
     * themselves
     */
    for (i=0; i < hashtable->size; i++) {
        list = hashtable->table[i];
        while(list != NULL) {
            temp = list;
            list = list->next;
            free(temp->string);
            free(temp);
        }
    }

    /* Free the table itself */
    free(hashtable->table);
    free(hashtable);
}

/* String lookup. Doing a string lookup is as simple as hashing the string,
 * going to the correct index in the array, and then doing a linear search
 * on the linked list that resides there.
 */

list_t *lookup_string(hash_table_t *hashtable, char *str) {
    list_t *list;
    unsigned int hashval = hash(hashtable, str);

    /* Go to the correct list based on the hash value and see if str is in the
     * list. If it is, return a pointer to the list element. If it isn't, the 
     * item isn't in the table so return NULL.
     */
    for(list = hashtable->table[hashval]; list != NULL; list = list->next) {
        if (strcmp(str, list->string) == 0) {
            return list;
        }
    }

    return NULL;
}

/* 
 * Inserting a string. Almost like looking up a string.
 * Hash the string. Go to the correct place in the array. Insert the new
 * string at the beginning.
 */
int add_string(hash_table_t *hashtable, char *str) {
    list_t *new_list;
    list_t *current_list;;
    
    unsigned int hashval = hash(hashtable, str);

    /* Attempt to allocate memory for list */
    if ( (new_list = malloc(sizeof(list_t))) == NULL) {
        return 1;
    }

    /* Does item already exist? */
    current_list = lookup_string(hashtable, str);

    /* Item already exists, dont insert it again */
    if (current_list != NULL) {
        return 2;
    }

    /* Insert into list */
    new_list->string = strdup(str);
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;

    return 0;
}


