#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void *my_malloc(size_t size);

void *my_malloc(size_t size) {
    void *p = sbrk(0);
    /* srbk syscall returns a pointer to the current top of the heap.
     * srbk(0) returns a pointer to the current top of the heap, increments
     * the heap size by foo and returns a pointer to the previous top of the
     * heap.
     */
    void *request = sbrk(size);

    if (request == (void*) -1) {
        return NULL; // srbk failed
    }  else {
        assert( p == request); // not thread safe.
        return p;
    }
}
