#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define KEYLENGTH 15                   /* �ؼ����ַ�������󳤶� */
typedef char ElementType[KEYLENGTH+1]; /* �ؼ����������ַ��� */
typedef int Index;                     /* ɢ�е�ַ���� */
/******** �����ǵ������Ķ��� ********/
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** �����ǵ������Ķ��� ********/
 
typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б���㶨�� */
    int TableSize; /* ������󳤶� */
    List Heads;    /* ָ������ͷ�������� */
};
 
HashTable CreateTable( int TableSize )
{
    HashTable H;
    int i;
 
    H = (HashTable)malloc(sizeof(struct TblNode));
    /* ��֤ɢ�б���󳤶������������������5.3 */
    H->TableSize = NextPrime(TableSize);
 
    /* ���·�������ͷ������� */
    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
    /* ��ʼ����ͷ��� */
    for( i=0; i<H->TableSize; i++ ) {
         H->Heads[i].Data[0] = '\0';
         H->Heads[i].Next = NULL;
    }
 
    return H;
}
 
Position Find( HashTable H, ElementType Key )
{
    Position P;
    Index Pos;
     
    Pos = Hash( Key, H->TableSize ); /* ��ʼɢ��λ�� */
    P = H->Heads[Pos].Next; /* �Ӹ������ĵ�1����㿪ʼ */
    /* ��δ����β������Keyδ�ҵ�ʱ */ 
    while( P && strcmp(P->Data, Key) )
        P = P->Next;
 
    return P; /* ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL */
}
 
bool Insert( HashTable H, ElementType Key )
{
    Position P, NewCell;
    Index Pos;
     
    P = Find( H, Key );
    if ( !P ) { /* �ؼ���δ�ҵ������Բ��� */
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        Pos = Hash( Key, H->TableSize ); /* ��ʼɢ��λ�� */
        /* ��NewCell����ΪH->Heads[Pos]�����ĵ�1����� */
        NewCell->Next = H->Heads[Pos].Next;
        H->Heads[Pos].Next = NewCell; 
        return true;
    }
    else { /* �ؼ����Ѵ��� */
        printf("��ֵ�Ѵ���");
        return false;
    }
}
 
void DestroyTable( HashTable H )
{
    int i;
    Position P, Tmp;
     
    /* �ͷ�ÿ�������Ľ�� */
    for( i=0; i<H->TableSize; i++ ) {
        P = H->Heads[i].Next;
        while( P ) {
            Tmp = P->Next;
            free( P );
            P = Tmp;
        }
    }
    free( H->Heads ); /* �ͷ�ͷ������� */
    free( H );        /* �ͷ�ɢ�б���� */
}

int main(int argc, char** argv) {
	return 0;
}