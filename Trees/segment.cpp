/* You are given a sequence A of N (N <= 50000) integers between -10000 and 10000.
On this sequence you have to apply M (M <= 50000) operations:
modify the i-th element in the sequence or for given x y print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.  */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct tr{
	ll sum,lsum,rsum,ans;
};

ll ar[100001];
tr seg[400001];

tr merge(tr a,tr b){
	tr k;
	k.sum=a.sum+b.sum;
	ll m=max(b.ans,a.rsum+b.lsum);
	k.ans=max(m,a.ans);
	k.lsum=max(a.lsum,a.sum+b.lsum);
	k.rsum=max(b.rsum,b.sum+a.rsum);
	return k;
}

void build(ll pos,ll l,ll h){
	if(l==h){
		seg[pos].sum=seg[pos].lsum=seg[pos].rsum=seg[pos].ans=ar[l];
		return;
	}
	ll b=(l+h)/2;
	build(2*pos,l,b);
	build(2*pos+1,b+1,h);
	seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
	return;
}

tr get(ll pos,ll l,ll h,ll st,ll en){
	if(l>en || h<st){
		tr k={-10001,-10001,-10001,-10001};
		return k;
	}
	if(st<=l && en>=h){
		return seg[pos];
	}
	ll b=(l+h)/2;
	return merge(get(2*pos,l,b,st,en),get(2*pos+1,b+1,h,st,en));
}

void sett(ll pos,ll l,ll h,ll i,ll x){
	if(l==h){
		ar[l]=x;
		seg[pos].sum=seg[pos].lsum=seg[pos].rsum=seg[pos].ans=x;
		return;
	}
	ll b=(l+h)/2;
	if(i<=b){
		sett(2*pos,l,b,i,x);
	}
	else{
		sett(2*pos+1,b+1,h,i,x);
	}
	seg[pos]=merge(seg[2*pos],seg[2*pos+1]);
	return;
}

	int main(){
		ios_base::sync_with_stdio(0);
  	    cin.tie(0);
  	    cout.tie(0);
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>ar[i];
		}
		build(1,1,n);
		ll m;
		cin>>m;
		for(ll i=1;i<=m;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			if(a==1){
				cout << get(1,1,n,b,c).ans << "\n";
			}
			else{
				sett(1,1,n,b,c);
			}
		}
		return 0;
	}