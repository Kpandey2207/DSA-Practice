class Solution {
public:
    int removeElement(vector<int>& nums,int val) {
        sort(nums.begin(),nums.end());

        int start=-1,end=-1;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]==val) {
                start=i;

                while(i<nums.size()&&nums[i]==val)
                    i++;

                end=i-1;
                break;
            }
        }

        if(start==-1)
            return nums.size();

        int diff=end-start+1;

        for(int i=start;i+diff<nums.size();i++) 
            nums[i]=nums[i+diff];

        return nums.size()-diff;
    }
};