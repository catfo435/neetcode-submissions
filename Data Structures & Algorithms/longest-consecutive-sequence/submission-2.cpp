class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0, len = 0, curr;
        for (auto i : nums){
            len = 0;
            if (!s.contains(i - 1)){
                len = 1;
                curr = i;
                while (s.contains(++curr)){
                    len++;
                }
            }
            maxi = max(len, maxi);
        }
        return maxi;
    }
};
