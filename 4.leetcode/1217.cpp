// 	1217.	Minimum Cost to Move Chips to The Same Position    

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd = 0;
        
        for(int i: position) {
            if(1&i) odd++;
            else even++;
            // cout<< "i: "<<i<<"odd :" << odd <<" even: " <<even <<endl;
        }
        return odd>even? even:odd;
        
    }
};