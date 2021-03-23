#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
	bool operator(pair<pair<double,char>,pair<int,int>> x, pair<pair<double,char>,pair<int,int>> y) {
			if(x.first.first == y.first.first) {
				if(x.second.first == y.second.first)
					return x.second.second < y.second.second;
				else
					return x.second.first < y.second.first;
			} else {
				return x.first.first > y.first.first;
			}
	}
};




int main() {
	double like[5];
	for(int i = 0; i < 5; i++) 
		cin >> like[i];
	
	vector<pair<int,int>> opened;
	vector<pair<int,int>> yet;
	
	int N,M;
	cin >> N >> M;
	
	char buf;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%c", &buf);
			if(buf == 'O') {
				opened.push_back(make_pair(i,j));
			} else if (buf == 'Y') {
				yet.push_back(make_pair(i,j));
			}
		}
		scanf("\n");
	}
	
	char genre [101][101];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%c", &buf);
			genre[i][j] = buf;
		}
		scanf("\n");
	}
	
	priority_queue<
		pair<pair<double,char>, pair<int,int>>,
		vector<pair<pair<double,char>, pair<int,int>>>,
		cmp> pq;
	
	for(auto e: yet) {
		int n = e.first;
		int m = e.second;
		char g = genre[n][m];
		double l = like[g - 'A'];
		pq.push(make_pair(make_pair(l,g), make_pair(n,m)));
	}
	
	while(!pq.empty()) {
		auto e = pq.top();
		pq.pop();
		
		printf("%c %.1f %d %d \n", e.first.first, e.first.second, e.second.first, e.second.second);
	}
	
	for(auto e: opened) {
		int n = e.first;
		int m = e.second;
		char g = genre[n][m];
		double l = like[g - 'A'];
		pq.push(make_pair(make_pair(l,g), make_pair(n,m)));
	}
	
	while(!pq.empty()) {
		auto e = pq.top();
		pq.pop();
		
		printf("%c %.1f %d %d \n", e.first.first, e.first.second, e.second.first, e.second.second);
	}
	
	
	
}