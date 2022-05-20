/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (64.14%)
 * Likes:    4192
 * Dislikes: 144
 * Total Accepted:    524.9K
 * Total Submissions: 818.4K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution
{

private:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int idx, int n, int k)
    {
        if (!k)
        {
            res.push_back(path);
            return;
        }

        for (int i = idx; i <= n; i++)
        {

            path.push_back(i);
            dfs(i + 1, n, k - 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(1, n, k);
        return res;
    }
};
// @lc code=end
