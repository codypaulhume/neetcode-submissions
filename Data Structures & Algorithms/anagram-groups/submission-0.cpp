class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> result;

        // Sort each word
        for(auto word : strs){
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            myMap[sorted].push_back(word);
        }
        for(auto e : myMap){
            result.push_back(e.second);
        }
        return result;
    }
};
