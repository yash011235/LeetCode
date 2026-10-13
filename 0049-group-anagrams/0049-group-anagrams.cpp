class Solution {
public:
    string hashIt(string &s){
        vector<int>freq(26, 0);
        for(char &c : s){
            freq[c - 'a']++;
        }
        string key;
        for(int i = 0; i < 26; i++){
            key += to_string(freq[i] + '#');
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mp;
        for(int i = 0; i < n; i++){
            mp[hashIt(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto &[num, v] : mp){
            res.push_back(v);
        }
        return res;
    }
};