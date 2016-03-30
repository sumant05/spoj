#include<bits/stdc++.h>
using namespace std;
class ZigZag{
    int g[1002]={0};
    int s[1002]={0};
public:
    int longestZigZag(vector<int> &v);
};
int ZigZag::longestZigZag(vector<int> &v)
{
    int n=v.size(),m=-10;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
                g[i]=max(1+s[j],g[i]);
            else if(v[i]<v[j])
                s[i]=max(1+g[j],s[i]);
        }
    }
    for(int i=0;i<n;i++)
        m=max(m,s[i]);
    for(int i=0;i<n;i++)
        m=max(m,g[i]);
    return m+1;
}

