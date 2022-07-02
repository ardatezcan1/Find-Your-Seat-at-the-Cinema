#include <stdio.h>
/* 1 if the seats to be taken are empty, otherwise 0 returns*/
int Bosmu(int mat[][50],int en,int boy,int x,int y,int koltuk)
{
    int i,j,say=0;
    for (i=0;i<koltuk;i++)
    	if ((mat[x][y+i]==0) && ((y+i)<en))
          		say++;
    	
	if (say==koltuk)
    	return 1;
    else
    	return 0;
}

/* finds the appropriate place in the hall and freezes the row and column number*/
int UygunYer(int mat[][50],int en,int boy,int yer[2],int koltuk)  //int UygunYer(int **mat,int en,int boy,int yer[2],int koltuk)
{
  int k,say=0,i=0,j=en-1;
   
  while ((i<boy) && (say!=koltuk))
  {
  	j=en-1;
  	while ((j>=0) && (say!=koltuk))
     	{
            		say=0;
             		for (k=0;k<koltuk;k++)
                 			if (((j-k)>=0) && (*((int *)mat + i*50 + j - k)==0))
                     			say++;
             		if (say==koltuk)
             		{
                			printf("Place:%d %d \n",i,j-k+1);
                			yer[0]=i;
                			yer[1]=j-k+1;
                			return 1;
             		}  
      	j--;      
     	}
     	i++;
 }
 return 0;
}

int main()
{
    int x,y,i,j,sonuc,rez=1,en,boy,koltuk,c='e',yer[2];
	static int mat[50][50];    
    printf("Give the width and height of the hall\n"); scanf("%d %d",&en, &boy);
    while (c=='e')
     {
     printf("x,y,length?\n");
     scanf("%d %d %d",&x,&y,&koltuk);
     if (koltuk>en)
     	printf("Maximum %d seats can be taken at a time\n",en);
     sonuc=Bosmu(mat,en,boy,x,y,koltuk);
     if (sonuc==1) // the requested seats are empty
     {
        // place people
        printf("Placed in the desired location\n");
        for (i=0;i<koltuk;i++)
        	mat[x][y+i]=rez;
     }
     else
     {
         sonuc=UygunYer(mat,en,boy,yer,koltuk);
         if (sonuc!=0)
         {
            x=yer[0];
            y=yer[1];
            for (i=0;i<koltuk;i++)
            	mat[x][y+i]=rez;
         }
     }
     rez++;
     printf("Do you want to continue e h\n");
     scanf("%c",&c); scanf("%c",&c);
   }
    

for (i=0;i<boy;i++)
	{
		for (j=0;j<en;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
return 0;
}
