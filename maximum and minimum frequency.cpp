// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void freq(int arr[], int n)
{
    unordered_map<int,int>mp;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int ans1, ans2;
    
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it: mp)
    {
        if(maxi<it.second)
        {
            maxi = it.second;
            ans1 = it.first;
        }
        
        if(mini>it.second)
        {
            mini = it.second;
            ans2 = it.first;
        }
    }
    
    cout<<"maximum frequency element:"<<ans1<<endl;
    cout<<"minimum frequency element:"<<ans2<<endl;
}

int main() {
    // Write C++ code here
    
    int arr[] = {2,2,3,4,4,2};
    int n = 6;
    freq(arr,n);

    return 0;
}
