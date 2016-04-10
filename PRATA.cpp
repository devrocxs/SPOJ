#include<bits/stdc++.h>
#define gc getchar_unlocked
#define ll long long
using namespace std;
//THIS GUY IS VERY COOL...    :'D
ll p,l,r[50];
void scanint(ll &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
bool isposs(ll x)   
 {
 	 ll cnt=0;
     	for(int i=0;i<l;i++)
     	{
          cnt=cnt+(ll)(((ll)(sqrt(r[i]*r[i]+8*r[i]*x))-r[i])/(2*r[i]));	
     	   	if(cnt>=p)
     	return true;
     	}
     	return false;
 }
ll bin()
{
	ll low=1,mid,high=5005000;
	while(low<high)
	{
		mid=(low+high)/2;
		if(isposs(mid))
		{
		 high=mid;	
		}
		else
		low=mid+1;
	}
	return high;
}
int main()
 {
 	ll t;
 	scanint(t);
 	while(t--)
 	 {
 	  	scanint(p);scanint(l);
 	  	for(int i=0;i<l;i++)
 	  	scanint(r[i]);
 	  	printf("%lld\n",bin());
 	 }
 	return 0;
 }  
