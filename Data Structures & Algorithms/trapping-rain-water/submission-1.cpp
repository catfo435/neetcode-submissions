class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rB = {0}, lB = {0}, revinput(height.rbegin(), height.rend());
        int prev = 0;
        for (int i : height){
            prev = max(prev, i);
            lB.push_back(prev);
        }
        lB.pop_back();
        prev = 0;
        for (int i : revinput){
            prev = max(prev, i);
            rB.push_back(prev);
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
