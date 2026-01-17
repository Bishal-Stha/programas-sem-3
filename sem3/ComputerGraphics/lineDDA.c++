#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void lineDDA(int x1, int y1, int x2, int y2, int col){
    int dX = x2 - x1;
    int dY = y2 - y1;
    int steps;
    float x = x1, y = y1;
    float Xinc, Yinc;

    steps = (abs(dX) > abs(dY)) ? abs(dX) : abs(dY);

    Xinc = (float)dX / steps;
    Yinc = (float)dY / steps;

    for(int k = 0; k <= steps; k++){
        putpixel(round(x), round(y), col);
        x += Xinc;
        y += Yinc;
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    
    // lineDDA(200,200,400,200,3);
    // lineDDA(300,100,300,300,4);   
    // lineDDA(200,100,400,300,2);   
    // lineDDA(400,100,200,300,5);
    lineDDA(100,100,350,350,2);
    lineDDA(175,175,425,425,3);
    lineDDA(150,150,450,450,4);
    lineDDA(200,200,400,400,5);

    getch();
    closegraph();
    return 0;
}
