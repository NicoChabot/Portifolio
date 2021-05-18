#include <stdio.h>
int maior(int x, int y, int maximo)
{
if(x>y)
{
  maximo=x;
}
else
{
  maximo=y;
}
return maximo;
}
int minimo(int m,int n, int mini)
{
  if(m<n)
  {
    mini=m;
  }
  else
  { mini=n;
  }
  
    return mini;
}
int diff(int c, int d,int mai,int men, int resultado)
{
resultado=maior(c,d,mai)-minimo(c,d,men);
return printf("A diferenca e %d",resultado);
}
int main(void) {
  int a,b,max,min,r;
  printf("Digite o valor de a e b: ");
  scanf("%d %d",&a, &b);
  maior(a,b,max);
  minimo(a,b,min);
 diff(a,b,max,min,r);
 return 0;
}
