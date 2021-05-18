#include <stdio.h>
#include <math.h>
int parabola(int x)
{
  if(x>0)
  {
    return printf("Parabola voltada para cima\n");
  }

  else if(x<0)
  {
    return printf("Parabola voltada para baixo\n");
  }
  else
  {
    return printf("Equação de primeiro grau.\n");
  }
}
int delta(int y,int z, int w,int tedla)
{
  return tedla=(pow(z,2)-(4*y*w));
}
int poss(int e)
{
  if(e>0)
  {
    return printf(" Duas raízes. A parábola toca a reta x em dos pontos (x é secante à parábola)");
  }
  else if(e==0)
  {
    return printf("Uma única raiz (o vértice da parábola toca a reta x)\n");
  }
  else
  {
  return printf("A parabola nao toca o eixo x\n");
  }
}
int raizes(int t,int i,int el, int xum,int xx)
{
xum=(-i+sqrt(el))/2*t;
xx=(-i-sqrt(el))/2/t;
return printf("x1=%d e x2=%d\n", xum,xx);
}
int vert(int o,int p, int celta,float vx,float vy)
{
  vx=(-p)/2*o;
  vy=(-celta)/4*o;
  return printf("Xv=%.2f e Yv=%.2f\n", vx,vy);
}
int main(void) {
  int a, b, c,delt;
  float x1,x2,xv,yv;
  printf("Digite os valores de a, b e c\n");
  scanf("%d %d %d", &a,&b,&c);
parabola(a);
delt=delta(a,b,c,delt);
poss(delt);
raizes(a, b, delt,x1, x2);
vert(a, b, delt,xv,yv);
return 0;
}
