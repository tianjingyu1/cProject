#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXN 1001 
#define MINH -10001 
 
int H[MAXN], size; 
 
void Create () {        
	size = 0;              
	H[0] = MINH;                 
	/*设置“岗哨”*/ 
} 
  
void Insert ( int X ) {      
	/* 将X插入H。这里省略检查堆是否已满的代码 */  
	int i; 
 	for (i=++size; H[i/2] > X; i/=2)   
	 	H[i] = H[i/2];  
	H[i] = X; 
} 
 
 
int main(int argc, char** argv) {
	int n, m, x, i, j; 
 	scanf("%d %d", &n, &m);          
	Create();                      /* 堆初始化 */          
	for (i=0; i<n; i++) {      
		/*以逐个插入方式建堆 */  
		scanf("%d", &x);  
		Insert(x);          
	} 
 	for (i=0; i<m; i++) {  
	 	scanf("%d", &j);  
		printf("%d", H[j]);  
		while (j>1) { 
			/*沿根方向输出各结点*/            
			j /= 2;            
			printf(" %d", H[j]);  
		}  
		printf("\n"); 
	} 
 	return 0; 
}   
