#include"Kruskal.h"

int main() {
	int n,num;
	adj adjlist;

	printf("�����붥�������");
	scanf("%d", &n);
	adjlist = inputnode(n);
	printf("\n������ߵ�������");
	scanf(" %d", &num);
	createadjlist(adjlist, n, num);
	list(adjlist, n);
	minispantree_kruskal(adjlist, num,n);
	getchar();
	getchar();

	return 0;
}