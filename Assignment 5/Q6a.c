
#include <stdio.h>
int n,m;
int a[100];
int count=0;

int merge(int l,int m,int r){
	
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	int inv=0;
	int i=0,j=0,k=l;
	for(i=0;i<n1;i++)L[i]=a[l+i];
	for(i=0;i<n2;i++)R[i]=a[m+1+i];
	i=0;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else {
			a[k]=R[j];
			j++;
			inv+=(m-i+1);
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
	return inv;
}

int sort(int l,int r){
	int c;
	if(r>l){
		int m=(l+r)/2;
		
		c=sort(l,m);
		c+=sort(m+1,r);
		c+=merge(l,m,r);
		
	}
	return c;
	
}


int main(void) {
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	count=sort(0,n-1);
	printf("%d\n",count);
	for(i=0;i<n;i++)printf("%d ",a[i]);
	
	return 0;
}