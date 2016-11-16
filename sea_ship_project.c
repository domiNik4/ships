#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>



int checkCode(int num);
void printArray(int array[8][8]);

main()
{
	int code1,code2,code3,code4;
	int field[8][8],position;
	int i,j;
	printf("Welcome. This is an app by Dominika Fric\n");
	printf("Enter a position on teh board.\n");
	
	printf("Enter code1:");
	scanf("%d",&code1);
	printf("Enter code2:");
	scanf("%d",&code2);
	printf("Enter code3:");
	scanf("%d",&code3);
	printf("Enter code4:");
	scanf("%d",&code4);
	
	code1=checkCode(code1);
	code2=checkCode(code2);
	code3=checkCode(code3);
	code4=checkCode(code4);
	
	printf("%d %d %d %d\n",code1,code2,code3,code4);
	
	for (j=7;j>=0;j--) {
			int bit=code1 & 1; 
			field[1][j]=bit*(-1);
				bit=code2 & 1; 
			field[3][j]=bit*(-1);
				 bit=code3 & 1; 
			field[5][j]=bit*(-1);
				 bit=code4 & 1; 
			field[7][j]=bit*(-1);
			
			code1=code1>>1;
			code2>>=1; 
			code3>>=1;
			code4>>=1;
	}
	
		for (j=7;j>=0;j--) { 
			int bit=code1 & 1; 
			field[0][j]=bit*(-1);
				bit=code2 & 1; 
			field[2][j]=bit*(-1);
				 bit=code3 & 1; 
			field[4][j]=bit*(-1);
				 bit=code4 & 1;
			field[6][j]=bit*(-1);
			
			code1=code1>>1;
			code2>>=1; 
			code3>>=1;
			code4>>=1;
	}
	
	printArray(field);
	
	printf("Enter position <0;63>\n");
	scanf("%d",&position);
	
	if(position<0||position>63){
		printf("Error. Out of the field.");
	}
	
	int positionRow=position/8;
	int positionCol=position%8;
	if(field[positionRow][positionCol]==-1){
		printf("Error. Ship can't be on land.");
	}
	
	
	field[positionRow][positionCol]=-2;
	printArray(field);
	
	if(positionCol>0&&field[positionRow][positionCol-1]==0)
	field[positionRow][positionCol-1]=1;
	if (positionCol>0&&field[positionRow][positionCol+1]==0)
	field[positionRow][positionCol+1]=1;
	if (positionCol>0&&field[positionRow-1][positionCol]==0)
	field[positionRow-1][positionCol]=1;
	if (positionCol>0&&field[positionRow+1][positionCol]==0)
	field[positionRow+1][positionCol]=1;
	
	int count=0;
	
	while(count<39){
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(field[i][j]==0){
				if(positionCol>0&&field[i][j-1]==0)
					field[i][j-1]=count+1;
				if (positionCol>0&&field[i][j+1]==0)
					field[i][j+1]=count+1;
				if (positionCol>0&&field[i-1][j]==0)
					field[i-1][j]=count+1;
				if (positionCol>0&&field[positionRow+1][positionCol]==0)
					field[positionRow+1][positionCol]=1;
			}
			
		}
		count++;
	}
	
}
	printf("\n");
	printArray(field);

}

int checkCode(int num){
	if(num>=0&&num<=pow(2,16)-1){
		return num;
	}
	else{
		return 0;
	}
}

void printArray(int array[8][8]) {
	int i,j;
	for(i=0;i<8;i++){
		printf(" - ");
	}
	printf("\n");
	for (i=0;i<8;i++) {
		printf("|");
		for (j=0;j<8;j++) {
			if(array[i][j]==0){
				printf("   ");
			}
			else{
				if(array[i][j]==-1){
				printf(" @ ");
				}
				else{
					if(array[i][j]==-2){
						printf(" S ");
					}
					else{
						if(array[i][j]>0){
							printf(" %d ",array[i][j]);
						}
					}
				}
			}
		}
		printf("|");
		printf("\n");
		printf("\n"); 
	}
	for(i=0;i<8;i++){
		printf(" - ");
	}
	printf("\n");
	
}

	
	






