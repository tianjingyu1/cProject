#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int PostOrderGetHeight( BinTree BT ) { int HL, HR, MaxH;
 	if( BT ) {
 		HL = PostOrderGetHeight(BT->Left); /*求左子树的深度*/
 		HR = PostOrderGetHeight(BT->Right); /*求右子树的深度*/
 		MaxH = （HL > HR）? HL : HR; /*取左右子树较大的深度*/
 		return ( MaxH + 1 ); /*返回树的深度*/
	}
 	else return 0; /* 空树深度为0 */
}

int main(int argc, char** argv) {
	return 0;
}
