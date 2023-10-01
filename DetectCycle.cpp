#include<bits/stdc++.h>
using namespace std;

string Delete_l(string s,int l)
{   string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(i==l-1)
            continue;
        ans+=s[i];
    }
    return ans;
}
string flip(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            s[i]='1';
        else if(s[i]=='1')
            s[i]='0';
    }
    return s;
}

int main()
{ 
    //  int n=3;
        // cin >> n;
        int n=3;
        // cin >> n;
        string s="101";
        // cin >> s;
        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zeros++;
            else
                ones++;
        }
        cout << (min(zeros, ones) + 1) / 2 << endl;
    
    return 0;
}