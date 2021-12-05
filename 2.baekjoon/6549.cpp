#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int testCase = 0;

vector<long long> input;

long long max_Square(int l, int r) {

    int i, j, k;
    long long left = 0;
    long long right = 0;
    long long middle = 0;

    // base case
    if(l == (r-1)) return input[l];

    // find max square
    left = max_Square(l, (l+r)/2);
    right = max_Square((l+r)/2, r);

    // brute force 
    /*
    for(i = l; i < (l+r)/2; i++)
        for(j = (l+r)/2; j < r; j++){

            int local_min = input[i];
            for(k = i; k <= j; k++)
                local_min = min(local_min, input[k]);

            middle = max(middle, (j - i + 1)*local_min);
        }
    */
   long long lo = (l+r)/2 - 1;
   long long hi = (l+r)/2;
   long long height = min<long long>(input[lo],input[hi]);
   middle = height*2;

   while(l < lo || hi < (r - 1)) { // 확장할게 남아 있을때

       if(lo == l || ((hi < (r - 1)) && (input[hi + 1] > input[lo - 1]))) { // 오른쪽 확장
            hi++;
            height = min<long long>(height,input[hi]);
       } else { // 왼쪽 확장
            lo--;
            height = min<long long>(height,input[lo]);
       }

       middle = max<long long>(middle, (hi - lo + 1) * height);

   }


    //cout << "l : " << l << " r : " << r << " // " << left << " " << right << " " << middle << endl;
    return max<long long>(left, max<long long>(right, middle));

}



int main(void) {

    int i, j;

    while(true) {

        int len, temp;

        input.clear();

        cin >> len;

        if(len == 0) break;

        for(j = 0; j < len; j++) {
            cin >> temp;
            input.push_back(temp);
        }

        cout << max_Square(0, len) << endl;

    }
        
        


    return 0;
}