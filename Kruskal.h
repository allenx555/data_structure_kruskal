#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct linknode  // 结点结构(按指导书要求构造）
{
	char data;             // 邻接的顶点的序号(下标) 
	int weight;             // 邻接顶点间的距离(权值)
	struct linknode *nextarc;  // 指向下一个邻接顶点的指针
}lnode, *link;

typedef struct linknode2  // 结点结构(按指导书要求构造）
{
	char first;
	char second;
	int weight;             // 邻接顶点间的距离(权值)
	struct linknode *nextarc;  // 指向下一个邻接顶点的指针
}*link2,LLL;

typedef struct headnode   //元素结构(按指导书要求构造）
{
	char data;               // 顶点元素
	link firstarc;           // 顶点元素所指向邻接结点所构成的邻接链表的指针
}hnode, *adj;

void createadjlist(adj adjlist, int n, int num);

int locatevex(adj adjlist, char ch, int n);

adj inputnode(int n);

void list(adj ht, int n);

int locateedge(link2 E, int a[], int n, int j);

void minispantree_kruskal(adj adjlist, int n, int ps);