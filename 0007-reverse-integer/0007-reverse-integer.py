class Solution(object):

  def reverse(self, x):
    """
        :type x: int
        :rtype: int
        """
    sign = -1 if x < 0 else 1
    x = abs(x)

    res = 0
    limit = 2**31 - 1 if sign == 1 else 2**31

    while x != 0:
      pop = x % 10
      x //= 10

      # Check for 32-bit signed integer overflow before pushing
      if res > limit // 10 or (res == limit // 10 and pop > limit % 10):
        return 0

      res = res * 10 + pop

    return sign * res
        