#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 21
#define INF 987654321

#define myswap(a,b) {pair <int,int> _t = (a); (a) = (b); (b) = _t;}
#define mymin(a,b) ((a) > (b) ? (b) : (a))
#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define myabs(a) ((a) > 0 ? (a) : -(a))

using namespace std;

int N;
int Max;
int Min;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // scanf("%d",&N);
    cin >> N;

    register int t;
    // scanf("%d",&t);
    cin >> t;
    Max = Min = t;
    N--;
    for(register int i = 0; i < N; i++) {
        // scanf("%d", &t);
        cin >> t;
        if(t > Max) Max = t;
        else if(t < Min) Min = t;
    }

    printf("%d %d\n", Min, Max);
    
    return 0;
}