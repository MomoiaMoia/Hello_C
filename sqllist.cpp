#include <stdlib.h>
#include <stdio.h>
#include "sqlist.h"

// 初始化
Status InitList(SeqList& L) {
	L.data = new int[InitSize];
	if (!L.data) exit(OVERFLOW);
	L.length = 0;
	return OK;
}

// 取值
Status GetElem(SeqList L, int i, int& e) {
	if (i<1 || i>L.length) return ERROR;
	e = L.data[i - 1];
	return OK;
}

// 按位插入
Status ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length+1) return ERROR;
	if (L.length == InitSize) return ERROR;

	for (int j = L.length - 1; j >= i - 1; j--)
		L.data[j+1] = L.data[j];

	L.data[i - 1] = e;
	++L.length;
	return OK;
}

// 按位删除
Status ListDelete(SeqList& L, int i, int e) {
	if (i<1 || i>L.length - 1) return ERROR;

	e = L.data[i - 1];

	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];

	L.length--;
	return OK;
}

Status ListTravel(SeqList& L) {
	printf("[");
	for (int i = 0; i <= L.length - 1; i++) {
		if (i == L.length - 1) {
			printf("%d", L.data[i]);
			continue;
		}
		printf("%d, ", L.data[i]);
	}
	printf("]\n");
	return OK;
}



// Quest
// p.17 1
Status DeleteMin(SeqList& L, int& e) {
	e = L.data[0];
	int indexOfMin = 0;

	for (int i = 0; i <= L.length - 1; i++) {
		if (e > L.data[i]) {
			e = L.data[i];
			indexOfMin = i;
		}
	}
	
	L.data[indexOfMin] = L.data[L.length - 1];
	L.length--;
	return OK;
}

// p.17 2
// 算法思想: 折断一半 List 的长度，交换 i 和 倒序 i 个元素的位置
// 空间复杂度: O(1)
Status ReverseList(SeqList& L) {
	int temp = 0;
	for (int i = 0; i <= L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
	return OK;
}
