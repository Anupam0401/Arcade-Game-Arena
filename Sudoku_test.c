//Completed
//read to-do 
#include<iostream.h>
#include <cstdio>
#include<cstdlib>
#include<ctime>
int checkSmall(int a[][9],int i,int j, int k)
{
 i=(i/3)*3;
 j=(j/3)*3;
 int i1=i,j1=j;
 for(i=i1;i<(i1+3);i++){
 	for(j=j1;j<(j1+3);j++){
 		if(k==a[i][j]){
 			return 0;
 			}
 		}
 	}
 return 1;
}
void print(int a[][9]){
 int i,j;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		printf("%2d ",a[i][j]%10);
 		if((j+1)%3==0)
 		printf("|");
 		}
 	if((i+1)%3==0){
 		printf("\n");
 		for(j=0;j<15;j++)
 			printf("_ ");
 		printf("\n");
 		}
 	printf("\n");
 }
}
int check(int a[][9],int i,int j, int k)
{
 int i1=0,j1=0;
 for(;i1<9;i1++){
 	if(k==a[i1][j])
 		return 0;
 	}
 for(;j1<9;j1++){
 	if(k==a[i][j1])
 		return 0;
 	}
 return 1;
}



int solve(int a[][9])
{
 int i,j,k;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		if(i==8&&j==8&&a[i][j]!=0){
 			return 1;
 			print(a);
 		}
 		if(a[i][j]!=0)
 			continue;
 		for(k=1;k<=10;k++){
 			if(k==10)
 				{a[i][j]=0;
 				 return -1;
 				}
 			if(checkSmall(a,i,j,k)==0)
 				continue;
 			if(check(a,i,j,k)==0)
 				continue;
 			a[i][j]=k;
 			if(solve(a)==1)
 				return 1;
 			}
 		}
 	}
 return 2;
}

int Sudoku_pass(int a[][9], int b[][9])
{
int i,j,k=0,flag=0;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		if(a[i][j]==0)
 			k=1;
 		}
 	}
 if(k==1){
 	return 0;
 }
 if(k==0){
 	for(i=0;i<9;i++){
 		for(j=0;j<9;j++){
 			k=a[i][j];
 			a[i][j]=0;
 			if(checkSmall(a,i,j,k)==0)
 				flag=1;
 			if(check(a,i,j,k)==0)
 				flag=1;
 			a[i][j]=k;
 		}
 	}
 	if(flag==0){
 		printf("You solved!!!\n");
 		print(a);
 		return 1;
 	}
 }
 if(k==0){
 	printf("Try again\nSolution of this Sudoku is\n\n");
 	solve(b);
 	print(b);
 	return 1;
 	}
 return 0;
}

int checkSmall(int a[][9],int i,int j, int k)
{
 i=(i/3)*3;
 j=(j/3)*3;
 int i1=i,j1=j;
 for(i=i1;i<(i1+3);i++){
 	for(j=j1;j<(j1+3);j++){
 		if(k==a[i][j]){
 			return 0;
 			}
 		}
 	}
 return 1;
}



int check(int a[][9],int i,int j, int k)
{
 int i1=0,j1=0;
 for(;i1<9;i1++){
 	if(k==a[i1][j])
 		return 0;
 	}
 for(;j1<9;j1++){
 	if(k==a[i][j1])
 		return 0;
 	}
 return 1;
}

int solve(int a[][9])
{
 int i,j,k;
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		if(i==8&&j==8&&a[i][j]!=0){
 			return 1;
 			print(a);
 		}
 		if(a[i][j]!=0)
 			continue;
 		for(k=1;k<=10;k++){
 			if(k==10)
 				{a[i][j]=0;
 				 return -1;
 				}
 			if(checkSmall(a,i,j,k)==0)
 				continue;
 			if(check(a,i,j,k)==0)
 				continue;
 			a[i][j]=k;
 			if(solve(a)==1)
 				return 1;
 			}
 		}
 	}
 return 2;
}




void sudoku(int a[][9],int n)
{
printf("Sudoku_created\n");
	int i,b,c,d;
 srand(time(0));
 	if(n==1)n=61;
 	else if(n==2) n=55;
 	else n=40;
   for( i = 0 ; i < n ; i++ ) {
   	b=rand()%9;
   	c=rand()%9;
   	d=(rand()%9)+1;
   	if(checkSmall(a,b,c,d)==0)
 		continue;
 	if(check(a,b,c,d)==0)
 		continue;
      a[b][c]=(d);
   }
   for( i = 0 ; i < n ; i++ ) {
   	b=rand()%9;
   	c=rand()%9;
   	
    //  a[b][c]=0;
   }
   
   print(a);
}


void playsudoku(int a[][9], int b[][9])
{
	int r,c,n;
	printf("Enter row (space) column (space) number:\n");
	scanf("%d",&r);
	r%=10;
	r--;
	scanf("%d",&c);
	c%=10;
	c--;
	scanf("%d",&n);
	n%=10;
	n;
	a[r][c]=n;
	print(a);
	if(Sudoku_pass(a,b)==0)
		playsudoku(a,b);
}


int main() 
{
 int n,i,j,num,k,a[9][9]={0},b[9][9];
 printf("Enter \n1 for Beginner Level \nor\n 2 for Intermediate level\nor\n 3 for Advanced Level\n");
 scanf("%d",&n);
/* for(k=0;k<n;k++){scanf("%d %d",&i,&j);scanf("%d",&a[i-1][j-1]);}*/
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		a[i][j]=0;
 		b[i][j]=0;
 		}
 	}
 sudoku(a,n);
 for(i=0;i<9;i++){
 	for(j=0;j<9;j++){
 		b[i][j]=a[i][j];
 	}
 }
 playsudoku(a,b);
return 0;
}
