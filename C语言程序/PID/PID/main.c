#include <stdio.h>
#include <stdlib.h>
double spdwant,spdtrue;
double ek0,ek1,ek2;
double kp,kd,k;
double u,du;
int i;
int main()
{
    spdwant = 1000;
    spdtrue =0;
    kp = 0.1;
    kd = 0.0;
    k = 1;
    while(1)
    {
        ek0 = spdwant - spdtrue;
        du = (kp*(ek0-ek1) + kd*(ek0+ek2-ek1*2))/k;
        ek2 = ek1;
        ek1 = ek0;
        spdtrue += du;
        printf("%lf\n",spdtrue);
    }
    return 0;
}
