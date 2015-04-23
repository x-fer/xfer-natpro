#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
  fstream solt(argv[2]);
  fstream soln(argv[3]);
  
  int moje, njihovo;

  solt >> moje;
  if(!(soln >> njihovo)) {
    cout << "0" << endl << "Krivo formatiran ispis!" << endl;
    return 0;
  }

  string trash;
  if(soln >> trash) {
    cout << "0" << endl << "Krivo formatiran ispis!" << endl;
    return 0;
  }

  if(njihovo < 0) {
    cout << "0" << endl << "Krivo - dobiven rezultat je negativan broj." << endl;
    return 0;
  }

  if(moje == njihovo)
    cout << "1" << endl << "Tocno rjesenje!" << endl;
  else if(moje > njihovo) {
    double bodovi = pow((double)njihovo/moje, 2.0);
    printf("%.2lf\nSuboptimalno - dobiven rezultat je %d, a optimalno je %d.\n", bodovi, njihovo, moje );
  } else if(moje < njihovo) 
    cout << "0" << endl << "Krivo - dobiven rezultat veci je od sluzbenog." << endl;
  
  solt.close();
  soln.close();

  return 0;
}


