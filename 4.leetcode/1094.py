# 1094.	Car Pooling    

class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        # road capacities
        road = [0 for _ in range(1001)]
        
        for trip in trips:
            for i in range(trip[1],trip[2]):
                road[i]+=trip[0]
                if road[i] > capacity:
                   return False
    
        return True
                
        