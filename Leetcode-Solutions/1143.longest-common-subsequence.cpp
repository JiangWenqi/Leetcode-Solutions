/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.98%)
 * Likes:    7132
 * Dislikes: 77
 * Total Accepted:    447.5K
 * Total Submissions: 758.7K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 *
 *
 * Example 1:
 *
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 *
 * Example 3:
 *
 *
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    //     a b c d e
    //   0 0 0 0 0 0
    // a 0 1 1 1 1 1
    // c 0 1 1 2 2 2
    // e 0 1 1 2 2 3
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
