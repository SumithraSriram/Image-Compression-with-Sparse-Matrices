//Multi-level Centroid compression method

#include<stdio.h>
#include<conio.h>
#include<string.h>

int im1[1000][1000];
int im2[1000][1000];
int im3[1000][1000];
int im4[1000][1000];
int im5[1000][1000];

int m[1000][1000];
int d1[1000][1000];
int d2[1000][1000];
int d3[1000][1000];
int d4[1000][1000];
int d5[1000][1000];

int main()
{
	int i,j,k,x;
	int r,c;
	char s[15];
	i=0;
	printf("Enter the number of rows\n");
	scanf("%d", &r);
	printf("Enter the number of columns\n");
	scanf("%d", &c);
	FILE * f1=fopen("image1.txt", "r");
    while (!feof (f1))
    {
        j=0;
        fscanf (f1, "%d", &im1[i][j]);    
        for(j=1;j<c;j++)
        {  
           fscanf (f1, "%d", &im1[i][j]);  
        }
        i++;
    }
    fclose (f1); 
    
    i=0;
	FILE * f2=fopen("image2.txt", "r");
    while (!feof (f2))
    {
        j=0;
        fscanf (f2, "%d", &im2[i][j]);    
        for(j=1;j<c;j++)
        {  
           fscanf (f2, "%d", &im2[i][j]);  
        }
        i++;
    }
    fclose (f2); 
    
    i=0;
	FILE * f3=fopen("image3.txt", "r");
    while (!feof (f3))
    {
        j=0;
        fscanf (f3, "%d", &im3[i][j]);    
        for(j=1;j<c;j++)
        {  
           fscanf (f3, "%d", &im3[i][j]);  
        }
        i++;
    }
    fclose (f3); 
    
    i=0;
	FILE * f4=fopen("image4.txt", "r");
    while (!feof (f4))
    {
        j=0;
        fscanf (f4, "%d", &im4[i][j]);    
        for(j=1;j<c;j++)
        {  
           fscanf (f4, "%d", &im4[i][j]);  
        }
        i++;
    }
    fclose (f4); 
    
    i=0;
	FILE * f5=fopen("image5.txt", "r");
    while (!feof (f5))
    {
        j=0;
        fscanf (f5, "%d", &im5[i][j]);    
        for(j=1;j<c;j++)
        {  
           fscanf (f5, "%d", &im5[i][j]);  
        }
        i++;
    }
    fclose (f5); 
    
    
    for(k=1;k<=2;k++)
    {
    	
    for(i=0;i<c;i++)
    {
    	im1[r][i]=im1[r-1][i];
    	im2[r][i]=im2[r-1][i];
    	im3[r][i]=im3[r-1][i];
    	im4[r][i]=im4[r-1][i];
    	im5[r][i]=im5[r-1][i];
    }
    
    for(i=0;i<=r;i++)   //Finding the median image
    {
    	for(j=0;j<c;j++)
			m[i][j]= (im1[i][j] + im2[i][j] + im3[i][j] + im4[i][j] +im5[i][j]) / 5;
    }
    
    for(i=0;i<r;i++)    //Finding the difference matrices
    {
    	for(j=0;j<c;j++)
    	{
    		x= m[i+1][j] + im1[i][j] - m[i][j];
    		d1[i][j] = im1[i][j] - x;
    		
    		x= m[i+1][j] + im2[i][j] - m[i][j];
    		d2[i][j] = im2[i][j] - x;
    		
    		x= m[i+1][j] + im3[i][j] - m[i][j];
    		d3[i][j] = im3[i][j] - x;
    		
    		x= m[i+1][j] + im4[i][j] - m[i][j];
    		d4[i][j] = im4[i][j] - x;
    		
    		x= m[i+1][j] + im5[i][j] - m[i][j];
    		d5[i][j] = im5[i][j] - x;
    	}
    }
    
    sprintf(s, "Median%d.txt", k);
    
    FILE * f6 = fopen(s, "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f6, "%d ",m[i][j]);
     	fprintf(f6, "\n");
     }
     fclose(f6);
     
     
     for(i=0;i<=r;i++)
    {
    	for(j=0;j<c;j++)
    	{
	    	im1[i][j]=d1[j][j];
	    	im2[i][j]=d2[j][j];
	    	im3[i][j]=d3[j][j];
	    	im4[i][j]=d4[j][j];
	    	im5[i][j]=d5[j][j];
	    }
    }
	}
	FILE * f7 = fopen("Difference1.txt", "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f7, "%d ",d1[i][j]);
     	fprintf(f7, "\n");
     }
     fclose(f7);
     
     FILE * f8 = fopen("Difference2.txt", "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f8, "%d ",d2[i][j]);
     	fprintf(f8, "\n");
     }
     fclose(f8);
     
     FILE * f9 = fopen("Difference3.txt", "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f9, "%d ",d3[i][j]);
     	fprintf(f9, "\n");
     }
     fclose(f9);
     
     FILE * f10 = fopen("Difference4.txt", "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f10, "%d ",d4[i][j]);
     	fprintf(f10, "\n");
     }
     fclose(f10);
     
     FILE * f11 = fopen("Difference5.txt", "wt");
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<c;j++)
     	     fprintf(f11, "%d ",d5[i][j]);
    	fprintf(f11, "\n");
     }
     fclose(f11);
     
     
     printf("Calculated successfully");
     getch();
     return 0;
}

