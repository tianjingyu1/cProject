#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void InOrderTraversal( BinTree BT ) { 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
	while( T || !IsEmpty(S) ){
		while(T){ /*一直向左并将沿途结点压入堆栈*/
 			Push(S,T);
 			T = T->Left;
 		}
 		if(!IsEmpty(S)){
 			T = Pop(S); /*结点弹出堆栈*/
 			printf(“%5d”, T->Data); /*（访问）打印结点*/
 			T = T->Right; /*转向右子树*/
 		}
	} 
}
 
void InOrderTraversal( BinTree BT ) { 
	BinTree T BT;
	Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
	while( T || !IsEmpty(S) ){
 		while(T){ /*一直向左并将沿途结点压入堆栈*/
 			Push(S,T);
 			T = T->Left;
 		}
 		if(!IsEmpty(S)){
 			T = Pop(S); /*结点弹出堆栈*/
 			printf(“%5d”, T->Data); /*（访问）打印结点*/
 			T = T->Right; /*转向右子树*/
 		}
	} 
}
 
void LevelOrderTraversal ( BinTree BT ) { 
	Queue Q; 
	BinTree T;
	if ( !BT ) return; /* 若是空树则直接返回 */ 
	Q = CreatQueue( MaxSize ); /*创建并初始化队列Q*/
	AddQ( Q, BT );
	while ( !IsEmptyQ( Q ) ) {
 		T = DeleteQ( Q );
		printf(“%d\n”, T->Data); /*访问取出队列的结点*/
		if ( T->Left ) AddQ( Q, T->Left );
		if ( T->Right ) AddQ( Q, T->Right ); 
	} 
}

int main(int argc, char** argv) {
	return 0;
}
