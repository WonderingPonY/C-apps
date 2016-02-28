#include <iostream>

using namespace std;

int main()
{
  long int num;

  cout<<"Enter a number to get multiplication table : ";
  cin>>num;

  for(int a=1;a<=10;a++)
    cout<<num<<" * "<<a<<" = "<<num*a<<endl;

  return 0;
}
