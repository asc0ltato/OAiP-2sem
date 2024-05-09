//Дано N чисел, N > 0. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а правая дочерняя вершина является внутренней. Для каждой внутренней
//вершины вначале создавать левую дочернюю вершину, а затем правую(если она существует); каждой создаваемой вершине присваивать очередное значение из исходного набора

#include <iostream>
using namespace std;
struct tree {
	int data;
	tree* left, * right;
};
tree* tree1 = NULL;
void insert(int a, tree** t, int N)
{
	if (!N) return;
	if (*t == nullptr)
	{
		(*t) = new tree;
		(*t)->data = a;
		(*t)->left = (*t)->right = nullptr;
		return;
	}
	if (!(*t)->left)
		insert(a, &(*t)->left, N);
	else
		insert(a, &(*t)->right, N);
}
void print(tree* t, int level)
{
	if (t == nullptr)return;
	else
	{
		print(t->left, ++level);
		for (int i = 0; i < level; ++i)
			cout << "|";
		cout << t->data << endl;
		level--;
	}
	print(t->right, ++level);
}
void del(tree** t)
{
	if (t != nullptr)
	{
		if ((*t)->left)del(&(*t)->left);
		if ((*t)->right)del(&(*t)->right);
		delete* t;
		*t = nullptr;
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice, n, i = 1;
	for (;;)
	{
		cout << "Меню: \n";
		cout << "1. Создание дерева\n";
		cout << "2. Вывод дерева\n";
		cout << "3. Удаление дерева\n";
		cout << "4. Выход \n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:
			cout << "введите количество вершин:" << endl;
			cin >> n;
			int a;
			while (i++ <= n)
			{
				cout << "введите число:";	
				cin >> a;
				cout << endl;
				insert(a, &tree1, n);
			}
			break;
		case 2:
			print(tree1, 0);
			system("pause");
			break;
		case 3: break;
			del(&tree1);
		case 4:
			exit(0);
			break;
		}
	}
}