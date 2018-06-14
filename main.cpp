#include"Kruskal.h"

int main() {
	int n,num;
	adj adjlist;

	printf("请输入顶点个数：");
	scanf("%d", &n);
	adjlist = inputnode(n);
	printf("\n请输入边的数量：");
	scanf(" %d", &num);
	createadjlist(adjlist, n, num);
	list(adjlist, n);
	minispantree_kruskal(adjlist, num,n);
	getchar();
	getchar();

	return 0;
}