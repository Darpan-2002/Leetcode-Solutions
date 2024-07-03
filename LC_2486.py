class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        n = len(s); m = len(t)
        j = 0
        for i in range(n):
            if s[i] == t[j]: 
                j += 1
            if j == m:
                break
        return m-j