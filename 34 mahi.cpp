#include<conio.h>
#include<stdio.h>
int main() {
	int n;
	int r;
	int i;
	int j;
	int k;
	int m;
	int mahi;
	int avail[10];
	int p[10];
	int Required[10][10];
	int allocation[10][10];
	int maximum[10][10];
	
	printf("\nPlease enter the number of process :");
	scanf("%d",&n);
	printf("\n Please enter  no of resources available : ");
	scanf("%d",&r);
	printf("\nPlease enter insatnces for resources :\n");
	for(i=0; i<r; i++) {
		printf("R%d ",i+1);
		scanf("%d",&avail[i]);
	}
	printf("\n Please enter allocation matrix  \n");
	for(i=0; i<n; i++) {
		p[i]=0;
		for(j=0; j<r; j++) {
			printf("p%d r%d\t",i+1,j+1);
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("\n Please enter maximum matrix  \n");

	for(i=0; i<n; i++) {
		
		for(j=0; j<r; j++) {
			printf("p%d r%d\t",i+1,j+1);
			scanf("%d",&maximum[i][j]);
		}
	}

	for(i=0; i<n; i++) {
		printf("\np%d\t",i+1) ;
		for(j=0; j<r; j++) {
			Required[i][j]=maximum[i][j]-allocation[i][j];
			printf("\t%d",Required[i][j]);
		}
	}
	k=0;
	mahi=0;
	printf("\n\n");
	while(k<15) {
		for(i=0; i<n; i++) {
			m=0;
			for(j=0; j<r; j++) {
				if(p[i]==1) break;
				if(Required[i][j]<=avail[j]) {
					m++;
				}
				if(m==r) {
					for(j=0; j<r; j++) {
						avail[j]+=allocation[i][j];
					}
					printf("p%d\t",i+1);
					p[i]=1;
					mahi++;
				}
			}
		}
		k++;
	}
	if(mahi<n-1) {
		printf("\nDeadlock ");
	}
	getch();
}

