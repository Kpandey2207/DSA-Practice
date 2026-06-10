class Solution {
public:
    vector<int> leftSum(vector<int>& nums){
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=0;
        for(int i=0;i<n-1;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        return prefix;
    }
    vector<int> rightSum(vector<int>& nums){
        int n=nums.size();
        vector<int>prefix(n);
        prefix[n-1]=0;
        for(int i=n-1;i>0;i--){
            prefix[i-1]=prefix[i]+nums[i];
        }
        return prefix;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ls=leftSum(nums);
        vector<int> rs=rightSum(nums);
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]= abs(ls[i]-rs[i]);
        }
        return nums;
    }
};