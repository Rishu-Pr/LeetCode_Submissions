class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        freqs = {}
        for ch in s:
            freqs[ch] = freqs.get(ch,0) + 1
        for i in range(len(s)):
            if freqs[s[i]] == 1:
                return i
        
        return -1
        