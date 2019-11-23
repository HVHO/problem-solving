#include <stdio.h>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define checkBit(x,a) ((x) & (1<<(a)))

const int INF = 987654321;
const int MOD = 5*1e5 + 9;
const int NMAX = (int)1e5+1;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

int M;

// disjoint set

int parent[NMAX];
int rank[NMAX];
int count[NMAX];

void disInit() {
    for(int i = 0; i < NMAX; i++) {
        parent[i] = i;
        count[i] = 1;
        rank[i] = 0;
    }
        
}

int find(int x) {
    int c = x;
    while(c != parent[c]) {
        c = parent[c];
    }
    return c;
}

void myUnion(int x, int y) {

    int xParent = find(x);
    int yParent = find(y);

    if(xParent == yParent) return;

    if (rank[xParent] >= rank[yParent]){
        if(rank[xParent] == rank[yParent])
            rank[xParent]++;
        parent[yParent] = xParent;
        count[xParent] += count[yParent];
    } else {
        parent[xParent] = yParent;
        count[yParent] += count[xParent];
    }

}

// hash

struct NODE {
    int next;
    char str[21];
};

NODE nodePool[NMAX];
int nodeNum = 0;
NODE hashTable[MOD];

bool ztrcmp(char* str1, char* str2) {
    int idx = 0;

    while(str1[idx]) {
        if(str1[idx] != str2[idx]) return false;
        idx++;
    } 
    if(str1[idx] == str2[idx]) return true;
    else return false;
    
}

void ztrcpy(char *src, char* dest) {
    int idx = 0;
    while(src[idx]) {
        dest[idx] = src[idx];
        idx++;
    }
    dest[idx] = src[idx];
}

void hashInit() {

    for(int i = 0; i < MOD; i++) {
        hashTable[i].next = 0;
        }
    
}

ull hashFunc(char *str) {
    ull hkey = 0;
    int idx = 0;

    while(str[idx]) {
        hkey = ((hkey << 5) + hkey + str[idx])%MOD;
        idx++;
    }

    return hkey;
}

int findHashEntry(char *str) {
    ull hashKey = hashFunc(str);

    // finde Hash Entry
    int cNode = hashTable[hashKey].next;
    while(cNode) {
        if(ztrcmp(nodePool[cNode].str,str))return cNode;
        cNode = nodePool[cNode].next;
    }

    // make New Entry
    int newNode = ++nodeNum;
    ztrcpy(str,nodePool[newNode].str);
    nodePool[newNode].next = hashTable[hashKey].next;
    hashTable[hashKey].next = newNode;

    return newNode;
}


ll sol() {

    int N;
    ll ret = 0;
    
    scanf("%d",&N);

    disInit();
    // hashInit();

    char str1[21],str2[21];
    for(int i = 0; i < N; i++) {
        scanf("%s %s",str1, str2);
        int hashEntry1 = findHashEntry(str1);
        int hashEntry2 = findHashEntry(str2);

        myUnion(hashEntry1,hashEntry2);
        printf("%d\n",count[find(hashEntry1)]);

    }


    return 0;

}



int main() {
    int TC;
    scanf("%d",&TC);
    for(int i = 0; i < TC; i++)
        sol();
    
    // printf("%lld\n",sol());
    // sol();
    return 0;
}