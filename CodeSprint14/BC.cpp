#include <iostream>
using namespace std;



inline int getbit(int elm, int bit){  
  return (elm>>bit)%2;
}


int main(){
  int N;
  int count = 0;
  cin>>N;
  int elm;
  for(int i=0;i<N;i++){
    cin>>elm;
    for(int bit=0;bit<31;bit++)
      count += getbit(elm,bit);
  }
  if(count%2 || N == 1)
    cout<<"Shaka :)"<<endl;
  else
    cout<<"The other player :("<<endl;  
  return 0;
}