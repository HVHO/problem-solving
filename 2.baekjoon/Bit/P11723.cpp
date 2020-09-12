#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define deleteBit(x,a) ((x) & ~(1<<a))
#define checkBit(x,a) ((x) & (1<<(a)))
#define toggleBit(x,a) ((x) ^ (1<<(a)))

const int INF = 987654321;
const int MOD = 5*1e5 + 9;
const int NMAX = (int)1e5+1;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

int _all = (1<<21) - 1;
int _empty = 0;
int set = 0;


// char add[] = "add";
// char check[] = "check";
// char remove[] = "remove";
// char toggle[] = "toggle";
// char all[] = "all";
// char empty[] = "empty";


int main() {
    int M;
    scanf("%d",&M);
    // for(int i = 0; i < TC; i++)
    //     sol();
    char order[10];
    int num;
    for(int i = 0; i < M; i++) {
        scanf("%s",order);

        if(order[0] == 'a') {
            if(order[1] == 'l') {
                set = _all;
            } else {
                scanf("%d",&num);
                set = updateBit(set,num);
            }
        } else if(order[0] == 'c') {
            scanf("%d",&num);
            if(checkBit(set,num)) printf("1\n");
            else printf("0\n");
        } else if(order[0] == 'r') {
            scanf("%d",&num);
            set = deleteBit(set,num);
        } else if(order[0] == 't') {
            scanf("%d",&num);
            set = toggleBit(set,num);
        } else if(order[0] == 'e') {
            set = _empty;
        }


    }
    // printf("%lld\n",sol());
    // sol();
    return 0;
}