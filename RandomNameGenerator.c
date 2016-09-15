/*
	Author: Edgar Han
	Generates a random name by selecting random
	prefix and random suffix
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXBUFLEN 512

// ========================= FUNCTIONS

static char * randSelection( char * buf, char *input[], int size );
static char * genRandName( char * buf );
static void diep(char *s);
static int Driver();

// ========================= GLOBAL VARIABLES
static char *_prefix[] = { "big", "little", "fat", "skinny", "pink", "super", "invisible", "raging", "savage", "one-eyed", "king", "dumb", "mystical", "hype", "light", "blue", "golden" };
static char *_suffix[] = { "shark", "dog", "cat", "pig", "whale", "man", "woman", "pirate", "programmer", "ballzak", "mario", "princess", "koopa", "ninja", "truck", "falcon" };
static int _prefixSize = 17;
static int _suffixSize = 16;

int main()
{

    Driver();

    return 0;
}

int Driver()
{
    char buf[MAXBUFLEN];
    while (1){
        printf( "%s", genRandName(buf) );
        scanf("%s", buf);
    }
}

// Produce error message and exit program
void diep(char *s)
{
    // if error, quit with error.
    perror(s);
    exit(1);
}

char * randSelection( char * buf, char *input[], int size )
{
    int randomNumber = (rand() % (size));
    sprintf(buf, "%s", input[randomNumber]);
    return buf;
}
char * genRandName( char * buf )
{
    char pre[MAXBUFLEN], suf[MAXBUFLEN];
    sprintf( pre, "%s", randSelection(pre, _prefix, _prefixSize) );
    sprintf( suf, "%s", randSelection(suf, _suffix, _suffixSize) );
    sprintf( buf, "%s %s", pre, suf);
    return buf;
}
