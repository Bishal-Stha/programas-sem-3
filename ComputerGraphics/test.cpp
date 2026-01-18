#include<stdio.h>
#include<math.h>

void lineDDA(int x1, int y1, int x2, int y2, int col){
    int dX, dY, steps;
    float x = x1, y= y1, Xinc, Yinc;
    dX = x2-x1;
    dY = y2-y1;
    
    if(abs(dX) > abs(dY))
    steps = abs(dX);
    else
    steps = abs(dY);

    Xinc = (float) dX/steps;
    Yinc = (float) dY/steps;

    // putpixel(x1,y1,col);

    for(int k=1; k<=steps; k++){
        x += Xinc;
        y += Yinc;
        // putpixel(x,y,col);
        printf("(%f, %f)\n",x,y);
    }
}

int main(){
    lineDDA(5,7,11,15,2);
}