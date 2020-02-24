
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SZ 1024
#define PROG_SZ 512

struct mbas_prog {
   size_t sz;
   char code[];
};

void mbas_compile( struct mbas_prog* prog, const char* line ) {

}

int main( void ) {
   FILE* bas_file = NULL;
   char* line = NULL;
   size_t line_len = 0;
   ssize_t rcount = 0;
   struct mbas_prog* prog = NULL;

   prog = calloc( sizeof( struct mbas_prog ) + PROG_SZ, 1 );
   prog->sz = PROG_SZ;
   
   bas_file = fopen( "test.mbs", "r" );
   while( 0 <= (rcount = getline( &line, &line_len, bas_file )) ) {
      mbas_compile( prog, line );
   }

   fclose( bas_file );

	return 0;
}

