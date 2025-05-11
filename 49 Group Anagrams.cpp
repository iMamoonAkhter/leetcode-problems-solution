
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        const int n = strs.size();
        
        for (int i = 0; i < n; i++) {
            string key = generateKey(strs[i]);
            groups[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            result.push_back(it->second);
        }
        
        return result;
    }
    
private:
    string generateKey(const string& s) {
        int count[26] = {0};
        const int len = s.length();
        
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
        }
        
        string key;
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i]) + "#";
        }
        
        return key;
    }
};