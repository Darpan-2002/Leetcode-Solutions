# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        sum=0; f=1
        t = head; pre = None
        while t != None:
            if t.val == 0:
                if pre != None:
                    pre.val = sum
                    pre.next = t.next
                    sum = 0
                    f=1
            else:
                sum += t.val
                if f==1:
                    pre = t
                    f = 0
            t = t.next
        return head.next