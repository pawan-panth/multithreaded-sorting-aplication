#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int a[100];
int b[100];
int c[100];
int d[100];
void * sort1(void *param1);
void *sort2(void *param3);
void *merge(void *param2);
struct ex{
	int  start;
	int end;
};
int main(int argc,char * argv[])
{
	struct ex ex1,ex2;
	int num=argc-1;
	pthread_t t1,t2,t3;
	for(int  i=0;i<argc-1;i++)
	{
       a[i]=atoi(argv[i+1]);
	}
	ex1.start=0;
	ex1.end=num/2;
	ex2.start=num/2;
	ex2.end=num;
	pthread_create(&t1,NULL,sort1,(void *)&ex1);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,sort2,(void *)&ex2);
	pthread_join(t2,NULL);
	//pthread_create(&t3,NULL,merge,(void *)&num);
	//pthread_join(t3,NULL);
	for(int i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
}
void *sort2(void *param1)
{

	int temp;
	struct ex *ex3=param1;
	for(int i=0,j=ex3->start;i<ex3->end;i++,j++)
	{
		d[i]=a[j]; 
	}
	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		printf("%d\n",d[i] );
	}

	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		for(int j=0;j<ex3->end-ex3->start-1;j++)
		{
			if(d[j]>d[j+1])
			{
				temp=d[j+1];
				d[j+1]=d[j];
				d[j]=temp;
			}
		}

	}
	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		printf("%d\n",d[i] );
	}

} 
void *sort1(void *param1)
{

	int temp;
	struct ex *ex3=param1;
	for(int i=0,j=ex3->start;i<ex3->end;i++,j++)
	{
		c[i]=a[j];
	}
	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		printf("%d\n",c[i] );
	}

	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		for(int j=0;j<ex3->end-ex3->start-1;j++)
		{
			if(c[j]>c[j+1])
			{
				temp=c[j+1];
				c[j+1]=c[j];
				c[j]=temp;
			}
		}

	}
	for(int i=0;i<ex3->end-ex3->start;i++)
	{
		printf("%d\n",c[i] );
	}

} 
void *merge(void *param3)
{
	int *a=(int *)param3;
	for(int i=0,j=0;i<a/2;i++,j++)
	{
		if(a[i]<a[j])
		{
			b[i];
		}
	}

}
