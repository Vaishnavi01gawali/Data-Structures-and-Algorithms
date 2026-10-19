#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;	
};

void InsertLast(struct node**,int);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void)
{
	struct node *pFirst=NULL;
	
	InsertLast(&pFirst,10);
	InsertLast(&pFirst,20);
	InsertLast(&pFirst,30);
	Display(pFirst);
	
	if(pFirst!=NULL);
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	return 0;
}

void InsertLast(struct node **ppHead,int iNo)
{
	struct node *pNewNode=NULL;
	struct node *pTemp=NULL;
	
	pNewNode=(struct node*)malloc (sizeof(struct node));
	if(NULL==pNewNode)
	{
		printf("Memory Allocation FAILED");
		return ;
	}
	pNewNode->iData=iNo;
	pNewNode->pNext=NULL;
	
	if(NULL== *ppHead)
	{
	    *ppHead=pNewNode;
	    
	    return;
	}
	pTemp=*ppHead;
	while(pTemp->pNext!=NULL)
	    pTemp=pTemp->pNext;
	   
	pTemp->pNext=pNewNode;   
}

void Display(struct node *pHead)
{
	if(NULL==pHead)
	{
		printf("List is empty");
		return;
	}
	
	while(pHead!=NULL)
	{
		printf("|%d|->",pHead->iData);
		pHead=pHead->pNext;
	}
	printf("|NULL|\n");
}

void DeleteAll(struct node **ppHead)
{
	struct node *pTemp=NULL;
	
	while(*ppHead != NULL)
	{
		pTemp=*ppHead;
		*ppHead=pTemp->pNext;
		free(pTemp);
	}	
}

//|10|->|20|->|30|->|NULL|
