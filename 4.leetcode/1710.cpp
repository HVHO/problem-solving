// 1710. Maximum Units on a Truck    		

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> first, vector<int> second) -> bool
        {
            return first[1] > second[1];
        });
        
        int res = 0;
        int idx = 0;
        while(true) {
            if(truckSize > boxTypes[idx][0]) {
                truckSize -= boxTypes[idx][0];
                res += boxTypes[idx][0] * boxTypes[idx][1];
                idx++;
                if(idx == boxTypes.size()) break;
            } else {
                res += boxTypes[idx][1] * truckSize;
                break;
            }
        }
        
        return res;
        
    }
};
