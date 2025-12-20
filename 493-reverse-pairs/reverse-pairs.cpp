class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        
        vector<int> temp(high - low + 1);
        int left = low, right = mid + 1, k = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp[k++] = nums[left++];
            else
                temp[k++] = nums[right++];
        }

        while (left <= mid) temp[k++] = nums[left++];
        while (right <= high) temp[k++] = nums[right++];

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int countpairs(vector<int>& nums, int low, int mid, int high) {
        int cnt=0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergesort(vector<int>& nums, int low, int high) {
        int cnt=0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt+=mergesort(nums, low, mid);
        cnt+=mergesort(nums, mid + 1, high);
        cnt+=countpairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        cnt+=mergesort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
