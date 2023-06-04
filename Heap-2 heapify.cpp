#include <iostream>
#include <algorithm>
using namespace std;

//heapify
void heapify(int arr[], int n, int i)
{
  int index = i;
  int leftIndex = 2*i;
  int rightIndex = 2*i + 1;
  int largest = index;

  if(leftIndex<=n && arr[largest]<arr[leftIndex])
  {
    largest = leftIndex;
  }
  if(rightIndex<=n && arr[largest]<arr[rightIndex])
  {
    largest = rightIndex;
  }


  if(index!=largest){
    //left or right child > current node
    swap(arr[index],arr[largest]);
    index = largest;
    heapify(arr,n,index);
      
  }
}


//build heap
  void buildHeap(int arr[], int n)
{
  for(int i=n/2; i>0; i--)
    {
      heapify(arr, n, i);
    }
}


//heap sort
void heapSort(int arr[], int n)
{
  int index = n;
  while(n != 1)
    {
      swap(arr[1], arr[index]);
      index--;
      n--;

      heapify(arr,n,1);
    }
}

int main() {

  
  int arr[] = {-1,12,15,13,11,14};
  int n = 5;
  
  //build heap
  buildHeap(arr, n);
  cout<<"printing heap for build heap"<<endl;
  for(int i=0; i<=n; i++)
    {
      cout<<arr[i]<<" ";
    }
  cout<<endl;


//heap sort
  heapSort(arr, n);
  cout<<"heap sort printing"<<endl;
  for(int i=0; i<=n; i++)
    {
      cout<<arr[i]<<" ";
    }
  cout<<endl;
    
  
  
  
  
}
