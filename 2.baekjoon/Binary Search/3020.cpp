#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 100000;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, H;
vector<int> a, b;

int upper_bound(int val, vector<int> &a) {
	int l = 0;
	int r = a.size();
	while(l < r) {
		int m = (l + r)/2;
		if(val < a[m]) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return l;
}

int lower_bound(int val, vector<int> &a) {
	int l = 0;
	int r = a.size();
	while(l < r) {
		int m = (l + r)/2;
		if(val <= a[m]) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return l;
}

int main(void) {
	scanf("%d %d\n", &N, &H);

	int t;
	a = vector<int>(N/2);
	b = vector<int>(N/2);

	for(int i = 0; i < N; i++) {
		scanf("%d", &t);
		if(i&1) {
			b[i/2] = t;
		} else {
			a[i/2] = t;
		}
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int min = INF;
	int cnt = 0;	
	for(int i = 1; i <= H; i++) {
		t = (N/2 - lower_bound(i, a)) + (N/2 - upper_bound(H - i, b));
		if(min > t) {
			min = t;
			cnt = 1;
		} else if (min == t) {
			cnt++;
		}
	}
	printf("%d %d\n", min, cnt);

	return 0;
}
