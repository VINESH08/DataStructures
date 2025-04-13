#include <vector>
#include<iostream>
using namespace std;

void subarraySort(vector<int> array,vector<int>&result) {
  // Write your code here.
//   vector<int>result;
  int smallnumb=INT_MAX;
  int largenumb=INT_MIN;
  for(int i=1;i<array.size();i++){
    if(array[i]-array[i-1]<0&&array[i]<smallnumb){
      smallnumb=array[i];
    }
    
      
  }
  cout<<smallnumb<<endl;
  for(int j=0;j<array.size()-1;j++){
    if(array[j]-array[j+1]>0&&array[j]>largenumb)
      largenumb=array[j];
  }
  cout<<largenumb<<endl;
  int smallidx=-1;
  int largeidx=-1;
  for(int i=0;i<array.size();i++){
    if(array[i]>smallnumb){
      smallidx=i;
      break;
    }
  }
   for(int i=0;i<array.size();i++){
    
    if(array[i]>largenumb){
      largeidx=i-1;
      break;
    }
  }
  if(largenumb!=INT_MIN&&largeidx==-1){
    largeidx=array.size()-1;
  }
    result.push_back(smallidx);
    result.push_back(largeidx);
  
  
}
int main(){
    std::vector<int> array;
    //  "array": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2]

    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    array.push_back(11);
    array.push_back(12);
    array.push_back(13);
    array.push_back(14);
    array.push_back(15);
    array.push_back(16);
    array.push_back(17);
    array.push_back(18);
    array.push_back(19);
    array.push_back(2);
    vector<int>result;
    subarraySort(array,result);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    
}