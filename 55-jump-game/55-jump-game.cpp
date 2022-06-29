class Solution {
public:
bool canJump(vector<int>& nums) {
		int n = nums.size();
		int mx = 0;
		for(int i=0;i<n;i++){
			if(mx >= i){
				mx = max(mx,i + nums[i]);
			}
			else{
				return false;
			}
		}
		return true;
	}
};