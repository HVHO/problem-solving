#include <iostream>
#include <stdlib.h>
#include <vector>
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

int N, M;


int parent[501] = {0,};
int _size[501] = {1,};
int edge[501] = {0,};

int find(int x) {
	int _x = x;
	while(parent[_x]!=_x) {
		_x = parent[_x];
	}

	parent[x] = _x; // path 압축
	return _x;
}

void _union(int x, int y) {
	int px = find(x);
	int py = find(y);


	if(_size[px] < _size[py]) {
		int t = px;
		px = py;
		py = t;
	}
	edge[px] += (edge[py]+1); // 해당 disjoint-set 에 속한 edge 개수
	if(px == py) return;
	parent[py] = px;
	_size[px] += _size[py];
} 

int main(void) {
	int tc = 1;
	while(true) {
		cin >> N >> M;
		if(!N&&!M) return 0;

		for(int i = 1; i <= N; i++) {
			parent[i] = i;
			_size[i] = 1; 
			edge[i] = 0;
		}
	
		int x, y;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			_union(x,y);
		}


		int res = 0;
		for(int i = 1; i <= N; i++) {
			if(i == parent[i] && edge[i] == (_size[i] - 1)) res ++;
		}

		printf("Case %d: ", tc);
		if(res == 0) printf("No trees.\n");
		else if(res == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", res);
		tc++;
	}
	return 0;
}
