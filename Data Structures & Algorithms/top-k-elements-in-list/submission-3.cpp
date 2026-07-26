class Solution {
   public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        // store key, frequency values in hashmap -> put them in priority queue->return top k
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(n + 1);
        for (auto ele : mp) {
            buckets[ele.second].push_back(ele.first);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (buckets[n - i].size() != 0) {
                for (auto p : buckets[n - i]) {
                    if (count == k) return ans;
                    ans.push_back(p);
                    count++;
                }
            }
        }
        return ans;
    }
};