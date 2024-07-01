class Solution(object):
    def threeConsecutiveOdds(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        n = len(arr)
        if n<3: return 0
        for i in range(n):
            if i==0 or i==1:
                continue
            else:
                if arr[i]%2==1 and arr[i-1]%2==1 and arr[i-2]%2==1:
                    return 1
        return 0