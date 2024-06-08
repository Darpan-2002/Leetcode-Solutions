class Solution(object):
    def clearDigits(self, s):
        ind = []
        ans = ""
        n = len(s)
        for i in range(n):
            if s[i]>='0' and s[i]<='9':
                ind.pop()
            else:
                ind.append(i)
        for i in range(len(ind)):
            ans += s[ind[i]]
        return ans