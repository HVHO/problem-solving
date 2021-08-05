#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>

#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 5000000;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N;

int main(void) {
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	scanf("%d",&N);

	int val;
	for(int i = 0; i < N; i++) {
		scanf("%d",&val);

		if(max_heap.size() > min_heap.size()) {
			min_heap.push(val);
		} else {
			max_heap.push(val);
		}

		if(!min_heap.empty() && max_heap.top() > min_heap.top()) {
			int a = max_heap.top();
			int b = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(b);
			min_heap.push(a);
		}

		printf("%d\n",max_heap.top());

	}


	return 0;
}
