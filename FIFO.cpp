#include<stdio.h>
int main()
{
	int incomingStream[40];
	int pageFaults = 0;
	int frames = 3;
	int m,n,s,pages;
	printf("enter no.of pages:");
	scanf("%d",&pages);
	printf("enter elements:");
	for(m=0;m<pages;m++)
	{
		scanf("%d",&incomingStream[m]);
	}
//ages=sizeof(incomingStream)/sizeof(incomingStream[0]);
	printf("Incoming \tFrame 1\tFrame 2\tFrame 3\t");
	
	int temp[frames];
	
	for(m=0;m<frames;m++)
	{
		temp[m]=-1;
	}
	
	for(m=0;m<pages;m++)
	{
		s=0;
		for(n=0;n<frames;n++)
		{
			if(incomingStream[m]==temp[n])
			{
				s++;
				pageFaults--;
			}
			
		}
		pageFaults++;
		if((pageFaults <= frames) && (s==0))
		{
			temp[m]= incomingStream[m];
		}
		
		else if(s==0)
		{
			temp[(pageFaults-1) % frames]= incomingStream[m];
		}
		printf("\n");
		printf("%d\t\t\t",incomingStream[m]);
		for(n=0;n<frames;n++)
		{
			if(temp[n] != -1)
			printf("%d\t\t\t",temp[n]);
			else
			printf("-\t\t\t");
			
		}
		
	}
	printf("\nTotal page Faults:\t%d\n",pageFaults);
	return 0;
}
