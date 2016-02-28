#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  int min,max,i,range,r,x;
  unsigned first = time(NULL);

  cout<<"First = " << first << endl;
  srand(first);
  cout<<"Enter the minimum number : ";
  cin>>min;
  cout<<"Enter the maximum number : ";
  cin>>max;
  cout<<"Enter the number of terms you want : ";
  cin>>x;

  range=max-min+1;

  for(i=0;i<x;i++)
  {
    r=rand()/100%range+min;
    cout<<r<<" ";
  }
  std::cout << std::endl;
}
