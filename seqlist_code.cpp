#include<iostream>
#include <stdlib.h>
using namespace std;

#define Max 25
typedef int element;



typedef struct {
	element data[Max];
	int length;//类似于目前的长度，就是表长
}seqlist, * slist;

typedef struct {
	element* data;
	int Maxsize, length;

}dlist;//为了区分静态分配和动态分配，使用dlist表示动态分配的顺序表


//inif

void initlist(seqlist& a) {
	//静态的顺序表相当于“类数组”已经在声明的时候就申请好了，无需申请操作，直接指明表长为0
	a.length = 0;

}

//dlist init
void initdlist(dlist& b) {
	b.Maxsize = Max;
	b.data = (element*)malloc(Max * sizeof(element*));
	b.length = 0;
}
//插入操作
//insert
bool seqlistInsert(seqlist& a, int i, element x) {
	if (i<1 || i>a.length + 1)
		return false;
	if (a.length >= Max)
		return false;
	for (int j = a.length; j >= i; j--) {
		a.data[j] = a.data[j - 1];
	}//for循环是执行完循环体之后在执行第三个项， 相当于，加入我需要在第3位插入一个数，边界情况是j=3是最后一次循环体执行之前的状态（判断通过进入最后一次循环体的执行，此时data[3]=data[2]是在实现第四位数等于第三位数，相当于第三位数后移到第四位上，这个时候第三位数就“空出来了”（占位但无关紧要），此时结束循环体，最后执行j--，j=2
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
	for ( j = a.length; j >= i; j--){
		a.data[j] = a.data[j - 1];
	}
	if (j == -1) {
		a.data[0] = x;
	}
	else {
		a.data[j] = x;
	}
	a.length=a.length+1;
	return true;
}

void printseqlist(seqlist a,int i) {
	cout << a.data[i] << ":block:" << i << endl;
	return;
}
void printdlist(dlist a, int i) {
	cout << a.data[i] << ":block:" << i << endl;
}

//删除操作
element deleteSeqlist(seqlist& a, int x) {
	if (x <= 0 || x > a.length)
		return -1;//假设只能输入零以上
	element e=a.data[x];//存放删除的元素值并返回：当让实际使用并不需要这个，我们仅仅要删除就行，我现在是为展示程序正确性
	for (int i = x; i < a.length; i++) {
		a.data[i - 1] = a.data[i];
	}
	a.length=a.length-1;
	return e;
}

//由于动态顺序表只是在表格用满的的时候可以动态扩大申请的空间，这里基本操作都是一样的，我下面的基本操作都不展示了，只展示静态分配的情况，并且在所有基本操作结束之后我会示范动态申请空间

//按值查找
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

	}//10--1倒序存储；
	int number = 1;
	for (int j = 1; j <= 10;++j,++number) {
		bool flag = dlistInsert(dtest, j, number);//能否这样？这个地方可以思考一下，试运行一下，两个不同意义的参数使用同一变量---->运行结果是可以，这个地方具有迷惑性，但是实际上正常写代码的时候一个意义需要用一个变量来占用表明，避免歧义
	}//1--10顺序存储
	int s = 10;
	for (int i = 0; i < s; ++i) {
		printdlist(dtest, i);
	}
	cout << "dong态顺序表的各个位置顺序汇报如上" << endl;
	//删除操作调试展示
	for (int i = 0; i < s; ++i) {
		printseqlist(test, i);
	}
	cout << "静态顺序表的各个位置顺序汇报如上" << endl;

	//删除操作；
	int c = 1;
	element deleteX=deleteSeqlist(test,c);
	//展示删除后的test顺序表：
	cout << deleteX << endl;
	for (int i = 0; i < test.length; ++i) {
		printseqlist(test, i);

	}
	//按值查找：7
	int answer; element check = 7;
	answer = locateElem(test, check);
	cout << "在删除了第一个数字之后的顺序表中查找7，结果为（位序）：" << answer<<"下标是" << answer - 1 << endl;

}
