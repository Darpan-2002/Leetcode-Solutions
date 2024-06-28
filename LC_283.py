class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 0
        for j in range(len(nums)):
            if j==0: continue
            if nums[i] == 0 and nums[j] != 0:
                nums[i] = nums[j]
                nums[j] = 0
                i += 1
            elif nums[i] != 0:
                i += 1