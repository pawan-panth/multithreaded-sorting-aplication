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
	pthread_create(&t3,NULL,merge,(void *)&num);
	pthread_join(t3,NULL);
	for(int i=0;i<num;i++)
	{
		printf("%d \n",b[i]);
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
		printf("****%d\n",d[i] );
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
		printf("***%d\n",c[i] );
	}

} 
void *merge(void *param3)
{
	int *a=(int *)param3;
	int i=0;
	int j=0;
	int k=0;
	int ld=*a/2;
	int lc=*a-ld;
	while (i <ld && j <lc)
    {
        if (d[i] <= c[j])
        {
            b[k] = d[i];
            i++;
        }
        else
        {
            b[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < ld)
    {
        b[k] = d[i];
        i++;
        k++;
    }
    while (j < lc)
    {
        b[k] = c[j];
        j++;
        k++;
    }
    
}
