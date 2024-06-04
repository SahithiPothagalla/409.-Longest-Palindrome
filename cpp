class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52);
        for (char c : s) {
            if (c > 96 && c < 123)
                freq[c - 'a']++;
            else
                freq[c - 'A' + 26]++;
        }
        int maxOdd = 0;
        int even = 0;
        for (int i : freq) {
            if (i % 2 == 0)
                even += i;
            else {
                if (i > maxOdd) {
                    if (maxOdd)
                        even += maxOdd - 1;
                    maxOdd = i;
                }
                else {
                    even += i - 1;
                }
            }
        }
        return even + maxOdd;
    }
};
