#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  float PA,R,Time,CI;
  cout<<"Enter Principle ammout : ";
  cin>>PA;
  cout<<"\n";
  cout<<"Enter rate : ";
  cin>>R;
  cout<<"\n";
  cout<<"Enter time in years : ";
  cin>>Time;

  //Formula to calculate compound intrest
  CI=PA*pow((1+R/100),Time) - PA;
  cout<<"Compound intrest is : "<<CI;

  cout<<"\n";
  return 0;
}
