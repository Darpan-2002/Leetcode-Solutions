from collections import Counter
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        mp = Counter(nums)
        j=0
        for i in range(mp[0]):
            nums[j] = 0
            j += 1

        for i in range(mp[1]):
            nums[j] = 1
            j += 1

        for i in range(mp[2]):
            nums[j] = 2
            j += 1
             

        