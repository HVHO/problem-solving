// prim algorithm
/*
6 11
1 2 3
1 3 5
2 3 2
2 4 6
3 2 1
3 4 4
3 5 6
4 5 2
4 6 3
5 1 3
5 6 6
*/
#include <stdio.h>
#define MAX 1001
#define INF 987654321
int V, E;
int g[MAX][MAX];

int dist[MAX];
int visited[MAX];
int p[MAX];
void init(){
	for (int i = 1; i <= V; i++){
		dist[i] = INF;
		p[i] = 0;
	}
}

void prim(int start, int end){
	init();
	for (int i = 1; i <= V; i++){
		visited[i] = 1;
	}

	dist[start] = 0;
	int u;
	int min;

	//	while (1){
	for (int i = 1; i < V; i++){
		min = INF;
		for (int i = 1; i <= V; i++){
			if (visited[i] && min > dist[i]){
				u = i;
				min = dist[i];
			}
		}
		
		visited[u] = 0;
		for (int j = 1; j <= V; j++){
			if (visited[j] && dist[j] >  g[u][j]){
				dist[j] =  g[u][j];
				p[j] = u;
			}
		}
	}
	puts("prim");
	printf("idx\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", i);
	}
	puts("");
	printf("dist\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", dist[i]);
	}
	puts("");
	printf("p\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", p[i]);
	}
	puts("");

	
}
int heap[MAX];
int hCnt;
void push(int idx){
	while (idx > 1 && dist[heap[idx]] < dist[heap[idx / 2]]){
		int t = heap[idx];
		heap[idx] = heap[idx/2];
		heap[idx/2] = t;
		idx = idx / 2;
	}

}

int pop(){
	int val = heap[1];
	heap[1] = heap[hCnt--];
	int idx = 1;
	int next;
	while (1){
		next = idx * 2;
		if (next<hCnt && dist[heap[next]] > dist[heap[next + 1]]){
			next++;
		}
		if (next > hCnt || dist[heap[idx]] < dist[heap[next]]){
			break;
		}

		int t = heap[idx];
		heap[idx] = heap[next];
		heap[next] = t;

		idx = next;
	}
	return val;
}
void prim_heap(int start, int end){
	init();
	for (int i = 1; i <= V; i++){
		visited[i] = 1;
		heap[i] = i;
	}
	heap[1] = start;
	heap[start] = 1;

	hCnt = V;

	dist[start] = 0;
	int u;
	

	while (hCnt){
	
		u = pop();
		for (int j = 1; j <= hCnt; j++){
			if (dist[heap[j]] >  g[u][heap[j]]){
				dist[heap[j]] =  g[u][heap[j]];
				p[heap[j]] = u;
				push(j);
			}
		}
	}
	puts("prim_heap");
	printf("idx\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", i);
	}
	puts("");
	printf("dist\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", dist[i]);
	}
	puts("");
	printf("p\t:\t");
	for (int i = 1; i <= V; i++){
		printf("%d\t", p[i]);
	}
	puts("");

}

int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	int sn, en, val;
	for (int i = 0; i < E; i++){
		scanf("%d %d %d", &sn, &en, &val);
		g[sn][en]= g[en][sn] = val;
	}
#if 0
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			printf("%d ", g[i][j]);
		}
		puts("");
	}
#endif
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			if (i != j && g[i][j] == 0){
				g[i][j] = INF;
			}
		}
	}

#if 0
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			if (g[i][j] == INF){
				printf("- ");
			}
			else{
				printf("%d ", g[i][j]);
			}
		}
		puts("");
	}
#endif
	int start = 2;
	int end = 6;
	prim(start, end);
	prim_heap(start, end);
	return 0;
}

