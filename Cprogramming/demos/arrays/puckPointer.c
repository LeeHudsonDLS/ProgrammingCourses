#include<stdio.h>
#include<math.h>

int main(void)
{
	//unsigned short demand; //= 16;   
	unsigned short demand;
	unsigned short bank01;   
	unsigned short bank02;   
	unsigned short bank03;   
	unsigned short bank04;
                                  
    	scanf("%d", &demand);	
	
	if(demand >= 1 && demand <= 16){
		bank01 = pow(2,demand-1);
		printf("bank01 = %d",bank01);
	}
	if(demand >= 17 && demand <= 32){
		bank02 = pow(2,demand-17);
		printf("bank02 = %d",bank02);
	}
	if(demand >= 33 && demand <= 48){
		bank03 = pow(2,demand-33);
		printf("bank03 = %d",bank03);
	}
	if(demand >= 49 && demand <= 64){
		bank04 = pow(2,demand-49);
		printf("bank04 = %d",bank04);
	}

	return 0;

}
