#include"queue.h"
//���в���


//��ʼ������
void InitQueue(QuType* q)
{
	q = (QuType*)malloc(sizeof(QuType));
	q->front = q->rear = 0;
}

//���ٶ���
void DestroyQueue(QuType*& q)
{
	free(q);
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(QuType* q)
{
	if (q->front == q->rear)
		return 1;
	else return 0;
}

//���
int EnQueue(QuType* q, Box e)
{
	if (q->rear == 1000 - 1)
		return 0;
	q->rear = (q->rear + 1) % 1000;
	q->data[q->rear] = e;
	return 1;
}

//����
int DeQueue(QuType*& q, Box& e)
{
	if (q->front == q->rear)
		return 0;
	q->front = (q->front + 1) % 1000;
	e = q->data[q->front];
	return 1;
}

//�����Ƕ��в���