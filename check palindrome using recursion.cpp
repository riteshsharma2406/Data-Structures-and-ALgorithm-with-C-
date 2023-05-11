#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &str, int i, int j)
{
  //base case
  if(i>=j)
  {
    return true;
  }


  //logic
  if(str[i]!=str[j])
  {
    return false;
  }
  
  return checkPalindrome(str,i+1, j-1);

}

int main() {
  string str;
  cin>>str;

  int i = 0;
  int j = str.size()-1;

  if(checkPalindrome(str,i,j))
  {
    cout<<"string is a palindrome"<<endl;
  }
  else
  {
    cout<<"not a palindrome"<<endl;
  }

  return 0;
}
