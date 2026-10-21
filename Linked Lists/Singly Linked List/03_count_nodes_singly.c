#include<stdio.h>
#include<malloc.h>

struct node
{
	int iData;
	struct node *pNext;	
};

void InsertFirst(struct node**,int);
int CountNodes(struct node *);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void)
{
	struct node *pFirst=NULL;
	int iCount=0;
	
	InsertFirst(&pFirst,10);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,30);
	Display(pFirst);
	
	iCount=CountNodes(pFirst);
	printf("Count of node is:%d\n",iCount);
	
	if(pFirst!=NULL);
	{
		DeleteAll(&pFirst);
		pFirst=NULL;
	}
	Display(pFirst);
	return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
	struct node * pNewNode=NULL;
	
	pNewNode=(struct node*)malloc (sizeof(struct node));
	if(NULL==pNewNode)
	{
		printf("Memory Allocation FAILED");
		return ;
	}
	pNewNode->iData=iNo;
	
	if(NULL== *ppHead)
	{
		pNewNode->pNext=NULL;
	    *ppHead=pNewNode;
	    
	    return;
	}
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
}

int CountNodes(struct node *pHead)
{
	int iCount=0;
	while(pHead!=NULL)
	{
		iCount++;
		pHead=pHead->pNext;
	}
	return iCount;
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

