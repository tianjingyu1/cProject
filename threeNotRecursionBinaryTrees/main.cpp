#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void InOrderTraversal( BinTree BT ) { 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/
	while( T || !IsEmpty(S) ){
		while(T){ /*һֱ���󲢽���;���ѹ���ջ*/
 			Push(S,T);
 			T = T->Left;
 		}
 		if(!IsEmpty(S)){
 			T = Pop(S); /*��㵯����ջ*/
 			printf(��%5d��, T->Data); /*�����ʣ���ӡ���*/
 			T = T->Right; /*ת��������*/
 		}
	} 
}
 
void InOrderTraversal( BinTree BT ) { 
	BinTree T BT;
	Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/
	while( T || !IsEmpty(S) ){
 		while(T){ /*һֱ���󲢽���;���ѹ���ջ*/
 			Push(S,T);
 			T = T->Left;
 		}
 		if(!IsEmpty(S)){
 			T = Pop(S); /*��㵯����ջ*/
 			printf(��%5d��, T->Data); /*�����ʣ���ӡ���*/
 			T = T->Right; /*ת��������*/
 		}
	} 
}
 
void LevelOrderTraversal ( BinTree BT ) { 
	Queue Q; 
	BinTree T;
	if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */ 
	Q = CreatQueue( MaxSize ); /*��������ʼ������Q*/
	AddQ( Q, BT );
	while ( !IsEmptyQ( Q ) ) {
 		T = DeleteQ( Q );
		printf(��%d\n��, T->Data); /*����ȡ�����еĽ��*/
		if ( T->Left ) AddQ( Q, T->Left );
		if ( T->Right ) AddQ( Q, T->Right ); 
	} 
}

int main(int argc, char** argv) {
	return 0;
}
