class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty()) {
            return 0;
        }

        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            int start = i;
            int end = i;

            while (end < s.length() && s.substring(start, end).indexOf(s.charAt(end)) == -1) {
                end++;
            }
            if (max < end - start) {
                max = end - start;
            }
        }
        return max;
    }
}