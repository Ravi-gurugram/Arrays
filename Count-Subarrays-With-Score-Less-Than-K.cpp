class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans =0; long long sum=0 ;
        long long score =0 ;

        int st=0, end=0;
        while(end<nums.size()){
            sum+=nums[end];
            score= sum*(end-st+1) ;
            while(score>=k&&st<=end){
                sum-=nums[st] ;
                st++ ;
                score= sum*(end-st+1) ;
                

            }
           
               ans+= (end-st+1) ;
            end++ ;    
        }
  return ans ;
    }
};