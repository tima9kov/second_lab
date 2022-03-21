#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node
{
	char c;
	struct Node* next;
} Node;