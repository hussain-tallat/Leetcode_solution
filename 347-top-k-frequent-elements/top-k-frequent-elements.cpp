class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (count.find(num) != count.end()) {
                count[num] = count[num] + 1;  // increase count
            } else {
                count[num] = 1;               // first time seen
            }
        }

        // Step 2: Find top k frequent numbers
        vector<int> result;

        while (result.size() < k) {
            int maxFreq = 0;
            int maxNum = 0;

            // Loop through the map to find number with maximum frequency
            for (auto it = count.begin(); it != count.end(); it++) {
                int num = it->first;
                int freq = it->second;
                if (freq > maxFreq) {
                    maxFreq = freq;
                    maxNum = num;
                }
            }

            // Add the number with highest frequency to result
            result.push_back(maxNum);

            // Set its count to 0 so it won't be picked again
            count[maxNum] = 0;
        }

        return result;
    }
};
