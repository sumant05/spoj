#include<bits/stdc++.h>
using namespace std;

class BadNeighbors{
    int dp[42]={0};
    bool one[42]={0};
public:
    int maxDonations(vector<int> &v);
};

int BadNeighbors::maxDonations(vector<int> &v)
{
    dp[0]=v[0];
    dp[1]=v[1];
    int n=v.size(),m=-10;
    for(int i=2;i<n-1;i++)
    {
        for(int j=0;j<i-1;j++)
        {
            if(dp[j]+v[i]>dp[i])
            {
                dp[i]=dp[j]+v[i];
                if(j==0)
                    one[i]=1;
            }
        }
    }
    for(int i=1;i<n-2;i++)
    {
        if(dp[i]+v[n-1]>dp[n-1])
        {
            if(!one[i])
                dp[n-1]=dp[i]+v[n-1];
            else
                dp[n-1]=dp[i]+v[n-1]-v[0];
        }
    }
    for(int i=0;i<n;i++)
        m=max(dp[i],m);
    return m;
}

int main(){
    vector<int> a;
    int x,n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x,a.push_back(x);
    BadNeighbors b;
    cout<<b.maxDonations(a)<<endl;
    return 0;
}
