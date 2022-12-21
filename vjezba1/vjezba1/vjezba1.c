#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* podniz(int* niz, int start, int stop)
{
	int n = stop - start;
	int* niz2 = (int*)malloc(n * sizeof(int));
	int j = 0;

	for (int i = start; i < stop; i++)
	{

		niz2[j] = niz[i];
		j++;
	}
	return niz2;
}

int* filtriraj(int* niz, int n, int th, int* nth)
{
	int j = 0;
	int i = 0;
	int brojac = 0;

	for (int i = 0; i < n; i++) {
		if (niz[i] < th) {
			brojac++;
		}
	}

	int* niz2 = (int*)malloc(brojac * sizeof(int));
	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			niz2[j] = niz[i];
			j++;
		}

	}

	*nth = brojac;
	return niz2;


}

int** podijeli(int* niz, int n) {
	int j = 0;
	int* Lniz = (int*)malloc((n / 2) * sizeof(int));
	int* Dniz = (int*)malloc((n - (n / 2)) * sizeof(int));
	int** nizNovi = (int**)malloc(2 * (sizeof(int*)));

	for (int i = 0; i < (n / 2); i++)
	{
		Lniz[i] = niz[i];
	}

	for (int i = (n / 2); i < n; i++)
	{
		Dniz[j] = niz[i];
		j++;
	}

	nizNovi[0] = Lniz;
	nizNovi[1] = Dniz;
	return nizNovi;
}


typedef struct Tocka {
	float x;
	float y;
}Tocka;

typedef struct Poligon {
	Tocka* nizVrhova;
	int n;
}Poligon;


Poligon* novi_poligon(float* niz_x, float* niz_y, int n) {
	Poligon* NoviPoligon = (Poligon*)malloc(sizeof(Poligon));
	Tocka* NoviNizVrhova = (Tocka*)malloc(n * sizeof(Tocka));

	NoviPoligon->n = n;
	for (int i = 0; i < NoviPoligon->n; i++) {
		NoviNizVrhova[i].x = niz_x[i];
		NoviNizVrhova[i].y = niz_y[i];
	}

	NoviPoligon->nizVrhova = NoviNizVrhova;

	return NoviPoligon;
	free(NoviNizVrhova);
}


Tocka** pozitivni(Poligon* p) {

	int brojac = 0;
	int j = 0;
	for (int i = 0; i < (p->n); i++) {
		if (p->nizVrhova[i].x > 0 && p->nizVrhova[i].y > 0) {
			brojac++;
		}
	}

	Tocka** PozNizVrhova = (Tocka**)malloc(brojac * sizeof(Tocka*));

	for (int i = 0; i < (p->n); i++) {
		if ((p->nizVrhova[i].x > 0) && (p->nizVrhova[i].y > 0)) {
			PozNizVrhova[j] = &(p->nizVrhova[i]);
			j++;
		}
	}
	return PozNizVrhova;
}


void main()
{

	int niz[] = { 11, 20, 12, 13, 15, 46, 30, 23 , 12, 69 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", niz[i]);
	}
	int start = 4;
	int stop = 8;
	printf("\nPodniz ");
	int* niz2 = podniz(niz, start, stop);
	for (int i = 0; i < (stop - start); i++)
		printf(" \n%d ", niz2[i]);

	free(niz2);
	printf("\n");
	int th = 20;
	int n = sizeof(niz) / sizeof(int);
	int nth;
	int* niz3 = filtriraj(niz, n, th, &nth);
	printf("Filtrirani: ");
	for (int i = 0; i < nth; i++)
		printf(" \n%d ", niz3[i]);
	free(niz3);
	int** niz4 = podijeli(niz, n);
	int* lijeviNiz = niz4[0];
	int* desniNiz = niz4[1];

	printf("\nPrvi dio: ");
	for (int i = 0; i < (n / 2); i++)
		printf("\n%d ", lijeviNiz[i]);

	printf("\nDrugi dio: ");

	for (int i = 0; i < (n - (n / 2)); i++)
		printf("\n%d ", desniNiz[i]);
	free(niz4);
	free(lijeviNiz);
	free(desniNiz);
	

	float niz_x[] = { -1, 5, 10, 15, 20 };
	float niz_y[] = { 20, 15, -10, 5 ,1 };
	int n = 5;

	Poligon* NovPol = novi_poligon(niz_x, niz_y, n);
	printf("Tocke su\n");
	for (int i = 0; i < n; i++)
		printf("%.2f %.2f\n", NovPol->nizVrhova[i].x, NovPol->nizVrhova[i].y);

	printf("\n");


	printf("Tocke sa pozitivnim vrhovima su\n");
	Tocka** nizPoz = pozitivni(NovPol);

	for (int i = 0; i < 3; i++)
		printf("%.2f %.2f \n", nizPoz[i]->x, nizPoz[i]->y);
	
	free(NovPol);
	free(nizPoz);


}
