// AC   Greedy solutin
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct cstmr{
int s;
int f;
int p;
};
cstmr a[100005];
bool comp(cstmr l,cstmr r)
{
    if(l.p==r.p)
        return(l.f<r.f);
    else
        return(l.p<r.p);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,n,k,c,ft,cur;
    cin>>t;
    while(t--)
    {
        c=1,cur=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i].s>>a[i].f>>a[i].p;
        if(n==0||n==1)
        {
            cout<<n<<endl;
            continue;
        }
        sort(a,a+n,comp);
        ft=a[0].f;
        for(int i=1;i<n;i++)
        {
            if(a[cur].f<=a[i].s&&a[i].p==a[i-1].p)
                c++,cur=i;
            else if(a[i-1].p!=a[i].p)
            {
                cur=i;
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
