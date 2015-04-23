
/*
DMIH 2004 - Prvi dan natjecanja
Srednjoskolska skupina - I. podskupina
Zadatak EDITOR
*/

#include <cstdio>
#include <stack>

using namespace std;

stack<char> lijevo, desno;
char buff[100002];
int n;

int main( void ) {
  gets( buff );
  scanf( "%d", &n );

  for( char *c = buff; *c; c++ ) lijevo.push( *c );

  for( int i = 0; i < n; ++i ) {
    scanf( "%s", buff );
    if( buff[0] == 'L' ) {
      if( lijevo.empty() ) continue;
      desno.push( lijevo.top() );
      lijevo.pop();
    }
    if( buff[0] == 'D' ) {
      if( desno.empty() ) continue;
      lijevo.push( desno.top() );
      desno.pop();
    }
    if( buff[0] == 'B' ) {
      if( lijevo.empty() ) continue;
      lijevo.pop();
    }
    if( buff[0] == 'P' ) {
      scanf( "%s", buff );
      lijevo.push( buff[0] );
    }
  }

  while( !lijevo.empty() ) {
    desno.push( lijevo.top() );
    lijevo.pop();
  }
  while( !desno.empty() ) {
    printf( "%c", desno.top() );
    desno.pop();
  }
  printf( "\n" );

  return 0;
}
