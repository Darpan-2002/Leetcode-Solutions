import heapq

class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """
        n = len(profits)
        vp = [(capital[i], profits[i]) for i in range(n)]
        vp.sort()
        pq = []
        ind = 0
        for i in range(k):
            while (ind < n and vp[ind][0] <= w):
                heapq.heappush(pq, -vp[ind][1])
                ind += 1
            if not pq:
                break
            w -= heapq.heappop(pq)
        return w