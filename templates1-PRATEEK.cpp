// #include <iostream>
// using namespace std;
// template <typename T>
// T my_max(T x, T y)
// {
//     return ((x > y) ? x : y);
// }
// int main()
// {
//     cout << my_max<int>(3, 5) << endl;
//     cout << my_max<float>(8.6, 5.8) << endl;
//     cout << my_max<char>('s', 'g') << endl;
//     cout << my_max<string>("z", "zabcdefgh") << endl;
// }
#include<bits/stdc++.h>
using namespace std;
    vector<long long> NSR(int arr[], int n)
{
  vector<long long> Right;
  stack<pair<int, int>> S1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (S1.size() == 0)
      Right.push_back(n);

    else if (S1.size() > 0 && S1.top().first < arr[i])
      Right.push_back(S1.top().second);

    else if (S1.size() > 0 && S1.top().first >= arr[i])
    {
      while (S1.size() > 0 && S1.top().first >= arr[i])
      {
        S1.pop();
      }
      if (S1.size() == 0)
        Right.push_back(n);
      else
        Right.push_back(S1.top().second);
    }
    S1.push({arr[i], i});
  }
  reverse(Right.begin(), Right.end());
  return Right;
}
vector<long long> NSL(int arr[], int n)
{
  vector<long long> Left;
  stack<pair<int, int>> S2;
  for (int i = 0; i < n; i++)
  {
    if (S2.size() == 0)
      Left.push_back(-1);

    else if (S2.size() > 0 && S2.top().first < arr[i])
      Left.push_back(S2.top().second);

    else if (S2.size() > 0 && S2.top().first >= arr[i])
    {
      while (S2.size() > 0 && S2.top().first >= arr[i])
      {
        S2.pop();
      }
      if (S2.size() == 0)
        Left.push_back(-1);
      else
        Left.push_back(S2.top().second);
    }
    S2.push({arr[i], i});
  }
  //  reverse(Right.begin(),Right.end());
  return Left;
}

    long long getMaxArea(int arr[], int n)
    {
        // Your code here
        vector<long long> Left=NSL(arr,n);
        vector<long long> Rigth=NSR(arr,n);
        vector<long long> Width;
        vector<long long> area;
        for(int i=0;i<n;i++)
        {
            Width.push_back(Rigth[i]-Left[i]-1);
            area.push_back(Width[i] * arr[i]);
        }
        long long ans= *max_element(area.begin(),area.end());
        return ans;
    }
int main()
{
//     int n = 7;
//   int arr[7] = {6, 2, 5, 4, 5, 1, 6};
int N = 8;
int arr[8] = {7, 2, 8, 9, 1, 3, 6, 5};
  cout<<getMaxArea(arr,N);
 return 0;
}