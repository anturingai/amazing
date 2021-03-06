// ConsoleApplication8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	int x;
	list *next;
}*head;

void print(struct list* node)
{
	if (node->next == NULL)
	{
		printf("%d", node->x);
		return;
	}
	print(node->next);
	printf("%d", node->x);
}

int main()
{
	int i, j, n;
	cout << "请输入n：" << endl;
	cin >> n;
	list *p;
	p = (struct list *)malloc(sizeof(struct list));
	head = p;
	p->x = 1;
	p->next = NULL;
	for (i = 1; i <= n; i++) {
		p = head;
		p->x *= i;
		while (p->next != NULL || p->x>9)
		{
			j = p->x;
			p->x = j % 10;
			if (p->next != NULL)
			{
				p = p->next;
				p->x = p->x*i + j / 10;
			}
			else
			{
				p->next = (struct list*)malloc(sizeof(struct list));
				p = p->next;
				p->x = j / 10;
				p->next = NULL;
			}
		}
	}
	print(head);
}

