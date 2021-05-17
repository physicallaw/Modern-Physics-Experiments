#include<stdio.h>

double triangle(int t){
    if ((t/125) % 4 == 0)
       return 0.016;
    else if ((t/125) % 4 == 1)
       return -0.016;
    else if ((t/125) % 4 == 2)
       return 0.01601;
    else
       return -0.01601;
}
 
int main()
{   
    int N = 100000;
    double x, dx, ddx, wave;
    x = 0, dx = 0, wave = -1. ;
    FILE *fp = fopen("output.txt", "w");
    for (int t = 0; t<N; t++){
    	wave += triangle(t);
        ddx = 1*x-20*x*x*x+430*wave-750*dx;
        dx = dx+ ddx/N;
        x = x + dx/N;
        fprintf(fp,"%f	%f\n", 290*wave, -x); 
   }
}
