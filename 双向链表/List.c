#include"List.h"

//LTNode* BuyListNode(LTDataType x)
//{
//	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
//	if (node == NULL)
//	{
//		perror("malloc fail");
//		//return NULL;
//		exit(-1);
//	}
//	node->next = NULL;
//	node->prev = NULL;
//	node->data = x;
//
//	return node;
//}

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		//return NULL;
		exit(-1);
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;

	return node;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	/*LTNode* first = phead->next;*/
	/*phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;*/

	//²»ÄÜËæ±ã»»Ë³Ðò
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;
	/*newnode->prev = phead;*/
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("<=head=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


bool LTEmpty(LTNode* phead)
{
	assert(phead);

	/*if (phead->next == phead)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return phead->next == phead;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	//....
}

void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* p = pos->prev;
	LTNode* n = pos->next;

	p->next = n;
	n->prev = p;
	free(pos);
	//pos = NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	// prev newnode pos

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	//phead = NULL;
}





















//LTNode* BuyListNode(LTDataType x)
//{
//	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
//	if (node == NULL)
//	{
//		perror("malloc fail");
//		//return NULL;
//		exit(-1);
//	}
//	node->next = NULL;
//	node->prev = NULL;
//	node->data = x;
//
//	return node;
//}
//
//LTNode* LTInit()
//{
//	LTNode* phead = BuyListNode(-1);
//	phead->next = phead;
//	phead->prev = phead;
//
//	return phead;
//}
//
//void LTDestroy(LTNode* phead);
//
//void LTPrint(LTNode* phead)
//{
//	assert(phead);
//
//	printf("<=head=>");
//	LTNode* cur = phead->next;
//	while (cur != phead)
//	{
//		printf("%d<=>", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
//
//bool LTEmpty(LTNode* phead)
//{
//	assert(phead);
//
//	/*if (phead->next == phead)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}*/
//
//	return phead->next == phead;
//}
//
//
//void LTPushBack(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	//LTNode* newnode = BuyListNode(x);
//	//LTNode* tail = phead->prev;
//
//	//// phead            tail  newnode
//	//tail->next = newnode;
//	//newnode->prev = tail;
//	//newnode->next = phead;
//	//phead->prev = newnode;
//
//	LTInsert(phead, x);
//}
//
//void LTPopBack(LTNode* phead)
//{
//	assert(phead);
//	assert(!LTEmpty(phead));
//
//	LTNode* tail = phead->prev;
//	LTNode* tailPrev = tail->prev;
//
//	tailPrev->next = phead;
//	phead->prev = tailPrev;
//	free(tail);
//	tail = NULL;
//}
//
//void LTPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	//LTNode* newnode = BuyListNode(x);
//	//LTNode* first = phead->next;
//	//phead->next = newnode;
//	//newnode->prev = phead;
//
//	//newnode->next = first;
//	//first->prev = newnode;
//
//	// ²»ÄÜËæ±ã»»Ë³Ðò
//	//newnode->next = phead->next;
//	//phead->next->prev = newnode;
//
//	//phead->next = newnode;
//	//newnode->prev = phead;
//
//	LTInsert(phead->next, x);
//}
//
//void LTPopFront(LTNode* phead)
//{
//	assert(phead);
//	assert(!LTEmpty(phead));
//	//....
//}
//
//void LTInsert(LTNode* pos, LTDataType x)
//{
//	assert(pos);
//
//	LTNode* prev = pos->prev;
//	LTNode* newnode = BuyListNode(x);
//	// prev newnode pos
//
//	prev->next = newnode;
//	newnode->prev = prev;
//
//	newnode->next = pos;
//	pos->prev = newnode;
//}
