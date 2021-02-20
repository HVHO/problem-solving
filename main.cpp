#include <bits/stdc++.h>
#include <iostream>

#define MAX_PEOPLE  ((int)2e5 + 1)
using namespace std;

int root[MAX_PEOPLE];
int _size[MAX_PEOPLE];
int _rank[MAX_PEOPLE];
// union find problem
int find(int idx) {
    if (root[idx] == idx) return idx;
    return root[idx] = find(root[idx]);
}

int _union(int l, int r) {
   int lp = find(l);
   int rp = find(r);

    if(lp == rp) return _size[lp];

    if (_rank[lp] < _rank[rp]) swap(lp, rp);

    root[rp] = lp;
    _size[lp] += _size[rp];
    _size[rp] = 0;
    if (_rank[lp] == _rank[rp]) _rank[lp]++;

    return _size[lp];
}


int main() {
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int EC;
        scanf("%d", &EC);
        for(int i = 0; i < MAX_PEOPLE; i++) {
            root[i] = i;
            _rank[i] = 0;
            _size[i] = 1;
        }

        map<string,int> idx_map;
        int idx = 0;

        for (int ec = 0; ec < EC; ec++) {
            char lc[21], rc[21];
            string l, r;
            scanf("%s %s\n", lc, rc);
            l = lc;
            r = rc;

            if(idx_map.find(l) == idx_map.end()) {
                idx_map[l] = idx++;
            }
            if(idx_map.find(r) == idx_map.end()) {
                idx_map[r] = idx++;
            }
            printf("%d\n", _union(idx_map[l],idx_map[r]));
        }

    }
    return 0;
}