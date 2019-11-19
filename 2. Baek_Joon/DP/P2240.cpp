#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define TMAX 1001
#define WMAX 31
#define INF 987654321

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;


int mem[TMAX][WMAX][2];
int arr[TMAX];
int T, W;


int dp(int t, int w, int c) {

    int &ret = mem[t][w][c];

    if(ret) return ret;

    // base case
    if(t == 0) {
        if(c == 1 && w == 0) return -TMAX;
        else if(arr[0] == c) return 1;
        else return 0;
    }
        

 
    if(w) ret = mymax(dp(t-1,w,c),dp(t-1,w-1,(c+1)%2));
    else ret = dp(t-1,w,c);
    if(arr[t] == c) ret++;

    return ret;
}


int sol() {

    

    cin >> T >> W;

    int tmp;
    for(int i = 0; i < T; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    
    return mymax(dp(T - 1,W,0),dp(T - 1,W,1));

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   cout << sol() << endl;

    return 0;
}
