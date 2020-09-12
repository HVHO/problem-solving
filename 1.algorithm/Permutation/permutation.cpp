#include <stdio.h>
#include <iostream>
#include <malloc.h>

#define MAX 101

#define myswap(a,b) {int _t = a; a = b; b = _t;}

char source[] = {0, 97, 98, 99 };
char temp[MAX] = { 0, };

int N;

// print func
void print() {
	printf("[");
	for (int i = 1; i <= N; i++) {
		printf("%c ", temp[i]);
	}
	puts("]");
}

// permutation, nPr = n-1Pr-1 + n-1Pr
void perm(int n, int r) {

	// 더이상 뽑을게 없을 경우 중지
	if (r == 0) {
		print();
		return;
	}

	for (int i = n; i; i--) {

		temp[r] = source[i];
		myswap(source[n], source[i]);
		perm(n - 1, r - 1);
		myswap(source[n], source[i]);
	}

}

void pi(int n, int r) {

	// 더이상 뽑을게 없을 경우 중지
	if (r == 0) {
		print();
		return;
	}

	for (int i = n; i; i--) {

		temp[r] = source[i];
		myswap(source[n], source[i]);
		perm(n, r - 1);
		myswap(source[n], source[i]);
	}
}

void comb(int n, int r) {

	if (r == 0) {
		print();
		return;
	}

	if (n == 0) {
		return;
	}

	temp[r] = source[n];
	comb(n - 1, r - 1);
	comb(n - 1, r);

}

void h(int n, int r) {
	
	if (r == 0) {
		print();
		return;
	}

	if (n == 0) {
		return;
	}

	temp[r] = source[n];
	h(n , r - 1);
	h(n - 1, r);

}

int perm_cal(int n, int r) {

	int ret = 1;
	for (int i = n; i > (n - r); i--) {
		ret *= i;
	}

	return ret;
}

int pi_cal(int n, int r) {
	int ret = 1;
	for (int i = 0; i < r; i++)
		ret *= n;
	return ret;
}

int comb_cal(int n, int r) {

	if (r == 0) return 1;

	if (r > n) return 0;

	return comb_cal(n - 1, r - 1) + comb_cal(n - 1, r);

}

int h_cal(int n, int r) {
	
	if(r == 0 ) return 1;

	if (n == 0) return 0;

	return h_cal(n - 1, r) + h_cal(n, r - 1);
}



int main() {

	N = 3;

	printf("%d\n", perm_cal(3, 2));
	perm(3, 2);
	printf("=====================\n");
	printf("%d\n", pi_cal(3, 2));
	pi(3, 2);
	printf("=====================\n");
	printf("%d\n", comb_cal(3, 2));
	comb(3, 2);
	printf("=====================\n");
	printf("%d\n", h_cal(3, 2));
	h(3, 2);

	return 0;
}

