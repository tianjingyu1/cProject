# include<stdio.h>
# include<time.h>
# include<math.h>
clock_t start, stop;
/* clock_t是clock()函数返回的变量类型 */
double duration;
/* 记录被测函数运行时间，以秒为单位 */
# define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */
# define MAXK 1e7 /* 被测函数最大重复调用次数 */

double f1( int n, double a[], double x)
{
	int i;
	double p =a[0];
	for ( i=1; i<=n; i++)
		p += (a[i] * pow(x, i));
	return p;
 } 
 
 double f2( int n,double a[], double x)
 {
 	int i;
 	double p = a[n];
 	for ( i=n; i>0; i-- )
 		p = a[i-1] + x*p;
 	return p;
 }
int main()
{ /* 不在测试范围内的准备工作写在clock()调用之前 */ 
	int i;
	double a[MAXN]; /* 存储多项式的系数 */
	for ( i=0; i<MAXN; i++) a[i] = (double)i; 
	
	start = clock();
	for ( i=0; i<MAXK; i++) /* 重复调用函数以获得充分多的时钟打点数 */ 
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	/* 计算运行时间 */
	/* 其他不在测试范围的处理写在后面，例如输出duration的值 */
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("durations2 = %6.2e\n", duration);
	
	start = clock();
	for ( i=0; i<MAXK; i++) /* 重复调用函数以获得充分多的时钟打点数 */ 
		f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	/* 计算运行时间 */
	/* 其他不在测试范围的处理写在后面，例如输出duration的值 */
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("durations2 = %6.2e\n", duration);
	
	return 0; 
}
