class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0; cur = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cur += 1
            else:
                if cur > ans: ans = cur
                cur = 0
        if cur > ans: ans = cur
        return ans