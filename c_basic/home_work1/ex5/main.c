#include <stdio.h>
int main(){
      float num1, num2, temp;
      printf("Enter value of num1: ");
      scanf("%f",&num1);
      printf("Enter value of num2: ");
      scanf("%f",&num2);
      temp = num1;
      num1 = num2;
      num2 = temp;
      printf("\nAfter swapping, value of num1 = %.2f\n", num1);
      printf("After swapping, value of num2 = %.2f", num2);
      return 0;
}
