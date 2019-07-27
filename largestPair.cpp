#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LargestPair(int num) { 
    int index,temp=0,maxCounter=0;
    vector <int> numList;
    while(num>0){
        int temp=num%10;
        num/=10;
        numList.push_back(temp);
    }
    //numlist 1234
    //original 4321
    vector <int> orgional;
    for(int i=0;i<numList.size();i++){
        index=numList[(numList.size()-i-1)];
        orgional.push_back(index);
        //cout<<orgional[i]<<" ";
    }
    sort(numList.begin(),numList.end());
    temp=numList[numList.size()-1];
    if(orgional[orgional.size()-1]==temp){
        temp=numList[numList.size()-2];
        //cout<<temp<<endl;
    }
    index=0;
    for(int i=0;i<orgional.size()-1;i++){
        if (temp==orgional[i]){
            maxCounter++;
            if(maxCounter>1){
                if(orgional[i+1]>=orgional[index+1]){
                    index=i;
                }
            }
            else{
                index=i;
            }
        }
    }
    cout<<orgional[index]<<"   "<<orgional[index+1]<<endl;
    num=orgional[index]*10+orgional[index+1];
    return num;
}

int main() { 
  // keep this function call here
  //only works for int range +-2147483647, else, i got core dumped segmentation fault
  cout << LargestPair(2147483647);
  return 0;
}
