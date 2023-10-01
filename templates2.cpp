#include<iostream>
#include<algorithm>
using namespace std;
template <typename T>
T arr_max(T arr[],int n)
{
  T res=arr[0];
  for(int i=0;i<n;i++)
  {
      if(arr[i]>res)
      res=arr[i];
  }
  return res;
}


int main()
{
 int arr1[]={10,8,9,100};
 cout<<arr_max<int>(arr1,4);
 return 0;
}