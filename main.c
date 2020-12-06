#include <stdio.h>
#include <math.h>  

int main()
{
    
    float x,y;
    printf ("Вкажіть координати маленької осі x :");
    scanf ("%float", &x);
    printf ("Вкажіть координати маленької осі y :");
    scanf ("%f", &y);
    float a1 = pow(x, 2);
    float a2 = pow(y, 2);
    float a3 = a1 + a2;
    printf ("Довжина маленької осі:%f\n",a3);
   //Расчет и вывод результата извлечения квадратного корня функцией sqrtf
    printf ("sqrtf : %.20f\n", sqrtf (a3) );
   //Расчет и вывод результата извлечения квадратного корня функцией sqrt
   
    float x1,y2;
    printf ("Вкажіть координати великої осі x :");
    scanf ("%float", &x1);
    printf ("Вкажіть координати великої осі y :");
    scanf ("%f", &y2);
    float a4 = pow(x1, 2);
    float a5 = pow(y2, 2);
    float a6 = a4 + a5;
    printf ("Довжина великої осі:%f\n",a6);
   //Расчет и вывод результата извлечения квадратного корня функцией sqrtf
    printf ("sqrtf : %.20f\n", sqrtf (a6) );
    
    float s=M_PI * a6 *a3;
    printf("Площа=%f\n",s);
    

   return 0;
}