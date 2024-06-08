class Solution(object):
    def checkSubarraySum(self, nums, k):
        n = len(nums)
        sum = 0
        mp = {}
        for i in range(n):
            sum += nums[i]
            rem = sum%k
            if rem == 0 and i>0:
                return 1

            if rem in mp:
                if i-mp[rem] > 1:
                    return 1
                
            else:
                mp[rem]=i
        
        return 0