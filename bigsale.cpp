#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
int countcustomer(vector<int> bill)
{
    int count=0;
    for(int i=0;i<bill.size();i++)
    {
        if(isPerfectSquare(bill[i]))
            count++;
         
    }
    return count;


}
int main()
{
  vector<int> v;
 return 0;
}