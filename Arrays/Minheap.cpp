#include<iostream>
#include<queue>
#include<vector>
// #include<priority_queue>
using namespace std;

int main()
{   std::vector<int> array;
//   array[]=[8,5,2,9,7,6,3];
array.push_back(8);
array.push_back(5);
array.push_back(2);
array.push_back(9);
array.push_back(7);
array.push_back(6);
array.push_back(3);
    int k=3;
    priority_queue<int>minheap;
  for(auto it:array){
    minheap.push(it);
    cout<<minheap.top()<<"Top"<<endl;
    if(minheap.size()>k){
      cout<<"----st--"<<endl;
      cout<<minheap.top()<<endl;
      minheap.pop();
      cout<<minheap.top()<<endl;
      cout<<"---end----"<<endl;
    }    
  }
}