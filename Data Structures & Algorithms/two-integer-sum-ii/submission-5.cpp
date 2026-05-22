class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int, index
        unordered_map<int,int> myMap;
        vector<int> result;

        // Iterate through numbers array. If it exists within, push index (value) into result.
        // Otherwise add it to map (with the index + 1 since thats what the problem wants ig)
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
