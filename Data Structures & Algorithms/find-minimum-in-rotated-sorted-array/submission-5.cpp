class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        int mid;
        // int k = 5;
        while (l <= r) {
            mid = l + (r-l)/2;
            if(l == mid && r == mid)break;
            cout << mid << " ";
            if(nums[mid]>nums[r])
            {
                cout << "ye";
                l = mid+1;
            }
            else r = mid;
        }
        return nums[l];
    }
};
