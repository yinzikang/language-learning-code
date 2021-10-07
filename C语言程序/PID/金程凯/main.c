#include <stdio.h>
#include <stdlib.h>
float pError = 0, iError = 0, dError = 0;
float ek=0;
float kp=0.9;
float ek1=0;
float ek2=0;

float u1=0;
float u=0;
float  MotorPWM_Speed=1000;
float  feedback_middle=0;
int main()
{

while(1)
  {ek= MotorPWM_Speed-feedback_middle;
      pError = ek-ek1;
      iError = ek;
    dError = ek-ek1*2+ek2;
      ek2 = ek1;
      ek1 = ek;
      u = kp* (0.5*pError + 0.001* iError + 0.5 * dError) + u1;
      u1 = u;
      feedback_middle+=u;
      printf("%f\n",u);
}
}
