#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
ll fact[N+1];
ll modinv[N+1];
int mod = 1e9+7;
// Mod inverse
ll power(ll base,ll pow)
{
    if(pow<0) return 0;
    ll ans = 1;
    while(pow)
    {
        if(pow%2==0)
        {
            base = (base*base)%mod;
            pow/=2;
        }
        else{
            ans = (ans*base)%mod;
            pow-=1;
        }
    }
    return ans;
}
void precomp()
{
    fact[0]=1;
    modinv[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        modinv[i] = power(fact[i],mod-2);
    }
}
ll ncr(ll n,ll r)
{
    //if(r>n )  return 0;
    ll numo = fact[n];
    ll den = (modinv[r]*modinv[n-r])%mod;
    return (numo*den)%mod;
}
void solve()
{
    precomp();
    ll N,M,k;
    cin>>N>>M>>k;
    
    ll sum = 0;
    
    while(k--)
    {
        int n,m;
        ll p;
        cin>>n>>m>>p;
        
        // First special cell
        ll ans = 1;
        ll total = n+m-2;
        ll r = n-1;
        // after special cell
        ll t = N+M-n-m;
        ll tr = M-m;

        ans =( (ans%mod) *  (ncr(total,r)%mod))%mod;
        ans = ((ans%mod) * (ncr(t,tr)%mod))%mod;
        ans = ((ans%mod) *(p%mod))%mod;
        sum = ((sum%mod)+(ans%mod))%mod;
        //cout<<sum<<" ";
    }
    sum = (sum%mod);
    cout<<sum<<endl;
    
}
int main()
{
   solve();

    return 0;
}
