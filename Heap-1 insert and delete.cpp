#include <iostream>
#include <algorithm>
using namespace std;

class Heap{

  public:
  int arr[101];
  int size;

  Heap()
{
  size = 0;
  
}


void insert(int value)
{
  //value insert at end
  size = size +1;
  int index = size;
  arr[index] = value;

  //value place at correct position
  while(index>1)
    {
      int parentIndex = index/2;
      if(arr[index]>arr[parentIndex])
      {
        swap(arr[index], arr[parentIndex]);
        index = parentIndex;
      }
      else{
        break;
      }
    }
}

int deleteHeap()
{
  int ans = arr[1];
  //[A] eplace root node value with last node data
  arr[1] = arr[size];
  size--;

  //[B] place root node date on correct place
  int index = 1;
  while(index<size)
    {
      int leftIndex = 2*index;
      int rightIndex = 2*index+1;

      int largest = index;

      if(leftIndex<size && arr[largest]<arr[leftIndex])
      {
        largest = leftIndex;
      }
      if(rightIndex<size && arr[largest]<arr[rightIndex])
      {
        largest = rightIndex;
      }

      if(largest==index)
      {
        //value is at correct position
        break;
      }
      else
      {
        swap(arr[index],arr[largest]);
        index = largest;
      }
      
    }
  return ans;
}

};



int main() {

  Heap h;
  h.arr[0]=-1;
  h.arr[1]=100;
  h.arr[2]=50;
  h.arr[3]=60;
  h.arr[4]=40;
  h.arr[5]=45;
  h.size = 5;

  cout<<"printing the heap: "<<endl;
  for(int i=0; i<=h.size; i++)
    {
      cout<<h.arr[i]<<" ";
    }
  cout<<endl;

  h.insert(110);
  cout<<"printing the heap after insertion: "<<endl;
  for(int i=0; i<=h.size; i++)
    {
      cout<<h.arr[i]<<" ";
    }
  cout<<endl;

  h.deleteHeap();
  cout<<"printing the heap after deletion: "<<endl;
  for(int i=0; i<h.size; i++)
    {
      cout<<h.arr[i]<<" ";
    }
  cout<<endl;



 
    
  
  
  
  
}
