// Изучить работу с красно-черными деревьями. Реализовать основные операции над красно-черным деревом. В красно-черном дереве найти путь 
// от корня к некоторому листу, содержащий минимальное количество красных вершин.

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
enum COLOR { RED, BLACK };

struct node
{
    node(int const rhs) : data(rhs) {}
    COLOR color = RED;
    int data;
    node* left = nullptr, * right = nullptr, * parent = nullptr;
};

// дерево
node* root = nullptr;

//Функция поиска деда узла rhs
node* grandparent(node* rhs)
{
    node* ret = nullptr;
    if (rhs && rhs->parent) // если узел rhs не является корнем и у него есть родитель
    {
        ret = rhs->parent->parent; // то возвращаем родителя родителя rhs
    }

    return ret; // возвращаем указатель на деда rhs (если он есть)
}

//Функция поиска дяди узла rhs
node* uncle(node* rhs)
{
    node* ret = nullptr;
    if (node const* gp = grandparent(rhs)) // если узел rhs имеет деда
    {
        ret = (gp->left == rhs->parent ? gp->right : gp->left); // то возвращаем левого или правого сына деда в зависимости от того, с какой стороны находится родитель rhs
    }

    return ret;
}

//Функция для выполнения левого поворота в дереве
void rotate_left(node* rhs)
{
    node* pivot = rhs->right; // сохраняем правого потомка узла rhs в переменной pivot

    pivot->parent = rhs->parent; // обновляем родительскую ссылку для pivot, чтобы она указывала на родителя rhs
    if (rhs->parent != nullptr) // обновляем ссылку на потомка родителя rhs, чтобы она указывала на pivot
    {
        if (rhs->parent->left == rhs) // если rhs является левым потомком своего родителя, то
        {
            rhs->parent->left = pivot;
        }
        else
        {
            rhs->parent->right = pivot;
        }
    }
    else // если rhs был корнем дерева, то обновляем ссылку на корень, чтобы она указывала на pivot
    {
        root = pivot;
    }

    rhs->right = pivot->left;
    if (pivot->left != nullptr)
    {
        pivot->left->parent = rhs;
    }

    rhs->parent = pivot;
    pivot->left = rhs;
}

//Функция для выполнения правого поворота в дереве
void rotate_right(node* rhs)
{
    node* pivot = rhs->left;

    pivot->parent = rhs->parent;
    if (rhs->parent != nullptr)
    {
        if (rhs->parent->left == rhs)
        {
            rhs->parent->left = pivot;
        }
        else
        {
            rhs->parent->right = pivot;
        }
    }
    else
    {
        root = pivot;
    }

    rhs->left = pivot->right;
    if (pivot->right != nullptr)
    {
        pivot->right->parent = rhs;
    }

    rhs->parent = pivot;
    pivot->right = rhs;
}


void push_case1(node*);
void push_case2(node*);
void push_case3(node*);
void push_case4(node*);
void push_case5(node*);

// вставка
node* push(node*& root, int const data)
{
    node** pcur = &root;
    node* parent = nullptr;
    while (*pcur) // спускаемся по дереву, пока не находим пустое место для нового узла. если найден узел с таким же значением, то просто выходим из цикла
    {
        parent = *pcur;
        if (data < (*pcur)->data)
        {
            pcur = &(*pcur)->left;
        }
        else if (data > (*pcur)->data)
        {
            pcur = &(*pcur)->right;
        }
        else
        {
            break;
        }
    }
    if (nullptr == *pcur) // создаем новый узел и устанавливаем его родителя, затем вызываем push_case1 для правильного раскрашивания узла и выполнения поворотов
    {
        *pcur = new node(data);
        (*pcur)->parent = parent;

        push_case1(*pcur);
    }
    return 0;
}

void push_case1(node* rhs)
{
    if (rhs->parent == nullptr)
    {
        rhs->color = BLACK;
    }
    else
    {
        push_case2(rhs);
    }
}

void push_case2(node* n)
{
    if (n->parent->color == BLACK)
    {
        return; /* Tree is still valid */
    }
    else
    {
        push_case3(n);
    }
}

void push_case3(node* n)
{
    node* u = uncle(n), * g = nullptr;

    if ((u != nullptr) && (u->color == RED))
    {
        // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        push_case1(g);
    }
    else
    {
        push_case4(n);
    }
}

void push_case4(node* n)
{
    node* g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left))
    {
        rotate_left(n->parent);
        n = n->left;
    }
    else if ((n == n->parent->left) && (n->parent == g->right))
    {
        rotate_right(n->parent);
        n = n->right;
    }
    push_case5(n);
}

void push_case5(node* n)
{
    node* g = grandparent(n);

    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left))
    {
        rotate_right(g);
    }
    else
    { /* (n == n->parent->right) && (n->parent == g->right) */
        rotate_left(g);
    }
}

// поиск
node* find(int const data)
{
    node* ret = root;
    while (ret)
    {
        if (data < ret->data)
        {
            ret = ret->left;
        }
        else if (data > ret->data)
        {
            ret = ret->right;
        }
        else
        {
            break;
        }
    }

    return ret;
}

void DeleteTree(node* root)
{
    if (root)
    {
        root->data = NULL;
        root->left = NULL;
        root->right = NULL;
    }
}

int lft = 0, rght = 0, how = 0;
// печать дерева
void print(node* root, int indent = 0)
{

    if (root)
    {
        how = 0;
        print(root->right, indent + 1);
        for (int i = 0; i < indent; ++i)
        {
            std::cout << ".";
            how++;
        }
        std::cout << root->data << std::endl;
        print(root->left, indent + 1);
        if (how == 2 && root->left)
        {
            lft++;
        }
        if (how == 2 && root->right)
        {
            rght++;
        }
    }
}
void putt(node* root, int indent = 0)
{
    if (root)
    {
        if (lft > rght) {
            print(root->right, indent + 1);
        }
        for (int i = 0; i < indent; ++i)
        {
            std::cout << ".";
        }
        std::cout << root->data << std::endl;
        if (lft < rght) {
            print(root->left, indent + 1);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int choice = 0;
    int key = 0;
    do
    {
        cout << "Меню: \n";
        cout << "1. Добавление нового элемента\n";
        cout << "2. Вывод дерева \n";
        cout << "3. Очистка дерева\n";
        cout << "4. Поиск элемента дерева\n";
        cout << "5. Путь от корня к некоторому листу, содержащий минимальное количество красных вершин\n";
        cout << "0. Выход\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            string str;
            cout << "Введите ключ: "; cin >> key;
            cout << "Строка корня: "; cin >> str;
            push(root, key);
            break;
        }

        case 2: {
            print(root);
            cout << endl << endl;
            break;
        }

        case 3: {
            DeleteTree(root);
            break;
        }

        case 4: {

            string str;
            cout << "Введите элемент, который хотите найти: "; cin >> key;
            if (node* found = find(key))
            {
                std::cout << "\nНашли: " << found->data << std::endl;
            }
            cout << endl << endl;
            break;
        }

        case 5: {
            putt(root);
            cout << endl << endl;
        }

        case 0: {
            break;
        }
        }
    } while (choice != 0);
}