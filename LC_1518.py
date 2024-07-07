class Solution(object):
    def numWaterBottles(self, x, y):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        return x + ((x-1)//(y-1))