class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> myMap;
        unordered_map<char, int> myMapTwo;
        for(char c : s){
            if(myMap.find(c) != myMap.end()){
                myMap[c]++;
            }else{
                myMap[c] = 1;
            }
        }
        for(char c : t){
            if(myMap.find(c) != myMap.end()){
                myMapTwo[c]++;
            }else{
                myMapTwo[c] = 1;
            }
        }
        for(char c : t){
            if(myMap[c] != myMapTwo[c]){
                return false;
            }
        }   
        return true;
    }
};
