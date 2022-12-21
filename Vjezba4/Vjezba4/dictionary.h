#ifndef DICTIONARY_H
#define DICTIONARY_H
#define _CRT_SECURE_NO_WARNINGS
#define strdup _strdup

typedef struct Word 
{
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

// vraæa 1 ako je broj pojavljivanja rijeci izmeðu 5 i 10 i ako je rijec duža od 3 znaka
int filter(Word *w);

// filtrira i vraca izmijenjenu indict listu koja sadrzi samo rijeci za koje je filter() vratila 1
Dictionary filterDictionary(Dictionary indict, int(*filter)(Word *w));

#endif