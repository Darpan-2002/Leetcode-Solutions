class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        ans = 0
        if x > y:
            top = "ab"
            t1 = x
            bot = "ba"
            t2 = y
        else:
            top = "ba"
            t1 = y
            bot = "ab"
            t2 = x
        stack = []
        for c in s:
            if c==top[1] and stack and stack[-1] == top[0]:
                ans += t1
                stack.pop()
            else:
                stack.append(c)
        stack2 = []
        for c in stack:
            if c==bot[1] and stack2 and stack2[-1] == bot[0]:
                ans += t2
                stack2.pop()
            else:
                stack2.append(c)
        return ans