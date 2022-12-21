#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int mystrlen(char* st)
{

	int i = 0;
	while (st[i] != '\0')
	{
		i++;

	}
	return i;


}

void mystrcpy(char* st1, char* st2)
{
	int i = 0;
	while (st2[i] != '\0')
	{
		st1[i] = st2[i];
		i++;
	}
	st1[i] = '\0';
}

int mystrcmp(char* st, char* st1)
{
	int i = 0;
	while (st[i] != '\0' && st1[i] != '\0')
	{
		if (st[i] == st1[i])
		{
			i++;
			printf("\n 0");
			return 0;
		}
		else if (st[i] < st1[i])
		{
			i++;
			printf("\n -1");
			return -1;
		}
		else
		{
			i++;
			printf("\n 1");
			return 1;
		}
	}

}

void main()
{
	int d = 0;
	int d1 = 0;
	char st[100];
	printf("Unesi string:");
	scanf("%s", st);
	d = mystrlen(st);
	printf("duljina stringa je: %d \n", d);

	char st1[100];
	char st2[100];
	//printf("Unesi string:");
	//scanf("%s", st1);
	printf("Unesi string:");
	scanf("%s", st2);
	mystrcpy(st1, st2);
	printf("string 1: %s \nstring 2: %s", st1, st2);

	int c = 2;
	c = mystrcmp(st, st1);
	printf("\n %d", c);








}

