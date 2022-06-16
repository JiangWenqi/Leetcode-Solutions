#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 *
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
 *
 * algorithms
 * Medium (57.94%)
 * Likes:    2227
 * Dislikes: 33
 * Total Accepted:    82.2K
 * Total Submissions: 141.8K
 * Testcase Example:  '4\n[[0,1],[0,2],[1,2]]'
 *
 * There are n computers numbered from 0 to n - 1 connected by ethernet cables
 * connections forming a network where connections[i] = [ai, bi] represents a
 * connection between computers ai and bi. Any computer can reach any other
 * computer directly or indirectly through the network.
 *
 * You are given an initial computer network connections. You can extract
 * certain cables between two directly connected computers, and place them
 * between any pair of disconnected computers to make them directly connected.
 *
 * Return the minimum number of times you need to do this in order to make all
 * the computers connected. If it is not possible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, connections = [[0,1],[0,2],[1,2]]
 * Output: 1
 * Explanation: Remove cable between computer 1 and 2 and place between
 * computers 1 and 3.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
 * Output: -1
 * Explanation: There are not enough cables.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * 1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
 * connections[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * There are no repeated connections.
 * No two computers are connected by more than one cable.
 *
 *
 */

// @lc code=start
const int N = 100010;
class Solution {
 private:
  int p[N];
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }

 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    int redundantCables = 0, isolateUnion = 0;

    // 1. init the union find
    for (int i = 0; i < n; i++) p[i] = i;

    // 2. link nodes
    for (auto& connection : connections) {
      int x = connection[0], y = connection[1];
      // if they are not in same union, just link them
      if (find(x) != find(y)) p[find(x)] = find(y);
      // if they are already in same union, it means we have one more cable
      else
        redundantCables++;
    }

    // 3. check the number of isolate union
    for (int i = 0; i < n; i++) {
      if (p[i] == i) isolateUnion++;
    }
    // 4. compare the number of redundant cables and isolateUnion
    if (redundantCables < isolateUnion - 1)
      return -1;
    else
      return isolateUnion - 1;
  }
};
// @lc code=end
