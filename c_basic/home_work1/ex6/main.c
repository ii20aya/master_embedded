#include <stdio.h>
int main(){
      float a, b;
      printf("Enter value of a: ");
      scanf("%f",&a);
      printf("Enter value of b: ");
      scanf("%f",&b);
      a=a+b;
      b= a-b;
      a= a-b;
      printf("\nAfter swapping, value of a = %.2f\n", a);
      printf("After swapping, value of b = %.2f", b);
      return 0;
}
