class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        h = []
        for i in range(len(heights)):
            h.append(heights[i])
        h.sort()
        ans = 0
        for i in range(len(h)):
            if(heights[i] != h[i]):
                ans += 1
        return ans