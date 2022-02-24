/* Author: NeterOster(neteroster@gmail.com)
*  Date: 2022/02/24
*  Thanks to: DSA-CPP (Data Structure & Algorithm in C++) Course by Deng of Tsinghua University.
*  DSA-CPP Public Course: https://dsa.cs.tsinghua.edu.cn/~deng/ds/dsacpp/
*/

#include <iostream>

using Rank = int;

template<typename T>
class MyVector
{
protected:
	int _size;
	int _capacity;
	T* _elem;

	void _expand();
	void _shrink();
	void _merge(Rank lo, Rank mi, Rank hi);

public:
	/* Constructor */
	MyVector(int capacity);

	/* Destructor */
	~MyVector();

	/* read-only(r) function */
	int size() const;
	bool empty() const;
	int disordered() const;
	Rank find(T const& e, Rank lo, Rank hi) const; // `this` should be a disordered vector.
	int search(T const& e, Rank lo, Rank hi) const; // `this` should be an ordered vector.

	/* write-possible(rw) function */
	T& operator[](Rank r);
	const T& operator[](Rank r) const;
	MyVector<T>& operator=(MyVector<T> const& v);
	int remove(Rank lo, Rank hi);
	T remove(Rank r);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e);
	void sort(Rank lo, Rank hi);
	void sort();
	int deduplicate();
	int uniquify();

	/* traverse */
	template <typename VST> void traverse(VST& v);
};

template<typename T>
void MyVector<T>::_expand()
{
	if ((_size << 1) >= _capacity) // _size >= _capacity / 2
	{
		// expand the vector (_capacity *= 2)
		T* old_elem = _elem;
		_elem = new T[_capacity <<= 2];

		for (int i = 0; i < _size; i++)
			_elem[i] = old_elem[i];

		delete[] old_elem;
	}
}

template<typename T>
void MyVector<T>::_shrink()
{
	if (_capacity == 0) return;
	if ((_size << 1) <= _capacity) // _size <= _capacity / 2
	{
		// shrink the vector (_capacity /= 2)
		T* old_elem = _elem;
		_elem = new T[_capacity >>= 1];

		for (int i = 0; i < _size; i++)
			_elem[i] = old_elem[i];

		delete[] old_elem;
	}
}

template<typename T>
void MyVector<T>::_merge(Rank lo, Rank mi, Rank hi)
{
	T* lr = _elem + lo;
	int lft_len = mi - lo;

	T* rgt = _elem + mi;
	int rgt_len = hi - mi;

	/* copy left array to a new space */
	T* lft_tmp = new T[lft_len];
	for (int i = 0; i < lft_len; i++)
		lft_tmp[i] = lr[i];

	/* merge */
	for (Rank i = 0, j = 0, k = 0; (k < lft_len || j < rgt_len); )  // continue even if one side is false.
	{
		/* lr -> i; rgt -> j; lft -> k */

		if (k < lft_len /* left is valid */
			&& /* and */
			(!(j < rgt_len) /* right is invalid */ || lft_tmp[k] < rgt[j]))
			lr[i++] = lft_tmp[k++];
		if (j < rgt_len /* right is valid */
			&& /* and */
			(!(k < lft_len) /* left is invalid */ || rgt[j] <= lft_tmp[k] /* must have `=` since not `else` */))
			lr[i++] = rgt[j++];
	}
	delete[] lft_tmp;
}

template<typename T>
MyVector<T>::MyVector(int capacity)
{
	_elem = new T[_capacity = capacity];
	_size = 0;
}

template<typename T>
MyVector<T>::~MyVector()
{
	delete[] _elem;
}

template<typename T>
int MyVector<T>::size() const
{
	return _size;
}

template<typename T>
bool MyVector<T>::empty() const
{
	return _size == 0;
}

template<typename T>
int MyVector<T>::disordered() const
{
	if (_size < 2) return 0;

	int disordered_num = 0;

	for (int i = 0; i < _size - 1; i++)
		if (_elem[i] > _elem[i + 1])
			disordered_num++;
	return disordered_num;
}

template<typename T>
Rank MyVector<T>::find(T const& e, Rank lo, Rank hi) const
{
	while (lo < (hi--) && _elem[hi] != e);
	return hi;
}

template<typename T>
int MyVector<T>::search(T const& e, Rank lo, Rank hi) const
{
	while (lo < hi)
	{
		int mi = (hi - lo) >> 1;
		_elem[mi] <= e ? lo = mi + 1 : hi = mi;
	}
	return lo - 1;
}

template<typename T>
T& MyVector<T>::operator[](Rank r)
{
	// assert: -1 < r < _size
	return _elem[r];
}

template<typename T>
const T& MyVector<T>::operator[](Rank r) const
{
	return _elem[r];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> const& v)
{
	if (_elem != 0) delete[] _elem;
	_elem = new T[_capacity = v._capacity];
	for (int i = 0; i < v._size; i++)
		_elem[i] = v._elem[i]; // deep copy
	_size = v._size;
}

template<typename T>
int MyVector<T>::remove(Rank lo, Rank hi)
{
	// assert: legel: lo, hi
	while (hi < _size)
		_elem[lo++] = _elem[hi++];
	_size = lo;
	_shrink();
	return hi - lo;

}

template<typename T>
T MyVector<T>::remove(Rank r)
{
	T removed = _elem[r];
	remove(r, r + 1);
	return removed;
}

template<typename T>
Rank MyVector<T>::insert(Rank r, T const& e)
{
	_expand();

	// _elem [r + 1, _size) -> [r + 2, _size + 1)
	for (int i = _size; r < i; i--)
		_elem[i] = _elem[i - 1];

	_elem[r] = e;
	_size++;

	return r;
}

template<typename T>
Rank MyVector<T>::insert(T const& e)
{
	return insert(_size, e);
}

template<typename T>
void MyVector<T>::sort(Rank lo, Rank hi) // merge sort: [lo, hi)
{
	if (hi - lo < 2) return;
	Rank mi = (lo + hi) >> 1;
	sort(lo, mi); sort(mi, hi);
	_merge(lo, mi, hi);
}

template<typename T>
void MyVector<T>::sort()
{
	sort(0, _size);
}

template<typename T>
int MyVector<T>::deduplicate()
{
	if (_size < 2) return 0;

	int old_size = _size;
	int p = 1;
	while (p < _size)
	{
		if (find(_elem[p], 0, p) < 0)
			p++;
		else
			remove(p);
	}
	_shrink();
	return old_size - _size;
}

template<typename T>
int MyVector<T>::uniquify()
{
	if (_size < 2) return 0;

	int i = 0; int j = 0; int removed = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i; _shrink();
	return j - i;
}

template<typename T>
template<typename VST>
void MyVector<T>::traverse(VST& v)
{
	for (int i = 0; i < _size; i++)
		v(_elem[i]);
}

template<typename T>
void print_vector(T& e)
{
	std::cout << e << " ";
}


void test_vector_auto_expand_shrink()
{
	MyVector<int> test_vector(1);
	test_vector.insert(0);

	for (int i = 1; i < 16384; i++)
		test_vector.insert(i);

	test_vector.remove(10, 16384);
	test_vector.remove(9, 10);

}

int main()
{
	test_vector_auto_expand_shrink();
}
