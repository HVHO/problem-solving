#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


int testCase = 0;

int N = 0, C = 0, M = 0;

vector<int> hat[10005];

int bSearch(int idx_hat, int A, char set) {

    vector <int> &cur = hat[idx_hat];
    int first = 0; int last = cur.size() - 1;
    int mid = 0;
    
    //if(cur[first] > A) return -1;

    while(first <= last) {
        mid = (first + last)/2;
        //cout << first << " " << mid << " " << last << endl;

        if(cur[mid] == A) { return mid;}

        if(cur[mid] > A) last = mid - 1;
        else first = mid + 1;
    };
    
    if(set == 'a') {
        while(first > 0 && cur[first-1] > A) first--; 
        return first;
    } 
    else if(set == 'b') {
        while(last < (cur.size() - 1) && cur[last+1] < A) last++; 
        return last;
    }

    return -1;
}

void binarySearch(int idx_hat, int A, int B, int &idx_A, int &idx_B) {

    //if(hat[idx_hat].size() < 2) {idx_A = -1; return;}

    idx_A = bSearch(idx_hat, A, 'a');
    idx_B = bSearch(idx_hat, B, 'b');

    return;

}

int main(void) {
    int i,j;


    cin >> N >> C;
    int temp;

    for( i = 0; i < N; i++) {
        scanf("%d ", &temp);
        hat[temp].push_back(i+1);
    }

    cin >> M;

    int A,B;
    int idx_A, idx_B;

    for(i = 0; i < M; i++) {
        idx_A = idx_B = 0;
        scanf("%d %d\n",&A,&B);
        
        int ret = -1;
        for(j = 1; j <= C; j++) {
            binarySearch(j,A,B,idx_A,idx_B);
            //cout << j << " " << idx_A << " " << idx_B << endl;
            if(idx_A != -1 && ((idx_B - idx_A + 1) > ((B-A+1)/2))) {
                ret = j;
                break;
            }
        }

        if(ret != -1) printf("yes %d\n",ret);
        else printf("no\n");

    }

    //printf("hello");


    return 0;
}