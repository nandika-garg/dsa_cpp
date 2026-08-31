class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        quicksort(nums, low, high);
        return nums;
    }
    void quicksort(vector<int>& nums, int low, int high){
        if (low<high){
            int p=partition(nums, low, high);
            quicksort(nums, low, p-1);
            quicksort(nums, p+1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high ){
        int x = low + rand() % (high - low + 1);
        int pivot=nums[x];
        swap(nums[x], nums[high]);
        int i=low-1;
        for (int j=low; j<high; j++){
            if (nums[j]<pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
};