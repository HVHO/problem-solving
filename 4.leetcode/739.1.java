// 739. Daily Temperatures

class Solution {
    final static int range = 71;
    
    public int[] dailyTemperatures(int[] T) {
        
        int size = T.length;
        int[] res = new int[size];
        Stack<Integer> s = new Stack<>();
        
        for(int i = 0; i < size; i++)
            res[i] = 0;
        
        for(int i = size - 1; i >= 0; i--) {
            while(!s.empty() && T[s.peek()] <= T[i])
                s.pop();
            if(!s.empty()) res[i] = s.peek() - i;
            s.push(i);
        }
        
        return res;
    }
}