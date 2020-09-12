#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int idx[10] = {0};


int main() {

    int N;
    scanf("%d", &N);

    int c;
    do {
        c = N%10;
        N /= 10;
        idx[c]++;
    } while(N) ;


    for(int i = 10; i--; ) {
        int cnt = idx[i];
        for(int j = cnt; j--; )
            printf("%d",i);
    }
    puts("");



    return 0;
}
