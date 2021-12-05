#include <iostream>
#include <stdlib.h>
#define mymax(a, b) ((a) > (b) ? (a) : (b))
#define mymin(a, b) ((a) < (b) ? (a) : (b))
#define updateBit(x, a) ((x) | (1 << (a)))
#define checkBit(x, a) ((x) & (1 << (a)))

const int INF = 987654321;
const long long MOD = (long long)1e9 + 7;
const int NMAX = 5000000;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int N, L;

pair<int, int> deque[2 * NMAX]; // val, idx
int f = 0, r = 0;

bool empty()
{
    return f >= r;
}

void pop_front()
{
    f++;
}

void pop_rare()
{
    r--;
}

pair<int, int> front()
{   
    return deque[f + 1];
}

pair<int, int> rare()
{
    return deque[r];
}

void push_rare(pair<int, int> p)
{
    deque[++r] = p;
}



int sol()
{
    cin >> N >> L;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (!empty() && front().second <= (i - L))
        {
            // cout << "pop front : " << front().first << endl;
            pop_front();
        }
        while (!empty() && rare().first > input)
        // while (!dq.empty() && dq.back().first > input)
        {
            // cout << "pop rare : " << rare().first << endl;
            pop_rare();
            // dq.pop_back();
        }
        push_rare({input, i});
        // dq.push_back({input, i});
        cout << front().first << " ";
        // cout << dq.front().first << " ";
    }

    return 0;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base ::sync_with_stdio(false);
    sol();
    return 0;
}