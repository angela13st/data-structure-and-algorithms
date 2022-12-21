#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define strdup _strdup


#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable* table;
	table = malloc(sizeof(HashTable));
	table->table = calloc(size, sizeof(Bin*));
	table->size = size;
	table->load = 0;
	return table;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int key = hash(word) % ht->size;
	Bin* item = malloc(sizeof(Bin));
	item->word = word;
	item->next = NULL;

	
	item->next = ht->table[key];
	ht->table[key] = item;
	ht->load++;
	
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int key = hash(word) % ht->size;
	Bin* p = ht->table[key];
		while (p != NULL)
		{
			if (strcmp(word, p->word) == 0) {
				return 1;
			}
			else {
				p = p->next;
			}
		}
	
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for (int i = 0; i < ht->size; i++) {
	
		
		while (ht->table[i] != NULL) 
		{
			Bin* brisi = ht->table[i];
			ht->table[i] = ht->table[i]->next;
			free(brisi->word);
			free(brisi);
		}
			
		}
	
	free(ht->table);
	free(ht);
	
	
}