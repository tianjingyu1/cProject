#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int PostOrderGetHeight( BinTree BT ) { int HL, HR, MaxH;
 	if( BT ) {
 		HL = PostOrderGetHeight(BT->Left); /*�������������*/
 		HR = PostOrderGetHeight(BT->Right); /*�������������*/
 		MaxH = ��HL > HR��? HL : HR; /*ȡ���������ϴ�����*/
 		return ( MaxH + 1 ); /*�����������*/
	}
 	else return 0; /* �������Ϊ0 */
}

int main(int argc, char** argv) {
	return 0;
}
