#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Position Find( HashTable H, ElementType Key )
{
    Position CurrentPos, NewPos;
    int CNum = 0; /* ��¼��ͻ���� */
 
    NewPos = CurrentPos = Hash( Key, H->TableSize ); /* ��ʼɢ��λ�� */
    /* ����λ�õĵ�Ԫ�ǿգ����Ҳ���Ҫ�ҵ�Ԫ��ʱ��������ͻ */
    while( H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key ) {
                                           /* �ַ������͵Ĺؼ�����Ҫ strcmp ����!! */
        /* ͳ��1�γ�ͻ�����ж���ż�� */
        if( ++CNum%2 ){ /* �����γ�ͻ */
            NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; /* ����Ϊ+[(CNum+1)/2]^2 */
            if ( NewPos >= H->TableSize )
                NewPos = NewPos % H->TableSize; /* ����Ϊ�Ϸ���ַ */
        }
        else { /* ż���γ�ͻ */
            NewPos = CurrentPos - CNum*CNum/4; /* ����Ϊ-(CNum/2)^2 */
            while( NewPos < 0 )
                NewPos += H->TableSize; /* ����Ϊ�Ϸ���ַ */
        }
    }
    return NewPos; /* ��ʱNewPos������Key��λ�ã�������һ���յ�Ԫ��λ�ã���ʾ�Ҳ�����*/
}
 
bool Insert( HashTable H, ElementType Key )
{
    Position Pos = Find( H, Key ); /* �ȼ��Key�Ƿ��Ѿ����� */
 
    if( H->Cells[Pos].Info != Legitimate ) { /* ��������Ԫû�б�ռ��˵��Key���Բ����ڴ� */
        H->Cells[Pos].Info = Legitimate;
        H->Cells[Pos].Data = Key;
        /*�ַ������͵Ĺؼ�����Ҫ strcpy ����!! */
        return true;
    }
    else {
        printf("��ֵ�Ѵ���");
        return false;
    }
}

int main(int argc, char** argv) {
	return 0;
}