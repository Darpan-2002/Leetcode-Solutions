from collections import Counter
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        count = Counter(arr1)
        ans = []
        for num in arr2:
            ans.extend([num] * count[num])
            del count[num]
        for num in sorted(count.elements()):
            ans.append(num)
        return ans
