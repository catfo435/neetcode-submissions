class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;   // descending by frequency
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i : nums) mp[i]++;

        vector<pair<int,int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), cmp);

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(freq[i].first);
        }

        return res;
    }
};