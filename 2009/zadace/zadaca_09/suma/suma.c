
/*
DMIH 2003, Prvi dan natjecanja
Srednjoskolska skupina, II. podskupina
Zadatak SUMA, Programski jezik C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ULAZ   "suma.in"
#define IZLAZ  "suma.out"

int n;
typedef struct
{
	int x, y;
	double kut;
} vektor;

int pokutu (const void *a, const void *b)
{
	vektor *va = (vektor *) a, *vb = (vektor *) b;

	double res = va -> kut - vb -> kut;
	if (res < 0) return -1;
	if (res > 0) return 1;

	return 0;
}

int main (void)
{
	FILE *fp = fopen (ULAZ, "rt");
	int i, j, maxx, maxy, nk;
        char jedinstveno, kolin = 0;
	vektor *v, *suma;

	fscanf (fp, "%d", &n);
	v = malloc (sizeof (vektor) * n);
	suma = malloc (sizeof (vektor) * (n + 1));

	for (i = 0; i < n; ++i)
	{
		fscanf (fp, "%d %d", &v[i].x, &v[i].y);
		if (v[i].x || v[i].y)
			v[i].kut = atan2 (v[i].y, v[i].x);
		else
			v[i].kut = 1e3;
	}
	fclose (fp);

        /* Sortiranje po kutu */
	qsort (v, n, sizeof (vektor), pokutu);

        nk = 0;
        /* Sve vektore istog smjera svedi u 1 (zbroji ih). */
	{
		int k, l;
		int tx, ty;

		for (i = k = 0; i < n;)
		{
			if (v[i].kut == 1e3) break;
			for (j = i + 1; j < n; ++j)
				if (v[i].kut != v[j].kut)
					break;
			tx = ty = 0;
			for (l = i; l < j; ++l)
				tx += v[l].x, ty += v[l].y;
			v[k].x = tx;
			v[k].y = ty;
			++k;
                        if (j > i + 1) kolin = 1, ++nk;
			i = j;
		}
		n = k;
	}

        /* Zbrajanje */
	suma[0].x = suma[0].y = 0;

	for (i = 1; i <= n; ++i)
		suma[i].x = suma[i - 1].x + v[i - 1].x,
		suma[i].y = suma[i - 1].y + v[i - 1].y;

	maxx = maxy = 0;

        jedinstveno = 1;
	for (i = j = 0; i < n;)
	{
		int curx, cury, next;

		if (j >= i)
			curx = suma[j + 1].x - suma[i].x,
			cury = suma[j + 1].y - suma[i].y;
		else
			curx = suma[n].x - suma[i].x + suma[j + 1].x,
			cury = suma[n].y - suma[i].y + suma[j + 1].y;


		if (curx * (long long) curx + cury * (long long) cury ==
                maxx * (long long) maxx + maxy * (long long) maxy)
			maxx = curx, maxy = cury, jedinstveno = 0;

		if (curx * (long long) curx + cury * (long long) cury >
                maxx * (long long) maxx + maxy * (long long) maxy)
			maxx = curx, maxy = cury, jedinstveno = 1;

		next = (j + 1) % n;
		if (v[i].x * v[next].y > v[i].y * v[next].x)
			j = next;
		else
		{
			if (j == i) j = next;
			++i;
		}
	}

	fp = fopen (IZLAZ, "wt");
	fprintf (fp, "%lld\n", (long long) maxx * maxx + maxy * (long long) maxy);
	fclose (fp);

	return 0;
}
