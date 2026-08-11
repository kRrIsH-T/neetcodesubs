class Solution {
   public:
    int binsrch(vector<int>& nums, int l, int r, int tgt) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == tgt)
                return mid;
            else if (nums[mid] < tgt)
                l = mid + 1;
            else if (nums[mid] > tgt)
                r = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        int mid = 0;
        while((target<nums[l] || target > nums[r]) && l<r)
        {
            mid = l + (r-l)/2;
            if(target<nums[l]){
                l++;
                continue;
            }
            if(target>nums[r]) r--;
        }
        return binsrch(nums,l,r,target);
    }
};
