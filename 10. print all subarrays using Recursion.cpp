#include <iostream>
#include<vector>
using namespace std;

void printSubArray_util(vector<int>&nums, int start, int end)
{
  //base case 
  if(end==nums.size())
  {
    return;
  }

  for(int i=start; i<=end; i++)
  {
    cout<<nums[i]<<" ";
  }
  cout<<endl;


  //recursive call
  printSubArray_util(nums,start,end+1);
  
}

int main() {
  
  vector<int>nums{1,2,3,4,5};
  
  for(int start=0; start<nums.size(); start++)
  {
    int end = start;
    printSubArray_util(nums,start,end);
  }

  return 0;
}
