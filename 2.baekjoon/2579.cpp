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

int N;

int main(void) {

	cin >> N;

	vector<int> stair(N,0);
	for(int i = 0; i < N; i++) 
		cin >> stair[i];

	if(N==1) {
		printf("%d\n",stair[0]);
		return 0;
	}

	vector<vector<int> > mem(N,vector<int>(2,0));

	mem[0][0] = stair[0];
	mem[0][1] = stair[0];
	mem[1][0] = stair[1];
	mem[1][1] = stair[0] + stair[1];

	int res = 0;
	for(int i = 2; i < N; i++) {
		mem[i][0] = max(mem[i-2][0],mem[i-2][1]) + stair[i];
		mem[i][1] = mem[i-1][0] + stair[i];
	}

	printf("%d\n",max(mem[N-1][0],mem[N-1][1]));
	
	return 0;
}
