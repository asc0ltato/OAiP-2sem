#include <tchar.h>
#include "Tree.h"
#include <fstream>
using namespace std;

int main()
{
	setlocale(0, "Russian");
	int key, choice, n, z = 0;
	Tree* rc;
	int c = 0;
	Tree* Root = NULL;
	for (;;)
	{	
		cout << "Меню: \n";
		cout << "1. Создание дерева\n";
		cout << "2. Вывод дерева\n";
		cout << "3. Удалить вершину с максимальной суммой 2 целых значений узла\n";
		cout << "4. Запись в файл\n";
		cout << "5. Чтение из файла\n";
		cout << "6. Прямой(нисходящий) обход\n"; //Посетить корень Обойти левое поддерево Обойти правое поддерево
		cout << "7. Симметричный(смешанный) обход \n"; //Обойти левое поддерево Посетить корень  Обойти правое поддерево
		cout << "8. Обратный(восходящий) обход\n"; //Обойти левое поддерево Обойти правое поддерево Посетить корень
		cout << "9. Проверка на сбалансированность\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2: print(Root, 0); break;
		case 3: Root = delet(Root);  break;
		case 5: print(Root, 0); break;
		case 6:  if (Root->key >= 0)
			view(Root);
			  else cout << "Дерево пустое\n"; break;
		case 7: if (Root->key >= 0)
			view2(Root);
			  else cout << "Дерево пустое\n"; break;
		case 8: if (Root->key >= 0)
			view3(Root);
			  else cout << "Дерево пустое\n"; break;
		case 9:
			if (isBalanced(Root))
				cout << "Дерево сбалансированно\n";
			else
				cout << "Дерево несбалансированно\n";
			break;
		case 4: ofstream file1;
			file1.open("file1.txt");
			insert(Root, 0, file1);
			file1.close();
			break;
		}
	}
}		