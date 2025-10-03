🔹 Problem: Two Sum 

You are given an array of integers nums and an integer target.
Return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9

🔹 Solution in C++

We can solve it using a hash map (unordered_map) to store visited numbers and their indices.
This gives O(n) time.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }

        return {}; // just in case, though problem guarantees one solution
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);
    cout << "[" << ans[0] << ", " << ans[1] << "]\n";
    return 0;
}

🔎 Explanation

Iterate over nums.

For each nums[i], compute the required complement target - nums[i].

If complement exists in the map → we found the answer.

Otherwise, store nums[i] with its index in the map.

✅ Time Complexity: O(n)
✅ Space Complexity: O(n)
