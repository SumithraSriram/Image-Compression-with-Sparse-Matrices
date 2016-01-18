#include<stdio.h>
#include<conio.h>
#include<math.h>

int im[100][100];
int rect[100][100];

int main()
{
	int i,j,k,x;
	int p,t;
	int r=0,c=0;
	int pc, pr, cf=0;   //Previous Column, Previous Row, Column Final
	printf("Enter the threshold value\n");
	scanf("%d", &t);
	
	i=0;
	FILE * f1=fopen("Boat 8x8.txt", "r");
    while (!feof (f1))
    {
        j=0;
        fscanf (f1, "%d", &im[i][j]);    
        for(j=1;j<8;j++)
        {  
           fscanf (f1, "%d", &im[i][j]);  
        }
        i++;
    }
    fclose (f1); 
    
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			rect[i][j]=0;
	}
	while(r<8)
	{
		x=8;
		p=im[r][cf];
		if(p==0)
		{
			cf++;
			if(cf==8)
			{
				cf=0;
				r++;
			}
			continue;
		}
		c=cf;
		while( abs(p-im[r][c]) <= t)
		{
			for(j=c;j<8;j++)
			{
				if( abs(p - im[r][j]) <= t && c<x)
				{
					im[r][j]=0;
					pc=c;
					c++;
				}
				else
				{
					x=c;
					pr=r;
					r++;
					break;
				}
			}
			c=cf;
		}
		
		rect[pr][pc]=p;
		cf=0;
		r=0;
		c=0;
		
	}
		
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%d ",im[i][j]);
		printf("\n");
	}

	FILE * f11 = fopen("Rectangle Segmentation.txt", "wt");
     for(i=0;i<8;i++)
     {
     	for(j=0;j<8;j++)
     	     fprintf(f11, "%d ",rect[i][j]);
    	fprintf(f11, "\n");
     }
     fclose(f11);
     
     printf("Succesfully written");
     getch();
     return 0;
}