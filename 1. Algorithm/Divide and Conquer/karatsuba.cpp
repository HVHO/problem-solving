#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int testCase = 0;

vector<int> member;
vector<int> fan;


void nomarlize(vector<int> &a) {

    for(int i = 0; i < a.size(); i++) {
        
        if(a[i] < 0) {

            int borrow = ( abs(a[i]) + 9 ) / 10;

            a[i+1] -= borrow;
            a[i] += borrow * 10;

        } else {

            a[i+1] += a[i] / 10;
            a[i] = a[i]%10;
        }

    }

    while(a.size() > 1 && a.back() == 0) a.pop_back();

}

vector<int> multiply(vector<int> &a, vector<int> &b) {

    vector<int> result(a.size() + b.size() + 1,0);

    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++) {
            result[i + j] += a[i] + b[j];
        }

    
    nomarlize(result);

    return result;
}

// a += b*10^k
void addTo(vector<int> &a, const vector<int> &b, int k) {

    int an = a.size();
    int bn = b.size();
    int delta = an - bn - k;

    // a 의 자릿수 조절
    if ( delta < 0)
        for(int i = 0; i < abs(delta); i++)
            a.push_back(0);
    
    // a += b*10^k
    for(int i = 0; i < bn; i++) {
        a[i + k] += b[i];
    }
}

// a -= b / assume a >= b
void subFrom(vector<int> &a, const vector<int> &b) {

    int an = a.size(), bn = b.size();

    for(int i = 0; i < bn; i++) {
        
        a[i] -= b[i];

        if(a[i] < 0) {
            int borrow = ( abs(a[i]) + 9) / 10;
            a[i + 1] -= borrow;
            a[i] += borrow*10; 
        }
    }

}


vector<int> karatsuba (vector<int>& a, vector<int>& b) {

    // assume an > bn
    if(a.size() < b.size()) return karatsuba(b,a);

    // base case
    if(a.size() == 0 && b.size() == 0) return vector<int> ();
    if(max(a.size(),b.size()) < 50) return multiply(a,b); 

    // Divide and Conquer

    int half = a.size()/2;

    // a, b 를 반으로 쪼갠다
    vector <int> a0(a.begin() , a.begin() + half);
    vector <int> a1(a.begin() + half, a.end());
    vector <int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector <int> b1(b.begin()+min<int>(b.size(),half), b.end());

    // z2 = a1*b1
    vector <int> z2 = karatsuba(a1,b1);

    // z0 = a0*b0
    vector <int> z0 = karatsuba(a0,b0);

    // a0 = a0 + a1
    addTo(a0,a1,0);
    // b0 = b0 + b1
    addTo(b0,b1,0);
    
    // z1 = (a0 + a1)*(b0 + b1)
    vector <int> z1 = karatsuba(a0,b0);

    // z1 -= z2, z0
    subFrom(z1,z2);
    subFrom(z1,z0);

    // ret = z0 + z1*10^half + z2*10^(half*2)
    vector <int> result;
    addTo(result,z0,0);
    addTo(result,z1,half);
    addTo(result,z2,2*half);


    return result;

}

void iter_print(vector<int> &a) {

    vector<int>::iterator it = a.begin();
    while(it != a.end()) cout << *(it++);
    cout << endl;

}


int main(void) {

    int i, j;


    cin >> testCase;

    for(i = 0; i < testCase; i++) {
        
        vector<int> a,b;

        char temp;
        scanf("%c",&temp);

        while(true) {
            scanf("%c",&temp);
            if(temp == 10) break;
            a.push_back(temp - 48);
        }
        iter_print(a);
        

        while(true) {
            scanf("%c",&temp);
            if(temp == 10) break;
            b.push_back(temp - 48);
        }
        iter_print(b);

        vector <int> ret = karatsuba(a,b);

        iter_print(ret);
    }

    return 0;
}