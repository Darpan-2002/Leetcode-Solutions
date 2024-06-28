class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        s1 = ""
        for i in range(n):
            if s[i] >= 'a' and s[i] <='z':
                s1 += s[i]
            elif s[i] >= '0' and s[i] <='9':
                s1 += s[i]
            elif s[i] >= 'A' and s[i] <='Z':
                s1 += s[i]
        s1 = s1.lower()
        # print(s1)
        i = 0; j = len(s1)
        while i < j :
            if s1[i] != s1[j]:
                return False
            i += 1
            j -= 1
        return True