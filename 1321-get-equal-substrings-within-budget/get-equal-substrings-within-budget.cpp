class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            diff.push_back(abs(s[i] - t[i]));
        }
        int left = 0, sum = 0, maxLen = 0;
        for (int right = 0; right < diff.size(); right++) {
            sum += diff[right];
            while (sum > maxCost && left <= right) {
                sum -= diff[left];
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};