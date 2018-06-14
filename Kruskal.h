#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct linknode  // ���ṹ(��ָ����Ҫ���죩
{
	char data;             // �ڽӵĶ�������(�±�) 
	int weight;             // �ڽӶ����ľ���(Ȩֵ)
	struct linknode *nextarc;  // ָ����һ���ڽӶ����ָ��
}lnode, *link;

typedef struct linknode2  // ���ṹ(��ָ����Ҫ���죩
{
	char first;
	char second;
	int weight;             // �ڽӶ����ľ���(Ȩֵ)
	struct linknode *nextarc;  // ָ����һ���ڽӶ����ָ��
}*link2,LLL;

typedef struct headnode   //Ԫ�ؽṹ(��ָ����Ҫ���죩
{
	char data;               // ����Ԫ��
	link firstarc;           // ����Ԫ����ָ���ڽӽ�������ɵ��ڽ������ָ��
}hnode, *adj;

void createadjlist(adj adjlist, int n, int num);

int locatevex(adj adjlist, char ch, int n);

adj inputnode(int n);

void list(adj ht, int n);

int locateedge(link2 E, int a[], int n, int j);

void minispantree_kruskal(adj adjlist, int n, int ps);