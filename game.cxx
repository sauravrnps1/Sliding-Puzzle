#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int position[2]={0};
 

void display(int arr[3][3]);
void rungame(int arr[3][3]);
int* tracker(int n,int arr[3][3]);
int win(int arr[3][3]);
void update(int n,int arr[3][3]);






void rungame(int arr[3][3]){
	
	int n;
	int x,y;
	
	printf("\n\n");
	display(arr);

	printf("enter numbers between 1 to 8 and Press 0 to endGame\n");
	printf("Game starts now !\n");
	
 	while(win(arr)==0 ){
		x=tracker(0,arr)[0];
		y=tracker(0,arr)[1];
		
		scanf("%d",&n);
		printf("\n\n");
		if (n<0 || n>8){
			printf("invalid input, enter again :\n");
			continue;}
		if (n==0)
		break;
		
		if ((tracker(n,arr)[0]==x && abs(y-tracker(n,arr)[1])==1) || (tracker(n,arr)[1]==y && abs(x-tracker(n,arr)[0])==1))
		{
		update(n,arr);
		display(arr);
		printf("\n\n");
		continue;
		
		
		}
		else
		{
			printf("Not possible , try different number : \n");
			
			continue;
		}
		
	}
	if(win(arr)==1)
	{
		printf("you won");
	}
	else
	{
		printf("better luck next time :)\n\n\n");
	}
		
}
			
		
		
	
void display(int  arr[3][3])
{
	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]==0)
			{
				printf("    ");
				continue;
				}
			printf("%d   ",arr[i][j]);
		}
	printf("\n");
	}
}
int* tracker(int n,int arr[3][3])
{
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if (arr[i][j]==n){
				position[0]=i;
				position[1]=j;
				return position;
			}
	    }
	}
}
		
		void update(int n,int arr[3][3])
		{
         int i=tracker(n,arr)[0];
         int j=tracker(n,arr)[1];
         int k=tracker(0,arr)[0];
         int l=tracker(0,arr)[1];


			arr[i][j]=0;
			arr[k][l]=n;
		}
int win(int arr[3][3])
		{
			if(arr[2][2]!=0)
			return 0;
			int min=arr[0][0];
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if((min>arr[i][j]) && !(i==2 & j==2))
					{
						return 0;
					}
					min=arr[i][j];
				}
			}
			return 1;
		}



int exists(int a,int arr[3][3])
{
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         if(arr[i][j]==a)
         return 1;
      }
   }
   return 0;
}

void matrix_setter(int arr[3][3])
{
srand(time(0)); 
   int num;
   for (int i = 0; i < 3; i++) {
      for(int j=0;j<3;j++){
         int a=(rand() % 9) + 0;
         while(exists(a,arr))
         {
            a=(rand() % 9) + 0;
         }
         
         arr[i][j]=a;

      } 
   }

}


					
int main()
{
	//int arr[3][3]={{1,2,3},{4,5,6},{7,8,0}};   //winning case for testing

	printf("\n\nLoading.....");
	int arr[3][3]={{10,10,10},{10,10,10},{10,10,10}};
	matrix_setter(arr);
	rungame(arr);
}