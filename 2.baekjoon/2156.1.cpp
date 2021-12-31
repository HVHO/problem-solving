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

	vector<int> alchor(N,0);
	vector<vector<int> > mem(N,vector<int>(3,0));

	for(int i = 0; i < N; i++)
		cin >> alchor[i];

	if(N==1) {
		printf("%d\n",alchor[0]);
		return 0;
	}

	mem[0][0] = alchor[0];
	mem[0][1] = alchor[0];
	mem[0][2] = alchor[0];

	mem[1][0] = alchor[1];
	mem[1][1] = alchor[0] + alchor[1];
	mem[1][2] = alchor[0] + alchor[1];

	for(int i = 2; i < N; i++) {
		mem[i][0] = max(mem[i-2][0],max(mem[i-2][1],mem[i-2][2])) + alchor[i];
		mem[i][1] = mem[i-1][0] + alchor[i];
		mem[i][2] = max(mem[i][0],max(mem[i][1],mem[i-1][2]));
	}

	printf("%d\n",mem[N-1][2]);
	
	return 0;
}
