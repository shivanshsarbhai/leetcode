class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int two = n-1;  
        int zero = 0;

        while(curr<=two){
            if(nums[curr]==0){
                swap(nums[curr], nums[zero++]);
                curr++;
            }
            else if(nums[curr]==2)
                swap(nums[curr], nums[two--]);
            else
                curr++;
        }
    }
};