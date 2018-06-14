#include"Kruskal.h"

int locatevex(adj adjlist, char ch, int n){ // 在有n个顶点的表头数组adjlist中查找字符ch所代表的顶点在表头数组的序号(下标)
	int i;
	for (i = 0;i < n;i++) {
		if (ch == adjlist[i].data) {
			return i;
		}
	}
}

int locateedge(link2 E, int a[], int n, int j) { 
	int flag = 0;
	if (a[E[j].first - 'A'] != a[E[j].second - 'A'])
		flag = 1;
	return flag;
}

adj inputnode(int n){ // 输入n个顶点
	char ch;
	int i = 0;
	adj adjlist;
	link end;

	adjlist = (adj)malloc(n * sizeof(adj));
	end = (link) malloc(n * sizeof(link));
	end->weight = -1;
	printf("\n顶点输入：\nNO 1: ");
	scanf(" %c", &ch);
	do{
		end[i].weight = -1;
		adjlist[i].data = ch;
		printf("NO %d: ", i+2);
		scanf(" %c", &ch);
		adjlist[i].firstarc = &end[i];
		i++;
	} while (ch != '*');
	return adjlist;
}

void createadjlist(adj adjlist, int n,int num){ //在有n个顶点的表头数组adjlist中输入边，建立图的邻接表    
	int i1,i2,w,p=0;
	char first, second;
	link linklist,m[1];

	printf("\n边输入：input u    v    w\n");
	scanf(" %c %c %d", &first, &second, &w);
	linklist = (link)malloc(2*num*sizeof(lnode));
	do {
		i1 = locatevex(adjlist, first, n);
		i2 = locatevex(adjlist, second, n);

		m[0] = adjlist[i1].firstarc;
		adjlist[i1].firstarc = &linklist[p];
		linklist[p].weight = w;
		linklist[p].nextarc = m[0];
		linklist[p].data = second;

		m[0] = adjlist[i2].firstarc;
		adjlist[i2].firstarc = &linklist[p+1];
		linklist[p+1].weight = w;
		linklist[p+1].nextarc = m[0];
		linklist[p+1].data = first;

		p = p + 2;
		scanf(" %c %c %d", &first, &second, &w);
	} while (first != '*');
}

void list(adj linklist, int n){ // 输出图的邻接表
	int i;
	struct linknode *p;
	
	printf("\nadjlist:");
	for (i = 0;i < n;i++) {
		printf("\nNo %d: %c",i+1,linklist[i].data);
		p = linklist[i].firstarc;
		do {
			printf("-->%c(%d)",p->data,p->weight);
			p = p->nextarc;
		} while (p->weight != -1 && p != NULL && p->nextarc != NULL);
	}
}

void minispantree_kruskal(adj adjlist, int n, int ps) { // 主模块，用kruskal算法生成最小生成树
	link2  E;
	E = (link2)malloc(2 * n * sizeof(LLL));
	int i, p = 0, j, k, m, flag;
	link t[1];
	link2 fin;
	linknode2 tmp;
	int *a;
	a = (int*)malloc(ps * sizeof(int));

	for (i = 0;i < ps;i++) 
		a[i] = i + 1;
	
	for (i = 0;i < ps;i++) {//将边编入一个数组
		t[0] = adjlist[i].firstarc;
		do {
			E[p].weight = t[0]->weight;
			E[p].first = adjlist[i].data;
			E[p].second = t[0]->data;
			E[p].nextarc = t[0]->nextarc;
			p++;
			t[0] = t[0]->nextarc;
		} while (t[0]->weight != -1 && t[0] != NULL && t[0] != nullptr);
	}

	for (i = 0; i < 2*n - 1; i++) {//将边从小到大排序
		for (j = 0; j < 2*n - 1 - i; j++) {
			if (E[j].weight > E[j + 1].weight) {
				tmp = E[j];
				E[j] = E[j + 1];
				E[j + 1] = tmp;
			}
		}
	}

	j = 0;
	fin = (link2)malloc(2*n*sizeof(link2));
	m = 0;
	do {
		flag = locateedge(E, a, m, j);//等于1时不重复
		if (flag == 0) {
			j++;
			continue;
		}
		else {
			fin[m].first = E[j].first;
			fin[m].second = E[j].second;
			fin[m].weight = E[j].weight;
			fin[m].nextarc = NULL;
			k = a[(int)(E[j].second - 'A')];
			for (i = 0;i < ps;i++) {
				if (a[i]== k)
					a[i] = a[(int)(E[j].first - 'A')];
			}
			m++;
			j++;
		}
	} while (j<2*n);

	printf("\nminispantree: ");
	for (i = 0;i <m;i++)
		printf("\n%c-->%c %d", fin[i].first, fin[i].second, fin[i].weight);

}
