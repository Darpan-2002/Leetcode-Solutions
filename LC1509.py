class Solution(object):
    def minDifference(self, a):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(a)
        if n<5: return 0
        a.sort()
        ans = a[n-4] - a[0]
        ans = min(ans, a[n-3] - a[1])
        ans = min(ans, a[n-2] - a[2])
        ans = min(ans, a[n-1] - a[3])
        return ans















