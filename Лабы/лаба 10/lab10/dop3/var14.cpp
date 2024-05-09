//Вершина бинарного дерева содержит ключ и два указателя на потомков. Написать функцию вычисления среднего арифметического всех элементов дерева.

#include <iostream>

struct Tree 
{
	int key;
	Tree* Left, * Right;
};

using namespace std;

Tree* Root = NULL; 	//указатель корня

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key);  //Добавление нового элемент
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, int sum);  //Подсчет количества элементов
void delAll(Tree* t);             //Очистка дерева
int count2(Tree* t, int res);

int main() 
{
	setlocale(LC_ALL, "rus");
	int key, choice;
	int n;
	Tree* rc;
	for (;;)
	{
		cout << "Меню: \n";
		cout << "1. Создание дерева\n";
		cout << "2. Добавление элемента\n";
		cout << "3. Поиск по ключу\n";
		cout << "4. Удаление элемента\n";
		cout << "5. Вывод дерева\n";
		cout << "6. Очистка дерева\n";
		cout << "7. Подсчет среднего арифметического\n";
		cout << "8. Выход\n";
		cout << "Ваш выбор: ";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			insertElem(Root, key); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
				rc = search(Root, key);
				break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5: if (Root->key >= 0)
			{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
			}
			 else cout << "Дерево пустое\n";
			 break;
		case 6:  delAll(Root); Root = NULL; break;
		case 7:  n = count2(Root, 0) / count(Root, 0);
			     cout << "Среднее арифметическое всех элементов дерева равно: " << n << endl; break;
		case 8:  exit(0);
		}
	}


}

Tree* makeTree(Tree* Root) {
	int key;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL) {
		cout << "\nВведите ключ корня: "; cin >> key;
		Root = list(key);
	}
	while (1) {
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0) break;
		insertElem(Root, key);
	}
	return Root;
}

Tree* list(int i) {
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key)  //Добавление нового элемента
{
	Tree* Prev = nullptr;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		cout << endl;
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int count(Tree* t, int sum) //Подсчет элементов
{
	if (t)
	{	
		sum++;
		sum += count(t->Right, 0);//вывод правого поддерева
		sum += count(t->Left, 0); //вывод левого поддерева
	}
	return sum;
}

int count2(Tree* t, int res) //Подсчет суммы элементов
{
	if (t)
	{
		res += t->key; //добавление корня
		res += count2(t->Right, 0);
		res += count2(t->Left, 0);
	}
	return res;
}