#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Ѱ��a,b�����Լ��
// GCD(a,b) = GCD(b, a % b)
int Gcd(int a,int b){
	while (b != 0){
		// ��������
		int remainder = a % b;
		// ���� GCD��b, remainder��
		a = b;
		b = remainder; 
	}
	
	// GCD(a,0)Ϊa
	return a; 
} 
int main(int argc, char** argv) {
	int a = Gcd(5,15);
	printf("���Լ��Ϊ%d",a);
	return 0;
}
