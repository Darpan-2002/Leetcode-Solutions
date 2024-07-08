class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        return (self.findTheWinner(n-1, k) + (k-1))%n + 1 if n>1 else 1