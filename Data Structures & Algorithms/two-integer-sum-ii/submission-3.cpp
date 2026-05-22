class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int, index
        unordered_map<int,int> myMap;
        int index = 1;

        for(auto i : numbers){
            myMap[i] = index;
            index++;
        }

        vector<int> result;

        for(auto e : myMap){
            int complement = target - e.first;
            if(myMap.find(complement) != myMap.end()){
                if(e.second < myMap[complement]){
                    result.push_back(e.second);
                    result.push_back(myMap[complement]);
                    return result;
                }else{
                    result.push_back(myMap[complement]);
                    result.push_back(e.second);
                    return result;
                }
            }
        }

        return result;
    }
};
