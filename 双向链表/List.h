#pragma once
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;

	LTDataType data;
}LTNode;

//void LTInit(LTNode** pphead);
LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

// 在pos位置之前插入一个值
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

LTNode* BuyListNode(LTDataType x);

