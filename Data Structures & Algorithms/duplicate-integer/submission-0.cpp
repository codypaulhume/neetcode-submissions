class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> myMap;
        for(auto number : nums){
            if(myMap.find(number) == myMap.end()){
                myMap[number];
            }
            else{
                return true;
            }
        }
        return false;
    }
};