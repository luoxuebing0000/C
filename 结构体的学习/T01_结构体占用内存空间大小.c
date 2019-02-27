// 定义struct的使用如果不足4的整数倍，则采用占位符来补充

typedef struct _tag_struct11
{
	int a;
	char b;
	char buf[9];
	int *c;
}TStruct11;

int main11(void)
{
	TStruct11 t1;
	int size = sizeof t1; // 对应到最小的int的整数倍
	return 0;
}