class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string ,vector <string>> anagram;

        for(string str: strs){
            string ch = str;
            sort(ch.begin(),ch.end());
            anagram[ch].push_back(str);
        }
        vector<vector<string>> result;
        for (auto pair : anagram) {
            result.push_back(pair.second);
        }

        return result;
    }
};