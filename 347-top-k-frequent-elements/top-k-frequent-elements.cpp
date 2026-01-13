class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }

     
        vector<pair<int, int>> sortedList;
        for (auto p : map) {
            sortedList.push_back({p.second, p.first});
        }

      
        sort(sortedList.rbegin(), sortedList.rend());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(sortedList[i].second);
        }

        return result;
    }
};