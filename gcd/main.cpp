#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// 寻找a,b的最大公约数
// GCD(a,b) = GCD(b, a % b)
int Gcd(int a,int b){
	while (b != 0){
		// 计算余数
		int remainder = a % b;
		// 计算 GCD（b, remainder）
		a = b;
		b = remainder; 
	}
	
	// GCD(a,0)为a
	return a; 
} 
int main(int argc, char** argv) {
	int a = Gcd(5,15);
	printf("最大公约数为%d",a);
	return 0;
}
