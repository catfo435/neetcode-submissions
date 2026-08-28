class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_map;
        vector<vector<string>> result;
        for (auto str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            str_map[temp].push_back(str);
        }
        
        for (auto str_pair: str_map) result.push_back(str_pair.second);
        return result;
    }
};
