class Solution {
public:

    string encode(vector<string>& strs) {
        vector<int> str_lens;
        for (auto i : strs) str_lens.push_back(i.size());

        string res = "";
        for (int i=0;i<strs.size();i++){
            res += to_string(str_lens[i]) + "%" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        bool str_rd_mod = false;
        int len = 0;
        string tmp = "";
        for (auto i : s){
            if (!str_rd_mod && i == '%'){
                if (!len){
                    res.push_back(tmp);
                    continue;
                }
                str_rd_mod = true;
                len /= 10;
                continue;
            }
            if (!str_rd_mod){
                len += i - '0';
                len *= 10;
            }
            else{
                tmp.push_back(i);
                if (str_rd_mod && !--len){
                str_rd_mod = false;
                res.push_back(tmp);
                tmp.clear();
            }
            }
        }
        return res;
    }
};
