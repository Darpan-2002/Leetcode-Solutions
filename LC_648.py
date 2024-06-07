class Solution(object):
    def replaceWords(self, a, s):
        n = len(a)
        m = len(s)
        mp = set(a)
        f = False
        ans = ""
        t = ""
        for i in range(m):
            if f and s[i] != ' ':
                if i == m - 1:
                    ans += t
                continue

            if s[i] == ' ':
                ans += t
                ans += ' '
                t = ""
                f = False
            else:
                t += s[i]

            if t in mp:
                f = True

            if i == m - 1:
                ans += t

        return ans