// 739. Daily Temperatures

class Solution {
    final static int range = 71;
    
    public int[] dailyTemperatures(int[] T) {
        
        int size = T.length;
        int mem[][] = new int[size][range];
        
        for(int i = 0; i < range; i++)
            mem[size - 1][i] = 0;
        
        for(int i = size - 1; i > 0; i--) {
            for(int j = 0; j < range; j++) {
                if(T[i] > j + 30) {
                    mem[i - 1][j] = 1;
                } else {
                    if(mem[i][j] != 0)
                        mem[i - 1][j] = mem[i][j] + 1;
                    else
                        mem[i - 1][j] = 0;
                }
                
            }
        }
        
        int[] res = new int[size];
        for(int i = 0; i < size; i++) {
            res[i] = mem[i][T[i] - 30];
        }
        
        return res;
    }
}