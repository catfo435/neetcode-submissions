class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0;i<nums.size();i++) {
            int remaining_val = target - nums[i];
            if (m.count(remaining_val) && m[remaining_val] != i) return { m[remaining_val], i };
            m[nums[i]] = i;
        }
    }
};
