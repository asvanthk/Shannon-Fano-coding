#include <stdio.h>
#include <string.h>

struct message {
    char symbol;
    float prob;
    int c[10];
    int c_pos;
 }m[6];
 
// function to code the message
code_c(int l_lim,int u_lim,int brk){
	int i;
	for(i=l_lim;i<=u_lim;i++){
		if(i<=brk){
			m[i].c[++(m[i].c_pos)] = 0;
		}
		else{
			m[i].c[++(m[i].c_pos)] = 1;
		}
	}	
}

//function to perform shanon-fano 
void code(int l_lim,int u_lim){
	if(l_lim!=u_lim){
		int i,j;
		float u =0;
		float l =0; 
		int brk = 0;
		float diff = 0;
		float pdiff = 0;
		for(i=l_lim;i<=u_lim;i++)
		{
			u = u+m[i].prob;
			for(j=i+1;j<=u_lim;j++){
				l = l+m[j].prob;
			}
			diff = (u-l)*(u-l);
			if(l==u){
				break;
			}
			if(i ==l_lim){
				pdiff  = diff;
			}
			else{
				if(diff>=pdiff)
					{
					i=i-1;
					break;
					}
				pdiff = diff;		
				}
			l=0;
		}
		brk = i;
		code_c(l_lim,u_lim,brk);
		code(l_lim,i);
		code(i+1,u_lim);
	}
}

//function to perform sorting
void sort(int n){
	struct message temp;
	int i,j;
	for (j = 1; j <= n - 1; j++) { 
    	   for (i = 0; i < n - 1; i++) { 
        	    if ((m[i].prob) < (m[i + 1].prob)) { 
            	    temp = m[i];
                  	m[i] = m[i+1];
                    m[i+1] = temp;
            	} 
        	} 
  	}
}

void main() {
  int i,j,k;
  int n=6;
  for (i = 0; i < n; i++) {
    printf("Enter detail of message  #%d\n",i+1);
    printf("Enter symbol: ");
    scanf("%s", &m[i].symbol);
    printf("Enter probability: ");
    scanf("%f",&m[i].prob);
	m[i].c_pos = -1;
  }

  sort(n);
  code(0,n-1);
  
  //display the code
  printf("\n");
  for(i=0;i<n;i++){
  	k = m[i].c_pos;
  	printf("\nsym = %c ",m[i].symbol);
  	for(j=0;j<=k;j++){
  		printf("%d",m[i].c[j]);
	}
	printf("\n");
  } 	
}


