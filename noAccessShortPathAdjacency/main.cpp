#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* �ڽӱ��洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
 
/* dist[]��path[]ȫ����ʼ��Ϊ-1 */
void Unweighted ( LGraph Graph, int dist[], int path[], Vertex S )
{
    Queue Q;
    Vertex V;
    PtrToAdjVNode W;
     
    Q = CreateQueue( Graph->Nv ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
    dist[S] = 0; /* ��ʼ��Դ�� */
    AddQ (Q, S);
 
    while( !IsEmpty(Q) ){
        V = DeleteQ(Q);
        for ( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
            if ( dist[W->AdjV]==-1 ) { /* ��W->AdjVδ�����ʹ� */
                dist[W->AdjV] = dist[V]+1; /* W->AdjV��S�ľ������ */
                path[W->AdjV] = V; /* ��V��¼��S��W->AdjV��·���� */
                AddQ(Q, W->AdjV);
            }
    } /* while����*/
}

int main(int argc, char** argv) {
	return 0;
}