#include<stdio.h>
#include<stdlib.h>
struct k{
int x,y;
}s[100],temp;
int l,ct,n,a[10],visited[10];
void sort(){
int i,j,t;
	for(i=0;i<l-1;i++){
		for(j=i+1;j<l;j++){
			if(s[a[i]].y>s[a[j]].y){
			t=a[j];
			a[j]=a[i];
			a[i]=t;
			}
		}
	}
	for(i=0;i<l;i++)
	printf("%d",a[i]);
	printf("\n");
}
void array(){
l=0;
int i;
	for(i=0;i<n;i++){
		if(s[i].x<=ct && visited[i]==-1){
		a[l]=i;
		l++;
		}
	}
}
int main(){
int i,j=0,index,gc[10],o=0,min=999,cmptym[10],tat[10],wt[10];
float avg_tat=0.0,avg_wt=0.0;
l=0;
printf("enter n value");
scanf("%d",&n);
printf("enter arrival and burst times");
	for(i=0;i<n;i++){
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	for(i=0;i<n;i++)
		visited[i]=-1;
	for(i=0;i<n;i++){
		if(s[i].x<min){
			min=s[i].x;
			index=i;
		}
		if(s[i].x==min){
		     if(s[i].y<s[index].y){
		          min=s[i].x;
		          index=i;
		     }
		}
	}
	ct=s[index].y;
	gc[o]=index;
	o++;
	visited[index]=1;
	while(o!=n){
		l=0;
		array();
		sort();
		ct+=s[a[0]].y;
		gc[o]=a[0];
		o++;
		visited[a[0]]=1;
		}
	for(i=0;i<n;i++){
		printf("%d",gc[i]);
	}
	l=0;
	if(s[index].x!=0){
	ct=s[index].x;
	printf("\n0-%d is ideal",ct);
	}
	for(i=0;i<n;i++){
	    cmptym[i]=ct+s[gc[i]].y;
	    ct=cmptym[i];
	    tat[i]=cmptym[i]-s[i].x;
	    wt[i]=tat[i]-s[i].y;
	    avg_tat=avg_tat+tat[i];
	    avg_wt=avg_wt+wt[i];
	}
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d %d %d\n",cmptym[i],tat[i],wt[i]);
	printf("%.2f %.2f",avg_tat/n,avg_wt/n);
}	
}
