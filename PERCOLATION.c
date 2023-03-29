//Percolation CMLT code//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define seed 4375
#define N 1001


int main(){
	int i,j,k,temp1,temp2,s,Prop,Smax,M=1000,sump=18,n,S2;
	double kp, p;
	
	srand(seed);	


FILE *Percolation;
Percolation=fopen("Percolation.txt","w");	

//allocate memory
int (*grid)[N] = malloc(sizeof(int[N][N]));
int*L=malloc(N*N*sizeof(int));
int*S=malloc(N*N*sizeof(int));
double*Iav=malloc(sump*sizeof(double));
double*Iavt=malloc(sump*sizeof(double));
double*pmax=malloc(sump*sizeof(double));




for (Prop=0; Prop<sump; Prop++){
	if (Prop>=0 && Prop<=4)  p=p+0.1;
	else if(Prop>4 && Prop<=5) p=p+0.05;
	else if (Prop>5 && Prop<=15)  p=p+0.01;
	else if (Prop>15 && Prop<=16) p=p+0.05;
	else if (Prop>16 && Prop<=17) p=p+0.1;

//initiallaization arrays

for(i=0; i<sump; i++) Iav[i]=0.0;

for(i=0; i<sump; i++) Iavt[i]=0.0;

for(i=0; i<sump; i++) pmax[i]=0.0;


   for (n=1; n<=M; n++){
   	for (i=0; i<N*N; i++ ) L[i]=0;
	for (i=0; i<N*N; i++ ) S[i]=0;
   	
   	
	    for (i=0; i<N; i++){
	     	for (j=0; j<N; j++){
	  	    	kp=(double)rand() / (double)((unsigned)RAND_MAX + 1);
	  		        if (kp<=p) grid[i][j]=1;
	  		        else       grid[i][j]=0;
					 grid[0][j]=0;
					 grid[i][0]=0; 	  		  	
		    }
	    }
	 
	
	
	
	
	
//CMLT CODE

 k=1;
 

        for (j=1; j<N; j++){
        	for (i=1; i<N; i++){
        		if (grid[i][j]!=0){
        			if (grid[i][j-1]==0){
        				if (grid[i-1][j]==0){
        					L[k]=k;
        					grid[i][j]=L[k];
        					S[L[grid[i][j]]]=S[L[grid[i][j]]]+1;
        					k=k+1;
						}
						else{
							grid[i][j]=L[grid[i-1][j]];
							S[L[grid[i][j]]]=S[L[grid[i][j]]]+1;
						}
        				
					}
					else{
						grid[i][j]=L[grid[i][j-1]];
						S[L[grid[i][j]]]=S[L[grid[i][j]]]+1;
						
						   if (grid[i-1][j]!=0 && L[grid[i-1][j]]!=L[grid[i][j-1]] ){
						   	   
						   	   
						   	    temp1=L[grid[i-1][j]];
						   	    L[grid[i-1][j]]=L[grid[i][j-1]];
						   	    temp2=L[grid[i-1][j]];
						   	    s=1;
						   	    
						   	    while (s<=(N*N)){
						   	    	if(L[s]==temp1){
						   	    		L[s]=temp2;	
									   }
									 s=s+1;  
								   }
							
							S[L[grid[i][j-1]]]=S[L[grid[i][j-1]]]+S[grid[i-1][j]];
			                S[grid[i-1][j]]=0;	   
						    }
			        } 
			     }
        	}
        }
        
      Smax=0;
     
      for (i=0; i<N*N; i++ ){
      	if(S[i]>Smax) Smax=S[i];
      }
      
      S2=0;
    
      for(i=0; i<N*N; i++){
      	if (S[i]==Smax){
      		S2=S2+1;
		  }
	  }
    
    //calculate parameters
   
      for (i=0; i<N*N; i++){
	  		Iav[Prop]=Iav[Prop]+(S[i]/(p*N*N))*S[i];
       }
     
	  for (i=0; i<N*N; i++){
	  Iavt[Prop]=Iavt[Prop]+(S[i]/(p*N*N))*S[i];  
       }
	   Iavt[Prop]=Iavt[Prop]-(S2*Smax/(p*N*N))*Smax;
	   
	  
	  pmax[Prop]=pmax[Prop]+Smax/(p*N*N);
	  
	  
	  
    }
	   
 Iav[Prop]=Iav[Prop]/M;   
 Iavt[Prop]=Iavt[Prop]/M; 
 pmax[Prop]=pmax[Prop]/M;

 {
	    printf("%f\t%f\t%f\t%f\n",p,Iav[Prop],Iavt[Prop],pmax[Prop]);
		fprintf(Percolation,"%f\t%f\t%f\t%f\n",p,Iav[Prop],Iavt[Prop],pmax[Prop]);  //write data
	}


}
  
// free memory
free(grid);
free(L);
free(S);
free(Iav);
free(Iavt);



return 0;	
}

