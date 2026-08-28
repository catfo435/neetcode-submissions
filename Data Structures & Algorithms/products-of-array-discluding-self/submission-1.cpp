class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_prod = 1;
        bool z1 = false;
        for (auto i : nums){
            if (z1 && !i){
                return vector<int>(nums.size(), 0);
            }
            if (!i){
                z1= true;
                continue;
            }
            total_prod *= i;
        }

        vector<int> res;
        for (auto i : nums) {
            if (i && z1) res.push_back(0);
            else if (!i && z1) res.push_back(total_prod);
            else res.push_back(total_prod/i);
        }
        return res;
    }
};
