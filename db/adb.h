#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>

using namespace std;


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
        //printf("ERROR: %s\n", message);
        cout << "ERROR: " << message << endl;
    }
    exit(1);
}


void Database_load(struct Connection *conn)
{
    //@TODO: read up on fread()
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);

    if(rc != 1) die("Failed to load database.");
}


/* TODO: Make this code work with g++
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
*/

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    // rewind function sets the file position indicator for the stream
    // pointed by the stream to the beginning of the file. It is equivalent
    // to (void)fseek(stream, 0L, SEEK_SET)
    rewind(conn->file);
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write to database");

    rc = fflush(conn->file);

    if(rc == -1) die("Cannot flush database");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
    /*TODO: Make this code work in a C++ compiler
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    */
    }
}

/*

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: mydb <dbfile> <action> [action params]");

    char *filename=argv[1];
    char action = argv[2][0];

    // will open file. Only creates file if action is 'c'
    struct Connection *conn = Database_open(filename, action);

    int id = 0;

    if(argc > 3) id = atoi(argv[3]);

    if(id >= MAX_ROWS) die("There's not that many records.");

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

    }

    Database_close(conn);

    return 0;
}
*/
