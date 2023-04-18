#include <iostream>
using namespace std;

int search(int arr[], int N, int X)
  {
        
        // Your code here
        for(int i=0; i<N; i++)
        {
            if(arr[i]==X)
            {
                return i;
            }
        }
        
        return -1;
        
  }

int main() {
  int n = 4;
  int arr[] = {1,2,3,4};
  int x = 3;

  cout<<search(arr,n,x);
  return 0;
}