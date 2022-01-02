#include <iostream>
#include <stdlib.h>
#include <vector>
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

int TC,N;

int main(void) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	auto val = vector<vector<int> > (NMAX, vector<int>(2,0));
	auto mem = vector<vector<int> > (NMAX, vector<int>(2,0));

	for(int tc = 0; tc < TC; tc++) {
		cin >> N;

		for(int i = 0; i < N; i++) cin >>  val[i][0];
		for(int i = 0; i < N; i++) cin >>  val[i][1];

		int res = 0;
		if(N==1) {
			res = max(val[0][0],val[0][1]);
		} else {
			mem[0][0] = val[0][0];
			mem[0][1] = val[0][1];
			mem[1][0] = val[0][1] + val[1][0];
			mem[1][1] = val[0][0] + val[1][1];
			res = max(mem[1][0],mem[1][1]);

			for(int i = 2; i < N; i++) {
				mem[i][0] = max(mem[i-1][1],mem[i-2][1]) + val[i][0];
				mem[i][1] = max(mem[i-1][0],mem[i-2][0]) + val[i][1];
			}

			res = max(max(mem[N-1][0],mem[N-1][1]),max(mem[N-2][0],mem[N-2][1]));
		}
		printf("%d\n",res);
	}	
	
	return 0;
}
