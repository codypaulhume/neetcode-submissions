class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
        // [value, index]
        unordered_map<int, int> myMap;
        int index = 0;
        for(auto i : nums){
            myMap[i] = index;
            index++;
        }
        // Calculate the complement for each iteration. If found, return the indices.
        // Make sure that the index does not match
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            auto toFind = myMap.find(complement);

            if(toFind != myMap.end() && toFind->second != i){
                result.push_back(i);
                result.push_back(myMap[complement]);
                return result;
            }
        }
        return {};
    }
};
