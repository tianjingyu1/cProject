# include<stdio.h>
# include<time.h>
# include<math.h>
clock_t start, stop;
/* clock_t��clock()�������صı������� */
double duration;
/* ��¼���⺯������ʱ�䣬����Ϊ��λ */
# define MAXN 10 /* ����ʽ���������������ʽ����+1 */
# define MAXK 1e7 /* ���⺯������ظ����ô��� */

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
{ /* ���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ */ 
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ�� */
	for ( i=0; i<MAXN; i++) a[i] = (double)i; 
	
	start = clock();
	for ( i=0; i<MAXK; i++) /* �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ���� */ 
		f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	/* ��������ʱ�� */
	/* �������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ */
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("durations2 = %6.2e\n", duration);
	
	start = clock();
	for ( i=0; i<MAXK; i++) /* �ظ����ú����Ի�ó�ֶ��ʱ�Ӵ���� */ 
		f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	/* ��������ʱ�� */
	/* �������ڲ��Է�Χ�Ĵ���д�ں��棬�������duration��ֵ */
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("durations2 = %6.2e\n", duration);
	
	return 0; 
}
