class Solution(object):
    def minIncrementForUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            if i==0:
                continue
            if nums[i] <= nums[i-1]:
                ans += nums[i-1] - nums[i] + 1
                nums[i] = nums[i-1] + 1
        return ans