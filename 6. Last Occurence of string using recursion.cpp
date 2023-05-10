#include <bits/stdc++.h>
using namespace std;

void lastOccurence(string &str, char x, int i, int &ans)
{
  //base case
  if(i>str.size())
  {
    return;
  }

  if(str[i]==x)
  {
    ans=i;
  }
  lastOccurence(str,x,i+1,ans);
}

int main() {
  string str = "abcddedg";
  char x = 'd';
  int ans = -1;
  int i =0;
  lastOccurence(str,x,i,ans);
  cout<<ans<<endl;

  return 0;
}
