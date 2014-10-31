#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    // rows is an array of Addresses
    // Each item in a row is an Address
    struct Address rows[MAX_ROWS];
};

// A Connection would have a pointer to a file
// and a pointer to a Database 'db' which has
// rows of addresses
struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}


void Database_load(struct Connection *conn)
{
    //@TODO: read up on fread()
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);

    if(rc != 1) die("Failed to load database.");
}


struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));

    if(!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;

}


void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}


int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename=argv[1];
    char action = argv[2][0];

    struct Connection *conn = Database_open(filename, action);

    Database_close(conn);

    return 0;
}
