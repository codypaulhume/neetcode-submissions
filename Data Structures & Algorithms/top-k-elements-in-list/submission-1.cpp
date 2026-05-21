class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //[number, frequency]
        unordered_map<int, int> myMap;

        for(int i = 0; i < nums.size(); i++){
            myMap[nums[i]]++;
        }
        
        // Create a vector pair and reverse sort based on the frequency (e.second)
        vector<pair<int, int>> arr;
        for(auto e : myMap){
            arr.push_back({e.second, e.first});
        }

        //Sort the array
        sort(arr.rbegin(), arr.rend());

        vector<int> result;

        // Return the number (not the frequency)
        for(int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }

        return result;
    }
};
