#include"queue.h"
//队列操作


//初始化队列
void InitQueue(QuType* q)
{
	q = (QuType*)malloc(sizeof(QuType));
	q->front = q->rear = 0;
}

//销毁队列
void DestroyQueue(QuType*& q)
{
	free(q);
}

//判断队列是否为空
int QueueEmpty(QuType* q)
{
	if (q->front == q->rear)
		return 1;
	else return 0;
}

//入队
int EnQueue(QuType* q, Box e)
{
	if (q->rear == 1000 - 1)
		return 0;
	q->rear = (q->rear + 1) % 1000;
	q->data[q->rear] = e;
	return 1;
}

//出队
int DeQueue(QuType*& q, Box& e)
{
	if (q->front == q->rear)
		return 0;
	q->front = (q->front + 1) % 1000;
	e = q->data[q->front];
	return 1;
}

//以上是队列操作