class Solution(object):
    def search(self, a, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        n = len(a)
        lo = 0; hi = n-1
        # while lo+1<n and a[lo] == a[lo+1]:
        #     lo += 1
        while hi>lo and a[0] == a[hi]:
            hi -= 1
        n = hi+1
        while lo <= hi:
            mid = (lo+hi)/2
            if a[mid] == target:
                return True
            if a[mid] >= a[0]:
                if a[0]<=target and a[mid]>=target: 
                    hi = mid-1
                else: 
                    lo = mid+1
            else:
                if a[n-1]>=target and a[mid]<=target:
                    lo = mid+1
                else:
                    hi = mid-1
        return False
    