// horrible accepted sol
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define LL long long
using namespace std;
LL st[400007],lazy[400007];

void update(LL node,LL s,LL e,LL i,LL j,LL v)
{
    if(lazy[node])
    {
        st[node]+=(e-s+1)*lazy[node];
        if(s!=e)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s > j || e < i)
		return;
    if(s >= i&&e<=j)
    {
        st[node]+=(e-s+1)*v;
        if(s!=e)
        {
            lazy[2*node+1]+=v;
            lazy[2*node+2]+=v;
        }
    }
    else{
    update(2*node+1,s,(s+e)/2,i,j,v);
    update(2*node+2,(s+e)/2+1,e,i,j,v);

    st[node]=st[2*node+1]+st[2*node+2];
    }
}
LL query(LL node,LL s,LL e,LL i,LL j)
{
    if(lazy[node])
    {
        st[node]+=(e-s+1)*lazy[node];
        if(s!=e)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<s)
        return 0;
    if(i <= s&&e<=j)
        return st[node];
    LL q1,q2;
    q1=query(2*node+1,s,(s+e)/2,i,j);
    q2=query(2*node+2,(s+e)/2+1,e,i,j);
    return (q1+q2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    LL t,n,q,k,a1,b,c;
    cin>>t;
    while(t--)
    {
        memset(st,0,sizeof st);
        memset(lazy,0,sizeof lazy);
        cin>>n>>q;
        while(q--)
        {
            cin>>k;
            if(k==0)
            {
                cin>>a1>>b>>c;
                update(0,0,n-1,a1-1,b-1,c);
            }
            else
            {
                cin>>a1>>b;
                cout<<query(0,0,n-1,a1-1,b-1)<<"\n";
            }
        }
    }
    return 0;
}
