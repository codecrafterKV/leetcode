class Solution(object):

  def restoreIpAddresses(self, s):
    """
        :type s: str
        :rtype: List[str]
        """
    res = []

    # A valid IPv4 string must have between 4 and 12 digits
    if len(s) < 4 or len(s) > 12:
      return res

    def backtrack(start, parts):
      # Base case: 4 parts formed
      if len(parts) == 4:
        if start == len(s):
          res.append('.'.join(parts))
        return

      # Try candidate parts of lengths 1, 2, and 3
      for length in range(1, 4):
        if start + length > len(s):
          break

        segment = s[start : start + length]

        # Leading zeros are invalid (unless the segment is just "0")
        if len(segment) > 1 and segment[0] == '0':
          continue

        # Value must be between 0 and 255
        if int(segment) > 255:
          continue

        parts.append(segment)
        backtrack(start + length, parts)
        parts.pop()

    backtrack(0, [])
    return res