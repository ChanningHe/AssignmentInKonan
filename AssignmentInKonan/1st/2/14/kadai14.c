#include<stdio.h>

int main(){
    char *weeks[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int arrayM[13]={6,2,2,5,7,3,5,1,4,6,2,4};
    int day,mouth,week;
    int firstday,result;
    
    printf("月を入力してください\n");    
    scanf("%d",&mouth);
    printf("日を入力してください\n");    
    scanf("%d",&day);

    firstday=arrayM[mouth];
    result = (day%7)+6-firstday;
    if(result > 7){ result -= 7;}

    printf("2022年%d月%d日の曜日は「%s」です。\n",mouth,day,weeks[result-1]);

    return 0;
}