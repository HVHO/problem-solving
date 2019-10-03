#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <malloc.h>

#define myswap(a,b) { int _t = (a); (a) = (b); (b) = _t;}

#define MAX 50
int src[MAX] = { 2,1,6,4,5,8,7,9,3 };
int temp[MAX] = { 0, };
int n;

void print(const char *str) {
	printf("%s : [",str);
	for (int i = 0; i < n; i++) {
		printf("%d ", src[i]);
	}
	printf(" ]\n");

}

void mergeSort(int s, int e) {

	// divide & conquer
	if (s < e) {

		// divide
		int m = (s + e) / 2;
		mergeSort(s, m);
		mergeSort(m + 1, e);

		int p = s;
		int q = m + 1;
		int idx = s;

		// conquer
		while (p <= m || q <= e) {
			// get from left
			if (q>e || (p<=m && src[p]<src[q])) {
				temp[idx++] = src[p++];
			}
			else {
				temp[idx++] = src[q++];
			}
		}

		// temp -> src
		for (int i = s; i <= e; i++)
			src[i] = temp[i];
	}

}

void quickSort(int s, int e) { // left pivot

	// divide & conquer
	if (s < e) {
		int p = s;
		int l = s;
		int r = e;

		while (l < r) {

			while (src[l] <= src[p] && l < e) {
				l++;
			}
			while (src[r] > src[p]) {
				r--;
			}
			if (l < r) {
				myswap(src[l], src[r]);
			}
		}
		myswap(src[r], src[p]);

		quickSort(s, r - 1);
		quickSort(r + 1, e);
	}

}

void quickSort2(int s, int e) { // Center pivot

	// divide & conquer
	if (s < e) {
		int p = src[(s + e)/2];
		int l = s;
		int r = e;

		while (l < r) {

			while (src[l] <= p) {
				l++;
			}
			while (src[r] > p) {
				r--;
			}
			if (l < r) {
				myswap(src[l], src[r]);
			}
		}
		//myswap(src[r], src[p]);

		quickSort(s, l - 1);
		quickSort(l , e);
	}

}

int binSearch(int key, int s, int e) {
	int m;
	while (s <= e) {
		m = (s + e) / 2;

		if (src[m] == key) return m;

		if (src[m] < key) s = m + 1;
		else e = m - 1;
	}

	// for lis DP prob
#if 0
	if (src[e] < key) {
		return e + 1;
	}
	else {
		return e;
	}
#endif
	// basic
	return -1;
}

int main(void) {

//	n = 9;
	n = MAX;
	for (int i = 0; i < MAX; i++)
		//src[i] = rand()%(MAX<<2);
		src[i] = i;

	//print("before sort : ");
//	mergeSort(0, n - 1);
//	quickSort(0, n - 1);
	quickSort2(0, n - 1);
	print("after  sort : ");

#if 0
	for (int i = 0; i < MAX - 1; i++) {
		if (src[i] > src[i + 1]) { printf("FAIL\n"); return 0; }
	}
	printf("SUCESS\n");
#endif
	int find = 5000;
	printf("binSearch %d idx : %d\n", find, binSearch(find, 0, n -1));


	return 0;

}

