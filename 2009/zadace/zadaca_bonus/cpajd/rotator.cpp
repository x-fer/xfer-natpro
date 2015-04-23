#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
const char *abeceda = "abcèædðefghijklmnopqrs¹tuvwxyz¾";
const int len = strlen( abeceda );
int rot;

void ispisi( char c ) {
  for( int i = 0; i < len; ++i ) 
    if( c == abeceda[i] ) {
      putchar( abeceda[ (i+rot)%len ] );
      return;
    }
    else if( tolower( c ) == abeceda[i] ) {
      putchar( toupper( abeceda[ (i+rot)%len ] ) );
      return;
    }
  putchar( c );
}

int main( int argc, char *argv[] ) {
  char c;
  rot = 1;
  
  while( ( c = getchar() ) != -1 )
    ispisi( c );
  
  return 0;
}
