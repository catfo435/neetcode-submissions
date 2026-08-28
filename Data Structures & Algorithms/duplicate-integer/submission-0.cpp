class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto i: nums){
            if (m[i]) return true;
            m[i] = 1;
        }
        return false;
    }
};