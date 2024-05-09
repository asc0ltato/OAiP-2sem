//Реализуйте алгоритм поиска k - го наименьшего элемента в неотсортированном массиве на основе бинарной кучи.
//Для этого используйте минимальную бинарную кучу размера k и добавляйте элементы массива в кучу до тех пор, пока ее размер не станет равным k.
//Затем каждый новый элемент сравнивается с корнем кучи, и если он меньше, то корень заменяется на этот элемент.
//В результате корень кучи будет содержать k - ый наименьший элемент массива

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct HeapElement {
    int value;
    int index;
};

//оператор сравнения элементов кучи
struct HeapElementCompare {
    bool operator()(const HeapElement& lhs, const HeapElement& rhs) const {
        return lhs.value > rhs.value;
    }
};

//функция нахождения k-го наименьшего элемента массива
int findKthSmallestElement(const vector<int>& array, int k) {

    priority_queue<HeapElement, vector<HeapElement>, HeapElementCompare> heap;

    //добавляем в кучу первые k элементов массива
    for (int i = 0; i < k; ++i) {
        HeapElement heapElement;
        heapElement.value = array[i];
        heapElement.index = i;
        heap.push(heapElement);
    }

    //проходим по массиву
    for (int i = k; i < array.size(); ++i) {
        //если новый элемент меньше корня кучи, заменяем корень на новый элемент
        if (array[i] < heap.top().value) {
            HeapElement heapElement;
            heapElement.value = array[i];
            heapElement.index = i;
            heap.pop();
            heap.push(heapElement);
        }
    }

    //возвращаем значение корня кучи
    return heap.top().value;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    cout << "Введите размер массива: ";
    cin >> n;
    cout << "Введите k: ";
    cin >> k;
    vector<int> array(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << "k-й наименьший элемент массива: " << findKthSmallestElement(array, k) << endl;
    return 0;
}