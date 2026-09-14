class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0, r = heights.size() - 1;
        int res = INT_MIN;
        while ( l <r ){
            int lval = heights[l], rval = heights[r], minval = min(lval,rval);
            int area = minval * (r-l);
            res = max(area, res);
            if (minval == lval) l++;
            else r--;
        }
        return res;
    }
};
