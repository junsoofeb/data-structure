#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
	int item;
	struct record * left;
	struct record * right;
}Record;

Record* add(Record* data, int item);
Record* delete(Record* data, int item);
void search(int item);
void print_inorder(Record * t);
Record* successor(Record* data);

Record * data = NULL;

int main()
{
	data = add(data, 5);
	print_inorder(data); printf("\n");

	data = add(data, 3);
	print_inorder(data); printf("\n");

	data = add(data, 7);
	print_inorder(data); printf("\n");

	data = add(data, 4);
	print_inorder(data); printf("\n");

	data = add(data, 6);
	print_inorder(data); printf("\n");

	search(5);

	data = delete(data, 5);

	search(5);

	print_inorder(data); printf("\n");


}

Record* add(Record* data, int item)
{
	if (data == NULL)
	{
		data = (Record*)malloc(sizeof(Record));
		data->left = data->right = NULL;
		data->item = item;

		return data;
	}
	else
	{
		if (data->item > item)
			data->left = add(data->left, item);
		else
			data->right = add(data->right, item);
	}

	return data;
}

Record* successor(Record* data) // successor�� �׻� ���� �ڽ��� ����.
{
	Record* succ = data;
	while (succ->left != NULL)
		succ = succ->left;
	return succ;
}

Record* delete(Record* data, int item)
{
	Record* tmp = NULL;
	if (data == NULL)
		return NULL;

	if (data->item > item)
		data->left = delete(data->left, item);
	else if (data->item < item)
		data->right = delete(data->right, item);
	else
	{
		// �ڽ� ��尡 �� �� �� ���� ��쿡 successor�� ��ü!
		if (data->right != NULL && data->left != NULL)
		{
			tmp = successor(data->right);
			data->item = tmp->item;
			data->right = delete(data->right, tmp->item);
		}
		else
		{
			tmp = (data->left == NULL) ? data->right : data->left;
			free(data);
			return tmp;
		}
	}

	return data;
}

void search(int item)
{
	Record *r; // �񱳿� ������
	r = data;

	while (r != NULL) // data�� ����ִٸ� ���� while���� ���õȴ�.
	{ 
		if ((r->item - item) < 0) //�Է°���  data�� ������ �۴ٸ� ���ʸ�ũ�� �̵� �� �ݺ�
			r = r->left;

		else if ((r->item - item) == 0) { //������ ����ϰ� ��
			printf("%d is in the data.\n", r->item);
			return;
		}

		else // �Է°��� ũ�� �����ʸ�ũ�� �̵��ؼ� �ݺ�
			r = r->right;
	}

	printf("Couldn't find %d.\n",item); // �ּҷ� ����־ while�� ���� X   or   �����ߴµ� ����
}

void print_inorder(Record * t)
{
	if (t == 0)
		return;
		

	print_inorder(t->left);
	printf("%d ",t->item);
	print_inorder(t->right);
}
