// my backtracking code
#include <iostream>
#include <stdio.h>
#include <malloc.h>
//#include <time.h>

#define MAX 4000
char src[MAX] = { 0,97,98,99 };
int n, r;
int a[MAX]; // perm 할 때 src 의 값이 아닌 idx 저장용
int visit[MAX]; // 사용했는지 판단

using namespace std;

void print() {
	/*
	printf("[ ");
	for (int i = 1; i <= r; i++)
		printf("%c ", src[a[i]]);
	puts("]");
	*/
}

// permutation framework
int makeCandi(int *candi, int k) {
	int cnt = 0;
	int inperm[MAX] = { 0 };

	for (int i = 1; i < k; i++) {
		inperm[a[i]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!inperm[i]) candi[cnt++] = i;
	}

	return cnt;
}

void perm_frame(int k) {

	if (k == r) {
		print();
		return;
	}
	k++;

	int candi[MAX];
	int cnt = makeCandi(candi, k);

	for (int i = 0; i < cnt; i++) {
		a[k] = candi[i];
		perm_frame(k);
	}

}

#if 1
// permutation visit method
void perm_btr(int k) {

	if (k == r) {
		print();
		return;
	}

	k++;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			a[k] = i;
			visit[i] = 1;
			perm_btr(k);
			visit[i] = 0;
		}
	}
}

void pi_btr(int k) {

	if (k == r) {
		print();
		return;
	}

	k++;
	for (int i = 1; i <= n; i++) {
		//if (!visit[i]) {
			a[k] = i;
			visit[i] = 1;
			pi_btr(k);
			visit[i] = 0;
		//}
	}
}
#endif

void footprint() {
	//printf("time : %d\n", time(NULL));
}

int main() {
	
	n = 18;
	r = 9;
	for (int i = 0; i < n; i++)
		src[i+1] = i+1;

	footprint();
	perm_btr(0);
	footprint();
	//pi_btr(0);
	//footprint();
	perm_frame(0);
	footprint();

	return 0;
}