class segmentTree{
  public:
    vector<int>v;
    
    void init_segmentTree(vector<int>&nums)
    {
        int n=nums.size();
        int x = (int)(ceil(log2(n))); 
        int max_size = 2*(int)pow(2, x) - 1; 
  
  
        v=vector<int>(max_size,0);    
    }
    int buildTree(vector<int> &nums,int curr,int l,int r)
    {
        if(l==r)
        {
            v[curr]=nums[l];
            return nums[l];
        }
        int mid=l + (r -l)/2;
        return v[curr]=buildTree(nums,2*curr+1,l,mid)+buildTree(nums,2*curr+2,mid+1,r);
        
    }
    void updateTree(int curr,int idx,int l,int r,int &val)
    {
        if(idx<l||idx>r)return;
        
        v[curr]+=val;
        if(l!=r)
        {
            updateTree(2*curr+1,idx,l,(l+r)/2,val);
            updateTree(2*curr+2,idx,(l+r)/2+1,r,val);            
        }

    }
    int get(int curr,int l,int r,int s,int e)
    {
        if(e<l||s>r)return 0;
        
        if(s<=l&&e>=r)return v[curr];
        
        return get(2*curr+1,l,(l+r)/2,s,e)+get(2*curr+2,(l+r)/2+1,r,s,e);
        return 1;
    }
    
};

class NumArray {
public:
    
    segmentTree st;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums=vector<int>(nums);
        st.init_segmentTree(nums);
        st.buildTree(nums,0,0,nums.size()-1);
    }

    void update(int index, int val) {
        int newVal=val-nums[index];
        nums[index]=val;
        st.updateTree(0,index,0,nums.size()-1,newVal);
    }
    
    int sumRange(int left, int right) {
        return st.get(0,0,nums.size()-1,left,right);
        return 0;
    }
};

