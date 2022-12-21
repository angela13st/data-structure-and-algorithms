#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* presjek(int* skupA,int* skupB, int nA, int nB)
{
	int* presjek;
	int k = 0;
	int veci;
	if (nA > nB)
		veci = nA;
	else
		veci = nB;
	presjek= (int*)malloc(sizeof(int) * veci);
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < nB; j++)
		{
			if (skupA[i] == skupB[j])
			{
				presjek[k] = skupA[i];
				k++;
			}
		}
	}
	return presjek;
}

int usporedba(const void* A, const void* B)
{
	return (*(int*)A-*(int*)B);
}

int* presjek_jedan_sortiran(int* skupA, int* skupB, int nA, int nB)
{
	int* presjek;
	int k = 0;
	int veci;
	if (nA > nB)
		veci = nA;
	else
		veci = nB;
	presjek = (int*)malloc(sizeof(int) * veci);
	for (int i = 0; i < nA; i++)
	{
		int* tmp = (int*)bsearch(&skupA, skupB, nB, sizeof(int), usporedba);
		if (tmp != NULL)
		{
			presjek[k] = tmp[i];
			k++;
		}
	}
	return presjek;
}

int* presjek_oba_sortirana(int* skupA, int* skupB, int nA, int nB)
{
	qsort(skupB, nB, sizeof(int), usporedba);
	int* presjek;
	int k = 0;
	int manji;
	if (nA < nB)
		manji = nA;
	else
		manji = nB;
	presjek = (int*)malloc(sizeof(int) * manji);
	int i = 0;
	int j = 0;
	while(i<manji && j<manji)
	{
	
		{
			if (skupA[i] == skupB[j])
			{
				presjek[k] = skupA[i];
				k++;
				i++;
				j++;
			}
			else if (skupA[i] > skupB[j])
			{
				j++;
			}
			else
				i++;
		}
	}
	return presjek;
}


void main()
{
	srand(time(NULL));
	int* skupA;
	int* skupB;
	int nA = 7000000;
	int nB = 7000000;
	clock_t pocetak, kraj;
	double vrijeme;
	int* presj;

	
	skupA = generiraj(nA);
	skupB = generiraj(nB);
	shuffle(skupA,nA);
	shuffle(skupB,nB);
	pocetak = clock();
	presj = presjek(skupA, skupB, nA, nB);
	kraj = clock();
	vrijeme = ((double)(kraj - pocetak)/CLOCKS_PER_SEC);
	printf("vrijeme oba nesortirana: %f \n", vrijeme);
	free(skupA);
	free(skupB);
	free(presj);
	

	skupA = generiraj(nA);
	skupB = generiraj(nB);
	shuffle(skupA, nA);
	pocetak = clock();
	presj = presjek_jedan_sortiran(skupA, skupB, nA, nB);
	kraj = clock();
	vrijeme = ((double)(kraj - pocetak) / CLOCKS_PER_SEC);
	printf("vrijeme jedan sortiran: %f \n", vrijeme);
	free(skupA);
	free(skupB);
	free(presj);

	skupA = generiraj(nA);
	skupB = generiraj(nB);
	shuffle(skupB, nB);
	pocetak = clock();
	presj =presjek_oba_sortirana(skupA, skupB, nA, nB);
	kraj = clock();
	vrijeme = ((double)(kraj - pocetak) / CLOCKS_PER_SEC);
	printf("vrijeme oba sortirana: %f \n", vrijeme);
	free(skupA);
	free(skupB);
	free(presj);
	
}