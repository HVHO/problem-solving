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
	vector<int> mem(N,0);

	for(int i = 0; i < N; i++)
		cin >> alchor[i];

	if(N==1) {
		printf("%d\n",alchor[0]);
		return 0;
	}

	mem[0] = alchor[0];
	mem[1] = alchor[0] + alchor[1];
	mem[2] = max(alchor[0]+alchor[1],max(alchor[1]+alchor[2],alchor[2]+alchor[0]));

	for(int i = 3; i < N; i++) {
		mem[i] = max(mem[i-3] + alchor[i] + alchor[i-1],max(mem[i-2] + alchor[i],mem[i-1]));
	}

	int res = 0;
	for(int i = 0; i < N; i++)
		res = max(res,mem[i]);

	printf("%d\n",res);
	
	return 0;
}
