class Solution {
public:
int merge(vector<int> &nums,int i,int m,int j)
{
int l=i;
int r=m;

int n=j-i+1;
    int res = 0 ;

vector<int> arr(n);

int k=0;
    
while(r<=j&&l<m)
{
    if(nums[l]>((long)nums[r])*2)  
    {
        res+=m-l;
        r++ ;
    }
    else 
        l++ ;   
    
}
    
r=m;
l=i;
    
while(l<m&&r<=j)
{
    if(nums[l]>nums[r])
        arr[k]=nums[r++];
    else arr[k]=nums[l++];
    
    k++;
}

while(l<m)
    arr[k++]=nums[l++];
    
while(r<=j)
    arr[k++]=nums[r++];
    
for(k=0;k<n;k++)
    nums[i+k]=arr[k];
    
return res ;
}


int divide(vector<int>& nums,int i,int j)
{
    int res = 0 ;
if(i<j)
{
    int mid=(i+j)/2;
    
    res += divide(nums,i,mid);
    res += divide(nums,mid+1,j);
    
    
    res += merge(nums,i,mid + 1,j);
    
}
    return res ;
}


int reversePairs(vector<int>& nums) 
{
    int res = divide(nums,0,nums.size()-1);
    
    return res;
}
};