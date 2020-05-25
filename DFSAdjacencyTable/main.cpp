#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* �ڽӱ�洢��ͼ - DFS */
 
void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}
 
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;
     
    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */
 
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )    /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
}

int main(int argc, char** argv) {
	return 0;
}
