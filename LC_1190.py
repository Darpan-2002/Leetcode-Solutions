class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        st = []
        for i in range(n):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                j = st.pop()
                s = s[:j+1] + s[j+1:i+1][::-1] + s[i+1:]
        ans = ""
        for i in range(n):
            if s[i] != '(' and s[i] != ')':
                ans += s[i]
        return ans