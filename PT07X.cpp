#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define gc getchar_unlocked
using namespace std;
vector<int > tree[100002];
int dp[100002][2];    //where dp[node][0]     node's parent is not selected 
                       //dp[node][1]      node's parent is selected
 void scanint(int &x)
  {
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
  }
int solve(int u,int par,int selected)
 {
 	
 	int &ret =dp[u][selected];
 	 if(ret!=-1)
 	 return ret;
 	 ret=0;
 	 if(selected)
 	  {
 	     for(int i=0;i<tree[u].size();i++)
 	       {
 	         if(tree[u][i]!=par)
 	           {
 	             ret=ret+solve(tree[u][i],u,0);   	
 	           }
 	       }
 	       int r=1;
 	        for(int i=0;i<tree[u].size();i++)
 	       {
 	         if(tree[u][i]!=par)
 	           {
 	             r=r+solve(tree[u][i],u,1);   	
 	           }
 	       }
 	        return ret=min(ret,r);
 	  }
 	  ret=1;
 	  for(int i=0;i<tree[u].size();i++)
 	   {
 	   	  if(tree[u][i]!=par)
 	     ret=ret+solve(tree[u][i],u,1);	
 	   }
 	   return ret;
 }
int main() {
   int n,u,v;
   scanint(n);
     for(int i=0;i<n-1;i++)
     {
         scanint(u);scanint(v);
         tree[u].pb(v);
         tree[v].pb(u);
     }
    memset(dp,-1,sizeof(dp));
    /* for(int i=1;i<=n;i++)
     {
       printf("i=%d ",i);
        for(int j=0;j<2;j++)
        {
        	printf(" j = %d ",j);
         printf("%d  ",dp[i][j]);
        }
         printf("\n");
     }
     */
       int ret=1;
      for(int i=0;i<tree[1].size();i++)
      {
      	  ret=ret+solve(tree[1][i],1,1);
      }
        int r=0;
        for(int i=0;i<tree[1].size();i++)
        {
        	r=r+solve(tree[1][i],1,0);
        }
        printf("%d",min(r,ret));
    return 0;
}
