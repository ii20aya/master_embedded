#include <stdio.h>
int main() {
int n, count;
unsigned long long int factorial=1;
printf("Enter an integer: ");
scanf("%d",&n);
if (n< 0)
printf("Error");
else
{

for(count=1; count<=n; ++count) {

factorial*=count;
}
printf("Factorial = %lu", factorial);
}
return 0;
}
