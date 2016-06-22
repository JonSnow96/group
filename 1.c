#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CEN 3
#define POINTS 100
struct point
{
	int x,y,a,dist;
}points[POINTS];
struct centers
{
	int x,y;
}c[CEN];
main()
{
	int d,temp,i,j,totalx,totaly,avgx,avgy,count,flag=1;
	srand(time(NULL));
	for(i=0;i<POINTS;i++)
	{
		points[i].x=rand()%1000;
		points[i].y=rand()%1000;
	//	printf("%d %d\n",points[i].x,points[i].y);
	}
//	printf("\n\n");
	for(i=0;i<CEN;i++)
	{
		c[i].x=rand()%1000;
		c[i].y=rand()%1000;
	}
	while(flag)
	{
		flag=0;
		for(i=0;i<POINTS;i++)
		{
			d=999999;
			for(j=0;j<CEN;j++)
			{
				if((temp=(int)sqrt(((points[i].x-c[j].x)*(points[i].x-c[j].x))+((points[i].y-c[j].y)*(points[i].y-c[j].y))))<d)
				{	
					d=temp;
					points[i].a=j;
					points[i].dist=temp;
				}
			}
		}
		for(j=0;j<CEN;j++)
		{
			totalx=totaly=avgx=avgy=count=0;
			for(i=0;i<POINTS;i++)
			{
				if(points[i].a==j)
				{
					totalx=totalx+points[i].x;
					totaly=totaly+points[i].y;
					count++;
				}
			}
			avgx=(int)totalx/count;
			avgy=(int)totaly/count;
			if(c[j].x!=avgx||c[j].y!=avgy)
			{
				c[j].x=avgx;
				c[j].y=avgy;
				flag=1;
			}
		}
//	for(i=0;i<CEN;i++)
//		printf("%d %d\n",c[i].x,c[i].y);
	}
	for(i=0;i<CEN;i++)
		printf("%d %d\n",c[i].x,c[i].y);
}

