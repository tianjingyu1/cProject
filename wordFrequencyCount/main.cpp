#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int TableSize = 10000; /* 散列表的估计大小*/
	int wordcount = 0, length;
	HashTable H;
	ElementType word;
	FILE *fp;
	char document[30]="HarryPootter.txt"; /* 要被统计词频的文件名*/
	H = InitializeTable(TableSize); /* 建立散列表*/
	if((fp = fopen(document,"r"))==NULL) FatalError("无法打开文件！\n");
	while(!feof(fp)){
		length = GetAWord(fp,word); /*从文件中读取一个单词*/
		if(length > 3){  /* 只考虑适当长度的单词*/
			wordcount++;  /* 统计文件中单词总数*/ 
			InsertAndCount(word,H);
		}
	} 
	fclose(fp);
	printf("该文档共出现%d个有效单词，",wordcount);
	Show(H, 10.0/100);  /* 显示词频前10%的单词 */ 
	DestroyTable(H);  /* 销毁散列表 */ 
	return 0;
}
