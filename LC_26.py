class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 1; j = 1
        for i in range (len(nums)):
            if i and nums[i] != nums[i-1]: 
                ans += 1
                nums[j] = nums[i]
                j += 1
        return ans