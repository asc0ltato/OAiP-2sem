#include "fstream"
#include "Tree.h"
Tree* Root = NULL; 	//указатель корня
int lit = 1000;
int Lkey = 0;

Tree* list(int i, int b[2], int sm)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->sum = sm;
	if (sm < lit) {
		lit = sm;
		Lkey = i;
	}
	for (i = 0; i < 2; i++)   //записываем инфу в структуру 
		*((t->a) + i) = *(b + i);

	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int b[2], int sm)  //Добавление нового элемента
{
	Tree* Prev = t;	     // Prev - элемент перед текущим
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
		t = list(key, b, sm);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key, a[2], sum = 0;


	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;

		cout << "Введите 2 числа корня: \n";
		for (int i = 0; i <2; i++) {
			cout << "Число номер: " << i + 1 << "\t";
			cin >> a[i];
			sum += a[i];
		}
		Root = list(key, a, sum);	// установка указателя на корень
	}

	while (1)                //добавление элементов
	{
		sum = 0;
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите 2 числа корня: \n";
		for (int i = 0; i < 2; i++) {
			cout << "Число номер: " << i + 1 << "\t";
			cin >> a[i];
			sum += a[i];
		}
		insertElem(Root, key, a, sum);
	}
	return Root;
}
void print(Tree* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print(t->Left, ++u);     //левое поддерево
		for (int i = 0; i < u; ++i)
			cout << "|";
		for (int m = 0; m < 2; m++)
			cout << t->a[m] << "\t";
		cout << endl;
		cout << "\nСумма элементов " << t->sum << endl;
		u--;
	}
	print(t->Right, ++u);          // правое поддерево
}
void insert(Tree* t, int u, ofstream& file1)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{

		cout << "Элементы в файле" << endl;
		insert(t->Left, ++u, file1);     //левое поддерево
		for (int i = 0; i < u; ++i)
			file1 << "|";
		for (int m = 0; m < 2; m++)
			file1 << t->a[m] << "\t";
		file1 << endl;
		//cout << "\nСумма элементов " << t->sum << endl;
		u--;

	}
	insert(t->Right, ++u, file1);          // правое поддерево
}

// Удаление элемента с минимальной суммой
Tree* delet(Tree* Root) // Удаление элемента с максимальной суммой двух значений узла
{
	int max_sum = INT_MIN;  // максимальная сумма найденных узлов
	Tree* Del = Root;  // удаляемый узел
	Tree* Prev_Del = NULL;  // родитель удаляемого узла
	Tree* Max_Del = NULL;  // узел с максимальной суммой
	Tree* Prev_Max_Del = NULL;  // родитель узла с максимальной суммой
	while (Del != NULL) {  // поиск узла с максимальной суммой
		if (Del->sum > max_sum) {
			max_sum = Del->sum;
			Max_Del = Del;
			Prev_Max_Del = Prev_Del;
		}
		Prev_Del = Del;
		if (Del->a[0] + Del->a[1] > max_sum) {
			max_sum = Del->a[0] + Del->a[1];
			Max_Del = Del;
			Prev_Max_Del = Prev_Del;
		}
		if (Del->a[0] + Del->a[1] <= max_sum && Del->Right != NULL) {
			Tree* tmp = Del->Right;
			while (tmp->Left != NULL) {
				tmp = tmp->Left;
			}
			if (tmp->sum > max_sum) {
				max_sum = tmp->sum;
				Max_Del = tmp;
				Prev_Max_Del = Del;
			}
			if (tmp->a[0] + tmp->a[1] > max_sum) {
				max_sum = tmp->a[0] + tmp->a[1];
				Max_Del = tmp;
				Prev_Max_Del = Del;
			}
		}
		Del = Del->Right;
	}
	if (Max_Del == NULL) { // элемент не найден
		puts("\nНет узлов");
		return Root;
	}
	Del = Max_Del;
	Prev_Del = Prev_Max_Del;
	Tree* R;
	Tree* Prev_R;
	if (Del->Right == NULL) { // поиск элемента R для замены
		R = Del->Left;
	}
	else if (Del->Left == NULL) {
		R = Del->Right;
	}
	else {
		Prev_R = Del; // поиск самого правого элемента в левом поддереве
		R = Del->Left;
		while (R->Right != NULL) { // поиск самого правого элемента в левом поддереве
			Prev_R = R;
			R = R->Right;
		}
		if (Prev_R == Del) { // найден элемент для замены R и его родителя Prev_R
			R->Right = Del->Right;
		}
		else {
			R->Right = Del->Right;
			Prev_R->Right = R->Left;
			R->Left = Del->Left;
		}
	}
	if (Del == Root) {
		Root = R; // удаление корня и замена его на R
	}
	else if (Del->key < Prev_Del->key) { // поддерево R присоединяется к родителю удаляемого узла
		Prev_Del->Left = R; // на левую ветвь
	}
	else {
		Prev_Del->Right = R; // на правую ветвь
	}
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

void view(Tree* t)
{
	if (t == NULL) return;
	cout << t->key << " " << "\n";
	view(t->Left);
	view(t->Right);
}
void view2(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	cout << t->key << " " << "\n";
	view(t->Right);
}
void view3(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	view(t->Right);
	cout << t->key << " " << "\n";
}

//Функиця вычисляет высоту заданного дерева
int height(Tree* t)
{

	if (t == NULL)
		return 0;

	return 1 + max((height(t->Left)),
		(height(t->Right)));
}
bool isBalanced(Tree* balanced)
{

	int lh;
	int rh;

	if (balanced == NULL)
		return 1;


	lh = height(balanced->Left);
	rh = height(balanced->Right);

	if (abs(lh - rh) <= 1 && isBalanced(balanced->Left) && isBalanced(balanced->Right))
		return 1;

	return 0;
}