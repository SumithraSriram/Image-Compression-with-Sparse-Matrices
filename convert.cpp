#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *row;
int *col;
double *data;
  
void sort(int nz)
 {
 	int i,j,k,temp,posn,x;
 	double t;
 	for(i=0;i<nz-1;i++)
	 {
	 	posn=i;
	 	for(j=i+1;j<nz;j++)
		 {
		 	if(*(row+posn)>*(row+j))
		 	    posn=j;
		 }	
		 if(posn != i)
		 {
		 	temp=*(row+i);
		 	*(row+i)=*(row+posn);
		 	*(row+posn)=temp;
		 	
		 	temp=*(col+i);
		 	*(col+i)=*(col+posn);
		 	*(col+posn)=temp;
		 	
		 	t=*(data+i);
		 	*(data+i)=*(data+posn);
		 	*(data+posn)=t;
		 }
	 }

	for(k=0;k<nz;k++)
	{
		x=*(row+k);
		for(i=k;i<nz-1;i++)
		{
		if(*(row+i) != x)
			break;
	 	posn=i;
	 	for(j=i+1;j<nz;j++)
		 {
			 if(*(row+j) != x)
				break;
		 	if(*(col+posn)>*(col+j))
		 	    posn=j;
		 }	
		//if(*(row+j) != x)
			//	break;
		 if(posn != i)
		 {		 	
		 	temp=*(col+i);
		 	*(col+i)=*(col+posn);
		 	*(col+posn)=temp;
		 	
		 	t=*(data+i);
		 	*(data+i)=*(data+posn);
		 	*(data+posn)=t;
		 }
	 }
	}
 }
 
 
int main()
{
  FILE *fp, *f;
  char line[1024]; 
  int i,j;
  int n=0; // number of nonzero elements in data
  int nr=0; // number of rows in matrix
  int nc=0; // number of columns in matrix
  int c=0;
  fp = fopen("Pd_rhs.txt", "r");
  f=fopen("temp.txt","w");
  fgets(line, 128, fp);
  while (line[0] == '%') 
  {
    fgets(line, 128, fp); 
  }
  sscanf(line,"%d %d %d\n", &nr, &nc, &n);
  
  row = (int *) malloc(n*sizeof(int));
  col = (int *) malloc(n*sizeof(int));
  data = (double *) malloc(n*sizeof(double));
  
  for(i=0;i<n;i++)
  {
      fscanf(fp, "%d %d %lf\n", &(row[i]),&(col[i]),&(data[i]));
     // *(row+i) = *(row+i)-1;
     // *(col+i) = *(col+i)-1;
  }
  fclose(fp);
  sort(n);
  for(i=0;i<n;i++)
  {
  	  fprintf(f, "%d %d %lf\n ",*(row+i), *(col+i), *(data+i));
  }
  fclose(f);
  FILE *f1=fopen("Pd_rhsFull.txt","w");
  
  for(i=1;i<=nr;i++)
  {
  	for(j=1;j<=nc;j++)
  	{
  		if(*(row+c)==i && *(col+c)==j)
  		{
  		   fprintf(f1, "%lf ",*(data+c));
  		   c++;
  		  // printf("%d %d %d\n",c, i, j);
  		}
  		else
  		    fprintf(f1, "0 ");
  	}
  	fprintf(f1, "\n");
  }
  //printf("%d %d %d", *(row+c), *(col+c), *(data+c) );
  fclose(f1);
  printf("Values entered in the file");
  
  getch();
  return 0;
}
