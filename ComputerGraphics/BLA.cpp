#include<stdio.h>
#include<graphics.h>

void BLA(int x1, int y1, int x2, int y2, int col){
    int x,y,dx, dy, p;
    x= x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2*dy-dx;

    while(x <= x2){
        putpixel(x,y,col);
        x++;
        if(p < 0)
        p += 2*dy;
        else {
            p += 2*dy - 2 *dx;
            y++;
        }
        }
}

int main(){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    BLA(200,200,400,200,3);
    BLA(300,100,300,300,4);
    BLA(200,100,400,300,2);
    BLA(400,100,200,300,5);
    getch();
    closegraph();
    return 0;
}