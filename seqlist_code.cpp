#include<iostream>
#include <stdlib.h>
using namespace std;

#define Max 25
typedef int element;



typedef struct {
	element data[Max];
	int length;//������Ŀǰ�ĳ��ȣ����Ǳ�
}seqlist, * slist;

typedef struct {
	element* data;
	int Maxsize, length;

}dlist;//Ϊ�����־�̬����Ͷ�̬���䣬ʹ��dlist��ʾ��̬�����˳���


//inif

void initlist(seqlist& a) {
	//��̬��˳����൱�ڡ������顱�Ѿ���������ʱ���������ˣ��������������ֱ��ָ����Ϊ0
	a.length = 0;

}

//dlist init
void initdlist(dlist& b) {
	b.Maxsize = Max;
	b.data = (element*)malloc(Max * sizeof(element));
	b.length = 0;
}
//�������
//insert
bool seqlistInsert(seqlist& a, int i, element x) {
	if (i<1 || i>a.length + 1)
		return false;
	if (a.length >= Max)
		return false;
	for (int j = a.length; j >= i; j--) {
		a.data[j] = a.data[j - 1];
	}//forѭ����ִ����ѭ����֮����ִ�е������ �൱�ڣ���������Ҫ�ڵ�3λ����һ�������߽������j=3�����һ��ѭ����ִ��֮ǰ��״̬���ж�ͨ���������һ��ѭ�����ִ�У���ʱdata[3]=data[2]����ʵ�ֵ���λ�����ڵ���λ�����൱�ڵ���λ�����Ƶ�����λ�ϣ����ʱ�����λ���͡��ճ����ˡ���ռλ���޹ؽ�Ҫ������ʱ����ѭ���壬���ִ��j--��j=2
	a.data[i-1] = x;
	a.length++;
	return true;
}

//dlistInsert
bool dlistInsert(dlist& a, int i, element x) {
	if (i<1 || i>a.length + 1)
		return false;
	if (a.length >= Max)
		return false;
	int j;
	for ( j = a.length; j >= i; j--) {
		a.data[j] = a.data[j - 1];
	}
	if (j == -1) {
		a.data[0] = x;
	}
	else {
		a.data[j] = x;
	}
	a.length++;
	return true;
}

void printseqlist(seqlist a,int i) {
	cout << a.data[i] << ":block:" << i << endl;
	return;
}
void printdlist(dlist a, int i) {
	cout << a.data[i] << ":block:" << i << endl;
}

//ɾ������
element deleteSeqlist(seqlist& a, int x) {
	if (x <= 0 || x > a.length)
		return -1;//����ֻ������������
	element e=a.data[x];//���ɾ����Ԫ��ֵ�����أ�����ʵ��ʹ�ò�����Ҫ��������ǽ���Ҫɾ�����У���������Ϊչʾ������ȷ��
	for (int i = x; i < a.length; i++) {
		a.data[i - 1] = a.data[i];
	}
	a.length=a.length-1;
	return e;
}

//���ڶ�̬˳���ֻ���ڱ�������ĵ�ʱ����Զ�̬��������Ŀռ䣬���������������һ���ģ�������Ļ�����������չʾ�ˣ�ֻչʾ��̬�������������������л�����������֮���һ�ʾ����̬����ռ�

//��ֵ����
int locateElem(seqlist& a, element x) {
	
	for (int i = 0; i < a.length; i++) {
		if (a.data[i] == x)return i + 1;
	}
	return -1;
}


int main() {
	seqlist test;
	//dlist 
	dlist dtest;
	initlist(test);
	initdlist(dtest);
	int y = 10;
	for (int j = 1; j <= 10; j++, y--) {
		bool flag = seqlistInsert(test, j, y);
		if (flag == 0) {
			cout << "erro" << endl;
			break;
		}

	}//10--1����洢��
	for (int j = 0; j <= dtest.length-1; j++) {
		bool flag = dlistInsert(dtest, j + 1, j + 1);//�ܷ�����������ط�����˼��һ�£�������һ�£�������ͬ����Ĳ���ʹ��ͬһ����---->���н���ǿ��ԣ�����ط������Ի��ԣ�����ʵ��������д�����ʱ��һ��������Ҫ��һ��������ռ�ñ�������������
	}//1--10˳��洢
	int s = 10;
	for (int i = 1; i <= s; ++i) {
		printdlist(dtest, i);
	}
	cout << "dong̬˳���ĸ���λ��˳��㱨����" << endl;
	//ɾ����������չʾ
	for (int i = 1; i <= s; ++i) {
		printseqlist(test, i);
	}
	cout << "��̬˳���ĸ���λ��˳��㱨����" << endl;

	//ɾ��������
	int c = 8;
	element deleteX=deleteSeqlist(test,c);
	//չʾɾ�����test˳���
	cout << deleteX << endl;
	for (int i = 1; i <= s; ++i) {
		printseqlist(test, i);

	}
	//��ֵ���ң�5
	int answer; element check = 5;
	answer = locateElem(test, check);
	cout << "���ҽ����" << answer << endl;

}