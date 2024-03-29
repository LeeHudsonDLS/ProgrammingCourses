#include<stdio.h>
#include<string.h>
#include<math.h>

#define BINS 10

struct Node;

typedef struct Node
{
	struct Node* next;
	const char* key;
} NODE;


typedef struct
{

	NODE bin[BINS];

} HASH;

int hashFunction(const char* text)
{
	int hash = 177;
	for(int i = 0; i < strlen(text); i++)
	{
		int c = text[i];
		hash +=c*(i+1);
		
	}
	return hash % BINS;
}

void insertInList(NODE* pStart, NODE* pNewEntry)
{
	while(pStart->next !=NULL)
	{
		pStart = pStart->next;
	}
	pStart->next= pNewEntry; 
	
}

void add(HASH* pHash, const char* key)
{
	int hash = hashFunction("key");

	NODE* pNode = malloc(sizeof(NODE));
	pNode->key = malloc(strlen(key)+1);	

	strcpy(pNode->key,key);
	pNode->next = NULL;
	insertInList(&pHash->bin[hash],pNode);
}



void print(HASH* pHash)
{
	
	printf("%s\n",pHash->bin[0]->key);
	/*
	for(int i = 0; i < BINS; i++)
	{
		printf("%s\n",pHash->bin[i].key);
	}*/
}

int main(void)
{

	HASH h = {NULL};
	add(&h,"Tommy");
	add(&h,"Ali");
	add(&h,"Susan");
	add(&h,"Jimmy");
	add(&h,"Peter");
	add(&h,"Kamil");
	print(&h);
	return 0;

}

