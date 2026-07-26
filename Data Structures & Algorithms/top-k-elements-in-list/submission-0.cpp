class Solution {
    public : 
        vector<int> topKFrequent(vector<int> nums, int k) {
        // store key, frequency values in hashmap -> put them in priority queue->return top k
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        for (auto ele : mp) {
            pq.push({ele.second, ele.first});
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};