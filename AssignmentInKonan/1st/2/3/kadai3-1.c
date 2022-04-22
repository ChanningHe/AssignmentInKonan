/*
20211011
12171029 Ka shouen
*/
#include<stdio.h>

int main(void){
	int water,cost;
	printf("使用水量を入力してください: ");
	scanf("%d",&water);

	if(water<=20){
		cost=1800;
	}else if(water>20 && water<=40){
		cost=1800+(water-20)*160;
	}else if(water>40 && water<=60){
		cost=1800+160*20+(water-40)*180;
	}else if(water>60){
		cost=1800+160*20+180*20+(water-60)*240;
	}
	
	printf("%dm^3 -> 水道料金: %d円\n",water,cost);
	return 0;
}