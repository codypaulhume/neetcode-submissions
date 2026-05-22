class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int, index
        unordered_map<int,int> myMap;
        vector<int> result;

        for(int i = 0; i < numbers.size(); i++){
            int complement = target - numbers[i];
            if(myMap.count(complement)){
                result.push_back(myMap[complement]);
                result.push_back(i+1);
            }
            myMap[numbers[i]] = i + 1;
        }

        return result;
    }
};
