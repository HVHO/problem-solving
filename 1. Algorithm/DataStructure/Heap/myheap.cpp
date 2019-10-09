#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001

#define myswap(a,b) {int _t = (a); (a) = (b); (b) = _t;}

using namespace std;

int N;

unsigned int heap[MAX];
int hcnt = 0;

void push(unsigned int a) {

    heap[++hcnt] = a;
    int idx = hcnt;

    while(idx > 1 && heap[idx] < heap[idx/2]) {

        myswap(heap[idx],heap[idx/2]);
        idx /= 2;

    }

    return;
}

unsigned int pop() {

    if(!hcnt) return 0;

    int ret = heap[1];
    heap[1] = heap[hcnt--];

    int idx = 1;
    while(1) {
        int next = 0;
        int left = 2*idx;
        int right = 2*idx + 1;

        if(left <= hcnt) {
            if(heap[left] < heap[idx]) next = left;
        }
        if(right <= hcnt) {
            if(heap[right] < heap[idx] && heap[right] < heap[left]) next = right;
        }

        if(!next) break;

        myswap(heap[next],heap[idx]);
        idx = next;
    }


    return ret;
}

int main() {
    int i,j;

    int N;
    scanf("%d", &N);

    int tmp;
    for(i = 0; i < N; i++) {
        
        scanf("%d" , &tmp);
        if(tmp) push(tmp);
        else printf("%u\n",pop());

    }


    return 0;
}
