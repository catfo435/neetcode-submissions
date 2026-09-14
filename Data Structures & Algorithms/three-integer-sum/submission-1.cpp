class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i=0;i<nums.size()-2;i++){
            if (i && nums[i] == nums[i-1]) continue; // we would have computed all posibilities already for this number
            int twoSum = 0 - nums[i];
            int l = i + 1, r = nums.size() - 1, sum;
            while(l < r){
                sum = nums[l] + nums[r];
                if (sum == twoSum) {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    //check if [a, b] exists again, ignore if it does, since there is only
                    // once c which can fulfill a + b + c = 0
                    do{
                        l++;
                    }
                    while(l < r && nums[l] == nums[l-1]);
                }
                if (sum > twoSum) r--;
                else if (sum < twoSum) l++;
            }
            
        }
        return res;
    }
};
