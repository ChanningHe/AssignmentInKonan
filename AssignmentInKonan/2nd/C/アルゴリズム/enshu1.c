#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RECORD_MAX (10000)

struct Record {
    int key;    /* 重複しない */
    int data;   /* 0以上と仮定 */
};

struct Record table[RECORD_MAX]; /* 表 */
int n = 0;                       /* レコード数(<= RECORD_MAX) */

void regist(int key, int data) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (table[i].key == key) {
            /* keyと一致するレコードがすでにあった場合 */
            table[i].data = data;
            return;
        } else if (table[i].key > key) {
            if (n < RECORD_MAX) {
                /* i番目以降のレコードを1つづつ後ろにずらす */
                for (j = n - 1; j >= i; j--) {
                    table[j+1].key = table[j].key;
                    table[j+1].data = table[j].data;
                }
                /* i番目のレコードに書き込み */
                table[i].key = key;
                table[i].data = data;                
                n++;
                return;
            }
        }
    }
    /* keyの値が一番大きい場合、一番最後に書き込み */
    if (n < RECORD_MAX) {
        table[n].key = key;
        table[n].data = data;
        n++;
    }
}
//binary search
int search(int key) {
    int flagl=0,flagr=n-1;
    int conut=0;
    while(flagl <= flagr){
        int flag=(flagl+flagr)/2;
        /*
        if(flag == flagl || flag == flagr){
            return -1;
        }
        */
        if(key > table[flag].key){
            flagl=flag+1;
        }else if(key < table[flag].key){
            flagr=flag-1;
        }else if(key == table[flag].key){
            //conut++;
            return table[flag].data;
        }
    }
    if(conut == 0){
        return -1;
    }
}
int main() {
    int n, m, i, key, data;

    scanf("%d", &n);
    printf("レコード数(%d)\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        scanf("%d", &data);
        printf("キー(%d), データ(%d)を登録\n", key, data);
        regist(key, data);
    }
    for (i = 0; i < n; i++) {
        printf("%d   %d\n",table[i].key,table[i].data);
    }


    printf("InputSearchTimes:\n");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("SearchKey:\n");
        scanf("%d", &key);
        printf("キー(%d)を探索．\n", key);
        data = search(key);
        if (data == -1) {
            printf("キー(%d)を持つレコードは登録されていません．\n", key);
        } else {
            printf("キー(%d)のデータは%dです．\n", key, data);
        }
    }
}