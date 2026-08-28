class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for (char i:s) m[i]++;
        for (char i:t){
            m[i]--;
            if (!m[i]) m.erase(i);
        }
        return m.empty();
    }
};