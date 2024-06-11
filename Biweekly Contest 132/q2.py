class Solution(object):
    def findWinningPlayer(self, skills, k):
        """
        :type skills: List[int]
        :type k: int
        :rtype: int
        """
        tm = k
        ans = 0
        if skills[0]<skills[1]:
            ans = 1
        tm -= 1
        if tm==0:
            return ans
        for i in range(len(skills)):
            if i<2:
                continue
            if skills[i] < skills[ans]:
                tm -= 1
            else:
                tm = k-1
                ans = i
            
            if tm==0:
                return ans
        return ans
