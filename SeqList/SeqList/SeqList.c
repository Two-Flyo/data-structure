#include"SeqList.h"

//顺序表扩容
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//利用三目运算符对没有空间和空间不足的情况进行分别处理
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//打印顺序表
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity=0;
}

//1.整个顺序表没有空间
//2.空间不够  扩容
//3.空间足够，直接插入数据即可
void SeqListPushBack(SL* ps, SLDataType x)
{
	//没有空间 空间不足就扩容
	//1.
	//SeqListCheckCapacity(ps);
	//ps->a[ps->size] = x;//空间足够
	//ps->size++;
	//2.调用插入函数
	SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
	//两种处理顺序表为空的方式均可
	//if (ps->size > 0)
	//{
	//	ps->size--;
	//}
	//(1).手动实现
	//assert(ps->size > 0);
	//ps->size--;
	//(2).调用删除函数
	SeqListErase(ps, ps->size - 1);
	
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	//挪动数据
	//1.手动实现
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	//2.调用插入函数
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	//1.手动实现
	//assert(ps->size > 0);
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;
	//2.调用实现的删除函数
	SeqListErase(ps, 0);
}


int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//if (pos > ps->size || pos < 0)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	assert(pos <= ps->size&&pos >= 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin <= ps->size - 1)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}