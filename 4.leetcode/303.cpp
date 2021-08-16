// 303. Range Sum Query - Immutable

class NumArray {
public:
    
    int segTree[40000] = {0,};
    int n;
    
    int init(int l, int r, int node, vector<int>& nums) {
        if(l==r) {
            return segTree[node] = nums[l];
        }
        int m = (l+r)/2;
        return segTree[node] = init(l,m,2*node,nums) + init(m + 1,r,2*node+1,nums);
    }
    
    int query(int l, int r, int nodeL, int nodeR, int root) {

        if(r < nodeL || l > nodeR) return 0;
        if(l <= nodeL && nodeR <= r) return segTree[root];
        int m = (nodeL+ nodeR)/2;
        
        return query(l, r, nodeL, m, 2*root) + query(l, r, m + 1, nodeR, 2*root + 1);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        init(0,n-1,1,nums);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
