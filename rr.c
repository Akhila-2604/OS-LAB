#include<stdio.h>
#include<stdlib.h>
void enqueue(int );
void dequeue();
struct k{
int x,y;
};
/*
0 4
1 5
2 6
3 3
4 1
5 4
*/
int ct,l=0,a[100],over=1,tq,n,visited[10],b[10];
struct k s[10];
struct node{
	int data;
	struct node *next;
}*front=NULL,*nn,*rear=NULL,*temp;
struct node*create(int data){
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	return nn;
}
void sort(struct k s[10],int n){
	int i,j;
	struct k temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++ ){
		  if(s[i].x>s[j].x ){//|| (s[j].x>s[j+1].x && s[j].p==s[j+1].p) ){
		  	temp=s[j];
		  	s[j]=s[i];
		  	s[i]=temp;
		  }	
		}  
	}
	
}
void dequeue(){
	temp=front;
	int i,j;
	if(rear==NULL && front==NULL)
	return ;
	else if(front==rear){
		i=front->data;
		a[l]=i;
		l++;
		front=NULL;
		rear=NULL;
	}
	else{
		i=front->data;
		a[l]=i;
		l++;
	front=front->next;
	free(temp);	
}
if(s[i].y<=tq){
	ct=ct+s[i].y;
		
	s[i].y=0;
	b[i]=ct;
	//p++;	
	}
	else{
	    ct=ct+tq;
		s[i].y=s[i].y-tq;
			
}
	for(j=0;j<n;j++){
		
		if(s[j].x<=ct && i!=j && s[j].y!=0 && visited[j]==-1){
			enqueue(j);
			
		}
	}
	if(s[i].y!=0)
	enqueue(i);
	//printf("hi");
	//while(over!=0)
	dequeue();

}
void enqueue(int i){
	int j;
	nn=create(i);
	if(rear==NULL && front==NULL){
	rear=nn;
	front=nn;
	visited[i]=1;
}
else{
rear->next=nn;
rear=rear->next;
visited[i]=1;
}
}
int main(){
	int i,index,min=9999,tat[10],wt[10],bt[10];
float avg_tat=0.0,avg_wt=0.0;
	
	printf("enter n");
	scanf("%d",&n);
	ct=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	printf("enter time quantum");
	scanf("%d",&tq);
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
	for(i=0;i<n;i++)
	bt[i]=s[i].y;
	//printf("%d",min);
	if(s[index].x!=0)
	ct=s[index].x;
	enqueue(index);
	sort(s,n);
	
	
	dequeue();
	for(i=0;i<l;i++)
	printf("%d ",a[i]);
	
	for(i=0;i<n;i++){
	    tat[i]=b[i]-s[i].x;
	    wt[i]=tat[i]-bt[i];
	    avg_tat=avg_tat+tat[i];
	    avg_wt=avg_wt+wt[i];
	}
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d %d %d\n",b[i],tat[i],wt[i]);
	printf("%.2f %.2f",avg_tat/n,avg_wt/n);
	
}

