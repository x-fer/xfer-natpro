// StarryNight.c    by Artur Miguel Dias/1998

#include <stdio.h>

/* maxSize=100*100, maxClusters=500, maxShapes=26, maxClusterSize=100 */

#define false		0
#define true		1
#define maxMap		100
#define maxShapes	30

typedef struct { int x, y ; } Pt ;

char map[maxMap][maxMap] ; // the Map
Pt size ;			// the Map's size
Pt minP, maxP ;		// info on the current cluster
int nStars ;		// info on the current cluster
struct {
	char name ;		// identification of the shape
	Pt start[8] ;	// start points for cluster comparison
	int nStars ;	// number of stars in this shape
	int num ;		// number of clusters with this shape (for debugging)
} shapes[maxShapes] ;
// arrows: the neighbourhood of each point in relative coordinates
Pt arrows[] = {{ 1, 0},{ 1, 1},{ 0, 1},{-1, 1},{-1, 0},{-1,-1},{ 0,-1},{ 1,-1}} ;

#define set(p,n)	( map[p.y][p.x] = n )

int get(Pt p) {
	if( p.x < 0 || p.x >= size.x || p.y < 0 || p.y >= size.y )
		return '0' ;
	else return map[p.y][p.x] ;
}

// Walks one unit in the direction "arrow" using the co-ordinate
// system represented by "rotSym". The values of "rotSym" range from 0 to 7
// and have the following meanings:
//		0=0 1=90 1=180 3=270 4=0s 5=90s 6=180s 7=270s
// For example 7 represents a 270 rotation followed by a symetry.
Pt Walk(Pt p, int arrow, int rotSym) {
	Pt res ;
	if( arrow == -1 )
		return p ;
	arrow = (arrow + 2 * (rotSym%4)) % 8 ;
	if( rotSym / 4 == 0 ) {
		res.x = p.x + arrows[arrow].x ;
		res.y = p.y + arrows[arrow].y ;
	}
	else {
		res.x = p.x + arrows[arrow].y ;
		res.y = p.y + arrows[arrow].x ;
	}
	return res ;
}

void LoadMap() {
	int i ;
	scanf("%d", &size.x) ;
	scanf("%d", &size.y) ;
	fgets(map[0], 100, stdin) ; // skip  nl
	for( i = 0 ; i < size.y ; i++)
		fgets(map[i], 100, stdin) ;
}

void WriteMap() {
	Pt p ;
	for( p.y = 0 ; p.y < size.y ; p.y++ ) {
		for( p.x = 0 ; p.x < size.x ; p.x++ )
			printf("%c", get(p) );
		printf("\n") ;
	}
}

// Determinates the enclosing rectangle of the current cluster
void UpdateMinMax(Pt p) {
	nStars++ ;
	if( p.x < minP.x ) minP.x = p.x ;
	if( p.x > maxP.x ) maxP.x = p.x ;
	if( p.y < minP.y ) minP.y = p.y ;
	if( p.y > maxP.y ) maxP.y = p.y ;
}

// Fills a cluster with the char "name" (for the first time)
void FirstFill(Pt p, int arrow, int name) {
	int a ;
	Pt np = Walk(p, arrow, 0) ;
	if( get(np) != '0' && get(np) != name ) {
		set(np, name) ;
		UpdateMinMax(np) ;
		for( a = 0 ; a < 8 ; a++ )
			FirstFill(np, a, name) ;
	}
}

// Fills a cluster with the char "name"
void Fill(Pt p, int arrow, int name) {
	int a ;
	Pt np = Walk(p, arrow, 0) ;
	if( get(np) != '0' && get(np) != name ) {
		set(np, name) ;
		for( a = 0 ; a < 8 ; a++ )
			Fill(np, a, name) ;
	}
}

// Determines the start point where the comparison of the current cluster must begin
// for the orientation "rotSym"
Pt StartPt(int rotSym, int name) {
	Pt p = Walk(minP, 1, rotSym) ;
	Pt res = minP ;
	if( p.x < minP.x )
		res.x = maxP.x ;
	if( p.y < minP.y )
		res.y = maxP.y ;
	while( get(res) != name )
		res = Walk(res, 0, rotSym) ;
	return res ;
}

// Compares two clusters according to the orientation "rotSym"
int CompareX(Pt p, Pt q, int arrow, int rotSym) {
	int a ;
	Pt np = Walk(p, arrow, 0), nq = Walk(q, arrow, rotSym) ;
	if( get(np) == '0' ) return get(nq) == '0' ;
	if( get(np) == '1' ) return true ;
	set(np, '1') ;

	if( get(nq) == '0' ) return false ;
	for( a = 0 ; a < 8 ; a++ )
		if( !CompareX(np, nq, a, rotSym) ) return false ;
	return true ;
}

// Compares the cluster starting at "p" with the cluster with starting points "start"
int Compare(Pt p, Pt start[], int old) {
	int rotSym ;
	for( rotSym = 0 ; rotSym < 8 ; rotSym++ ) {
		if( CompareX(p, start[rotSym], -1, rotSym) )
			return true ;
		else Fill(p, -1, old) ;
	}
	return false ;
}

// Scans the map, finds the clusters, paints them
void ProcessMap() {
	Pt p ;
	int k, rotSym ;
	int nShapes = 0 ;
	char name = 'a' ;
	for( p.y = 0 ; p.y < size.y ; p.y++ )
		for( p.x = 0 ; p.x < size.x ; p.x++ ) {
			if( get(p) == '1' ) {
				minP = maxP = p ;
				nStars = 0 ;
				FirstFill(p, -1, name) ;
				for( k = 0 ; k < nShapes ; k++ )
					if( shapes[k].nStars == nStars
						&& Compare(p, shapes[k].start, name) ) {
					// Same shape
						shapes[k].num++ ;
						Fill(p, -1, shapes[k].name) ;
						goto next ;
					}
			// New shape
				shapes[nShapes].name = name ;
				shapes[nShapes].nStars = nStars ;
				shapes[nShapes].num = 1 ;
				for( rotSym = 0 ; rotSym < 8 ; rotSym++ )
					shapes[nShapes].start[rotSym] = StartPt(rotSym, name) ;
				nShapes++ ;
				name++ ;
			}
next: ; }
//	for( k = 0 ; k < nShapes ; k++ )
//		printf("%c = %d\n", shapes[k].name, shapes[k].num) ;
}

main() {
	LoadMap() ;
	ProcessMap() ;
	WriteMap() ;
}
