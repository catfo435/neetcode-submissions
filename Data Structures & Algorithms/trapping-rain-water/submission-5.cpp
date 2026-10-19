class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l=0, r=height.size() - 1, maxL = height[l], maxR = height[r];
        while (l < r){
            if (maxL > maxR){
                maxR = max(maxR, height[--r]);
                res += maxR - height[r];
            }
            else{
                maxL = max(maxL, height[++l]);
                res += maxL - height[l];
            }
        }
        return res;
    }
};