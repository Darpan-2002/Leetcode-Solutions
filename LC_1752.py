class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ct = 0
        for i in range(len(nums)):
            if nums[i] > nums[(i+1)%len(nums)]:
                ct += 1
        if ct==1: return True
        return False 