#include <stdio.h>
#include <stdlib.h>
#include <random>
#include "sqlist.h"

int main(void) {

	SeqList L;
	srand(time(NULL));

	InitList(L);
	for (int i = 0; i < 30; i++) {
		int randomInt = rand() % 100 + 1;
		ListInsert(L, i, randomInt);
	}
	ListTravel(L);


	ReverseList(L);
	ListTravel(L);
}


