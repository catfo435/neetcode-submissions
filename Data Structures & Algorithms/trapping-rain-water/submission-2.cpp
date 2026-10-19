class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rB = {0}, lB = {0}, revinput(height.rbegin(), height.rend());
        for (int i : height){
            lB.push_back(max(lB.back(), i));
        }
        lB.pop_back();
        for (int i : revinput){
            rB.push_back(max(rB.back(), i));
        }
        rB.pop_back();
        reverse(rB.begin(), rB.end());

        int res = 0;
        for (int i=0;i<height.size();i++){
            int water = min(lB[i], rB[i]) - height[i];
            res += water > 0 ? water : 0;
        }
        return res;
    }
};
