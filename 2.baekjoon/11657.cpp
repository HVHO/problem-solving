#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <tuple>

#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const long long INF = INT64_MAX/2;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 100000;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, M;

int main(void)
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector<tuple<ll, ll, ll>> edges;

	for (int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		edges.push_back(make_tuple(s - 1, e - 1, c));
	}

	auto cost = vector<ll>(N, INF);
	cost[0] = 0;

	for (int i = 0; i < (N - 1); i++)
		for (int j = 0; j < M; j++)
		{

			auto [s, e, c] = edges[j];

			if (cost[s] == INF)
				continue;
			if (cost[e] > cost[s] + c)
				cost[e] = cost[s] + c;
		}

	for (int j = 0; j < M; j++)
	{

		auto [s, e, c] = edges[j];
		if (cost[s] == INF)
				continue;
		if (cost[e] > cost[s] + c)
		{
			cout << "-1";
			return 0;
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (cost[i] == INF)
			cout << "-1" << endl;
		else
			cout << cost[i] << endl;
	}

	return 0;
}
