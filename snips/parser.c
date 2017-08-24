#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token {
    char type;
    char string[MAXTOKENLEN];
};

/** Globals!?!??! **/
int top=-1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[ top-- ]
#define push(s) stack[ ++top ]=s

enum type_tag classify_string(void) {
    /* figure out the identifier type */
    char *s = this.string;
    if ( !strcmp( s,"const")) {
        strcpy( s,"read-only");
        return QUALIFIER;
    }

    if ( !strcmp( s,"volatile")) return QUALIFIER;
    if ( !strcmp( s,"void")) return TYPE;
    if ( !strcmp( s,"char")) return TYPE;

    if ( !strcmp( s,"signed")) return TYPE;
    if ( !strcmp( s,"unsigned")) return TYPE;
    if ( !strcmp( s,"short")) return TYPE;

    if ( !strcmp( s,"int")) return TYPE;
    if ( !strcmp( s,"long")) return TYPE;
    if ( !strcmp( s,"float")) return TYPE;
    if ( !strcmp( s,"double")) return TYPE;
    if ( !strcmp( s,"struct")) return TYPE;
    if ( !strcmp( s,"union")) return TYPE;
    if ( !strcmp( s,"enum")) return TYPE;

    return IDENTIFIER;
}

void gettoken(void) {
    char *p = this.string;
    
    /* read past any spaces */
    while (( *p = getchar()) == ' ');

    if ( isalnum( *p)) {
        /* it starts with A-Z, 0-9 read in identifier */
        while ( isalnum( *++p = getchar()));

        ungetc( *p, stdin);
        *p = '\0';
        this.type=classify_string();
        return;
    }

    if ( *p == '*') {
        strcpy( this.string, "pointer to");
        this.type = '*';
        return;
    }

    this.string[1] = '\0';
    this.type = *p;
    return;
}

void read_to_first_identifier() {

    gettoken();

    while ( this.type != IDENTIFIER) {
        push( this);
        gettoken();
    }
    printf("%s is ", this.string);
    gettoken();

}

void deal_with_arrays(void) {

}


int main(void) {
    read_to_first_identifier();

    /*
    deal_with_declarator();
    printf("\n");
    */
    return 0;
}
