#include<stdio.h>

typedef struct color{
    char name[100];
    int r;
    int g;
    int b;
    int y;
}color;

void lum(color *c);

int main(){
    color col[3] = {
            {"plum", 221, 160, 221, 0},
            {"purple", 128, 0, 128, 0},
            {"indigo",75, 0, 130, 0},
    };
    for(int i=0; i<3; i++){
        lum(&col[i]);
    }
    for(int i=0; i<3; i++){
        printf("%s  %d %d %d %d\n",col[i].name,col[i].r,col[i].g,col[i].b,col[i].y);
    }
    return 0;
}


void lum(color *c){
    c->y = 0.299*c->r + 0.587*c->g + 0.114*c->b;
}