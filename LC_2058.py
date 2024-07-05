# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        ans = [-1,-1]
        i=0; f=0; pre=0; pv=0
        while head.next != None:
            if i==0:
                pv = head.val
                head = head.next
                i += 1
                continue
            x = head.val; y = head.next.val
            if (x<pv and x<y) or (x>pv and x>y):
                if f==0:
                    f = i
                else:
                    if ans[0] == -1:
                        ans[0] = i-pre
                    else:
                        ans[0] = min(ans[0], i-pre)
                    ans[1] = i-f
                pre = i
            pv = x
            head = head.next
            i += 1
        return ans