#define OK 0
#define ERROR 1
#define OVERFLOW -2
#define InitSize 100

typedef int Status;

typedef struct {
	int* data;
	int MaxSize, length;
} SeqList;

// basic operation
Status InitList(SeqList& L);
Status GetElem(SeqList L, int i, int& e);
Status ListInsert(SeqList& L, int i, int e);
Status ListDelete(SeqList& L, int i, int e);
Status ListTravel(SeqList& L);

// Quest
Status DeleteMin(SeqList& L, int& e);
Status ReverseList(SeqList& L);


