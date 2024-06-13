class Solution(object):
    def minMovesToSeat(self, seats, students):
        """
        :type seats: List[int]
        :type students: List[int]
        :rtype: int
        """
        ans = 0
        seats.sort()
        students.sort()
        for i in range(len(seats)):
            ans += abs(seats[i] - students[i])
        return ans