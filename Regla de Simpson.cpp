#include<bits/stdc++.h>

double funcion(double coe[],double x);
double trap(double h, int n, double f[]);
double simInt(double a, double b, int n, double f[], double h);
double sim13(double h, int n, double f[]);
double sim38(double h,double f0,double f1,double f2,double f3);

int main()
{
	int n;
	double a, b, coe[6], h, x, res;
	
	printf("\tRegla de Simpson");
	printf("\nIngrese la cantidad de segmentos: ");
	scanf("%d",&n);
	double f[n+1];
	
	printf("\nIngrese los limites de integracion");
	printf("\na: ");
	scanf("%lf",&a);
	printf("\nb: ");
	scanf("%lf",&b);
	h=(b-a)/n;
	x=a;
	printf("\nIngrese los coeficientes de X (si dicho coeficiente no existe en la ecuacion ingrese 0)");
	for(int i=0; i<=5; i++)
	{
		printf("\nX^%d: ",i);
		scanf("%lf",&coe[i]);
	}
	for(int i=0; i<=n; i++)
	{
		f[i]=funcion(coe,x);
		x+=h;
	}
	res= simInt(a,b,n,f,h);
	
	printf("\nI: %lf\n\n",res);
	system("PAUSE");
	return 0;
}


double funcion(double coe[],double x)
{
	double res= coe[0];
	for(int i=1; i<=5; i++)
	{
		res=res+ (coe[i] * pow(x,i));
	}
	return res;
}
double trap(double h, int n, double f[])
{
	double sum=f[0];
	for(int i=1; i<n-1;i++)
		sum=sum+(2*f[i]);
	sum=sum+f[n];
	double tramp = h*sum/2;
	return tramp;	
}
double simInt(double a, double b, int n, double f[], double h)
{
	double sum=0, simpInt, odd;
	int m, parteEntera;
	if(n==1)
		sum=trap(h,n,f);
	else
	{
		m=n;
		odd=n/2.0 - int(n/2);
		if(odd>0 && n>1)
		{
			sum=sum+sim38(h,f[n-3],f[n-2],f[n-1],f[n]);
			m=n-3;
		}
		if(m>1)
			sum=sum+sim13(h,m,f);
	}
	simpInt=sum;
	return simpInt;
}
double sim13(double h, int n, double f[])
{
	double sum, simp13m;
	sum=f[0];
	for(int i=1; i<n-2; i=i+2)
		sum=sum+(4*f[i])+(2*f[i+1]);
	sum=sum+(4*f[n-1]) + f[n];
	simp13m=h*sum/3;
	return simp13m;
}
double sim38(double h,double f0,double f1,double f2,double f3)
{

	double simp38;
	simp38=3*h*(f0+ (3*(f1+f2))+f3)/8;
	return simp38;
}

/*
5
0
0.8
0.2
25
-200
675
-900
400
*/
