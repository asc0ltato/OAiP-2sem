#pragma once

struct AAA
{
	int x;
	void print();
	int getPriority() const;
};

namespace heap
{
	enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };
	struct Heap
	{
		int size;
		int maxSize;
		void** storage;
		CMP(*compare)(void*, void*);
		Heap(int maxxize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxxize];
			compare = f;
		};
		int left(int ix);
		int right(int ix);
		int parent(int ix);
		bool isFull() const
		{
			return (size >= maxSize);
		}
		bool isEmpty() const
		{
			return (size <= 0);
		}
		bool isLess(void* x1, void* x2) const
		{
			return compare(x1, x2) == LESS;
		}
		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL;
		}
		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT;
		}
		void swap(int i, int j);
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();
		void* extractMin();
		void* extractI(int i);
		void scan(int i) const;

	};
	Heap create(int maxsize, CMP(*f)(void*, void*));
	void unionHeap(Heap*, Heap*);
}