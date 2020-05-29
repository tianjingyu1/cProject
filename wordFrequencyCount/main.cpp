#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int TableSize = 10000; /* ɢ�б�Ĺ��ƴ�С*/
	int wordcount = 0, length;
	HashTable H;
	ElementType word;
	FILE *fp;
	char document[30]="HarryPootter.txt"; /* Ҫ��ͳ�ƴ�Ƶ���ļ���*/
	H = InitializeTable(TableSize); /* ����ɢ�б�*/
	if((fp = fopen(document,"r"))==NULL) FatalError("�޷����ļ���\n");
	while(!feof(fp)){
		length = GetAWord(fp,word); /*���ļ��ж�ȡһ������*/
		if(length > 3){  /* ֻ�����ʵ����ȵĵ���*/
			wordcount++;  /* ͳ���ļ��е�������*/ 
			InsertAndCount(word,H);
		}
	} 
	fclose(fp);
	printf("���ĵ�������%d����Ч���ʣ�",wordcount);
	Show(H, 10.0/100);  /* ��ʾ��Ƶǰ10%�ĵ��� */ 
	DestroyTable(H);  /* ����ɢ�б� */ 
	return 0;
}
