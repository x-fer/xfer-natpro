/*
	Koristenje: server input log output. Input je ulazna datoteka,
	server zapisuje detaljan log u log, a rezultat u output.
*/

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
using namespace std;

#define MINMN		3
#define MAXMN		1000000000
#define MAXCOMMANDS 1000

#define SOLUTIONCOMMAND		"rjesenje"
#define EXAMINECOMMAND		"ispitaj"

int N = 0, M = 0;
int Xc = 0, Yc = 0, Rc = 0;

bool isInside ( int X, int Y );


int main( int argc, char *argv[] )
{
	assert( argc == 4 );

	ifstream finput( argv[1] );
	ofstream flog( argv[2] );
	ofstream foutput( argv[3] );

	assert( !finput.fail() && !flog.fail() && !foutput.fail() );

	if ( !( finput >> N >> M >> Xc >> Yc >> Rc ) ) 
	  {
	    flog << "Invalid input file: error reading N, M, Xc, Yc, Rc" << endl;
	    foutput << 0 << endl << "Invalid input file." << endl;
	    exit(1);
	  }

	if ( N < MINMN || N > MAXMN )
	  {
	    flog << "Invalid input file: N must be between " << MINMN << " and " << MAXMN << "." << endl;
	    foutput << 0 << endl << "Invalid input file." << endl;
	    exit(1);
	  }
	
	if ( M < MINMN || M > MAXMN )
	  {
	    flog << "Invalid input file: M must be between " << MINMN << " and " << MAXMN << "." << endl;
	    foutput << 0 << endl << "Invalid input file." << endl;
	    exit(1);
	  }
	
	if( Rc < 1 ) {
	  flog << "Invalid input file: radius R must be greater than zero." << endl;
	  foutput << 0 << endl << "Invalid input file." << endl;
	  exit(1);
	}

	if( Xc+Rc < 1 || Xc+Rc > N || Yc+Rc < 1 || Yc+Rc > M ) {
	  flog << "Invalid input file: circle must completely be inside the meadow." << endl;
    exit(1);
	}
	
	string crap;
	if ( finput >> crap ) 
	{
	  flog << "Invalid input file: too much data (after the 5 input numbers)!" << endl;
	  foutput << 0 << endl << "Invalid input file." << endl;
	  exit(1);
	}

	flog << "Input file parsed successfully." << endl;
	
	// output N M
	cout << N << " " << M << endl;
	fflush(stdout);

	int commands = 0;
	while ( 1 ) 
	  {
	    string command; int X = 0, Y = 0, R = 0;
	    
	    if ( !(cin >> command >> X >> Y) ) 
	      {
          flog << "Program terminated before outputting solution." << endl;
          foutput << 0 << endl << "Program terminated before outputting solution." << endl;
          exit(0);
	      }
	    
	    if ( command == SOLUTIONCOMMAND ) 
	      {
          if( !(cin >> R) ) {
            flog << "Program terminated before outputting solution." << endl;
            foutput << 0 << endl << "Program terminated before outputting solution." << endl;
            exit(0);
          }
	      
          flog << "solution " << X << " " << Y << " " << R << " => " << endl;		

          if ( (X == Xc) && (Y == Yc) && (R == Rc) )
            {
              flog << "Correct! (" << commands << " commands)" << endl;
              foutput << "1" << endl
                << "Correct! (" << commands << " commands)" << endl;
              exit(0);
            }
          else 
            {
              flog << "Wrong." << endl;
              foutput << "0" << endl   
                << "Received answer (" << X << ", " << Y << ", " << R << ") after " << commands << " commands, correct center cell is (" << Xc << ", " << Yc << ", " << Rc << ")." << endl;
              exit(0);
            }
          
          return 0;
	      }
	    else if ( command == EXAMINECOMMAND )
	      {
          flog << "examine " << X << " " << Y << " => ";
          
          if ( ++commands > MAXCOMMANDS ) 
            {
              flog << "Too many commands (" << commands-1 << ")." << endl;
              foutput << "0" << endl
                << "Too many commands (" << commands-1 << ")." << endl;
              exit(0);
            }
          
          if ( X < 1 || X > N || Y < 1 || Y > M )
            {
              flog << "cell is not in the meadow!" << endl;
              foutput << "0" << endl
                << "Examined cell (" << X << ", " << Y << ") which is not inside the meadow!" << endl;
              exit(0);
            }
          
          if ( isInside( X, Y ) )
            {
              flog << "unutra" << endl;
              cout << "unutra" << endl;
              fflush(stdout);
            }
          else
            {
              flog << "vani" << endl;
              cout << "vani" << endl;
              fflush(stdout);
            }
	      }
	    else
	      {
          flog << "Unknown command ('" << command << "')." << endl;
          foutput << 0 << endl << "The program used an unknown command ('" << command << "')." << endl;
          exit(0);
	      }
	  }
	
	return 0;
}

bool isInside ( int X, int Y )
{
  return (((long long)X-Xc)*(X-Xc) + ((long long)Y-Yc)*(Y-Yc) <= ((long long)Rc)*Rc);
}
