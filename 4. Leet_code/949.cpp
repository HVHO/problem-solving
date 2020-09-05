// 949.	Largest Time for Given Digits    

#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    
    bool check(vector<int> arr) {
        int hour = arr[0]*10 + arr[1];
        int minute = arr[2]*10 + arr[3];
        if(hour < 24 && minute < 60)
            return true;

        return false;
    }
    
    int trans(vector<int> arr) {
        return 1000*arr[0] + 100*arr[1] + 10*arr[2] + arr[3];
    }
    
    vector<int> comp(vector<int> a, vector<int> b) {
        if(trans(a)>trans(b)) return a;
        else return b;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        
        vector<int> res = {0,0,0,0};
        bool flag = false;
        
        sort(arr.begin(),arr.end());
        do{
            if(check(arr)) {
                res = comp(res, arr);
                flag =true;
            }
	    }while(next_permutation(arr.begin(),arr.end()));
        
        if(!flag) return string("");
        
        char buf[10];
        sprintf(buf,"%d%d:%d%d",res[0],res[1],res[2],res[3]);
        
        return string(buf);
        
    }
};