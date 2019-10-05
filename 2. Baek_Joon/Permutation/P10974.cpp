#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;


int src[MAX] = {1, 2, 3, 4 ,5 ,6 ,7 , 8, 9, 10};
int visit[MAX] = {0};
int temp[MAX] = {0};

int N;

void perm(int n, int r) {

    if(r == 0) {
        for(int i = n; i > 0; i--)
        printf("%d ",temp[i]);
        printf("\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            temp[r] = src[i];
            perm(n, r - 1);
            visit[i] = 0;
        }
    }

}


int main() {


    cin >> N;

    perm(N,N);

    return 0;
}
