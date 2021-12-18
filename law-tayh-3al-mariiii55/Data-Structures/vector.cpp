#include <algorithm>
#include <cmath>
#include "Vector.h"

template<typename T>
Vector<T>::Vector()
	:
	capacity(INITIAL_CAPACITY),
	begin(INITIAL_BEGIN),
	end(INITIAL_END)
{
	array = new T[capacity](); // allocate memory and initialize to zero
}

template<typename T>
Vector<T>::~Vector()
{
	delete [] array;
}

template<typename T>
long Vector<T>::getLength() const
{
	return end - begin - 1;
}

template<typename T>
long Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void Vector<T>::insertEnd(const T& item)
{
	array[getEnd()] = item;
	incrementEnd();
}

template<typename T>
void Vector<T>::insertBegin(const T& item)
{
	array[getBegin()] = item;
	decrementBegin();
}

template<typename T>
void Vector<T>::deleteBegin()
{
	incrementBegin();
}

template<typename T>
void Vector<T>::deleteEnd()
{
	decrementEnd();
}


template<typename T>
T& Vector<T>::getAt(long k) const
{
	long realAddress;

	realAddress = getRealAddress(k);
	if (isInValidRealAddress(realAddress))
		throw "out of bound";
	return array[realAddress];
}

template<typename T>
void Vector<T>::setAt(long k, T item)
{
	long realAddress;

	realAddress = getRealAddress(k);
	if (isInValidRealAddress(realAddress))
		throw "out of bound error";

	array[realAddress] = item;
}

template<typename T>
T& Vector<T>::getFirst() const
{
	return getAt(0);
}

template<typename T>
void Vector<T>::setFirst(T item)
{
	setAt(0, item);
}

template<typename T>
T& Vector<T>::getLast() const
{
	return getAt(getLength() - 1);
}

template<typename T>
void Vector<T>::setLast(T item)
{
	setAt(getLength() - 1, item);
}

template<typename T>
bool Vector<T>::isEmpty() const
{
	return getLength() == 0;
}

template<typename T>
void Vector<T>::resize(double factor)
{
	long i, k;
	long newBegin, newCapacity;
	long oldLength;
	T* newArray;

	newCapacity = long(getCapacity() * factor);
	newArray = new T[newCapacity];
	newBegin = long(std::ceil(BEGIN_RATIO * newCapacity));

	oldLength = getLength();
	for (k = 0, i = newBegin + 1; k < oldLength; k++, i++)
		newArray[i] = getAt(k);

	setBegin(newBegin);
	setEnd(i);
	setCapacity(newCapacity);
	delete [] array;
	array = newArray;
}

template<typename T>
void Vector<T>::setCapacity(long nc)
{
	capacity = nc;
}

template<typename T>
long Vector<T>::getBegin() const
{
	return begin;
}

template<typename T>
void Vector<T>::setBegin(long nb)
{
	begin = nb;
}

template<typename T>
void Vector<T>::setEnd(long ne)
{
	end = ne;
}

template<typename T>
long Vector<T>::getEnd() const
{
	return end;
}

template<typename T>
long Vector<T>::getRealAddress(long k) const
{
	return getBegin() + 1 + k;
}

template<typename T>
void Vector<T>::incrementEnd()
{
	end++;
	if (getEnd() == getCapacity())
		resize(INSERTION_RESIZE_FACTOR);
}

template<typename T>
void Vector<T>::decrementBegin()
{
	--begin;
	if (getBegin() == -1)
		resize(INSERTION_RESIZE_FACTOR);
}

template<typename T>
void Vector<T>::incrementBegin()
{
	if (getBegin() >= getEnd() - 1)
		throw "too much begin increment";
	begin++;
}

template<typename T>
void Vector<T>::decrementEnd()
{
	if (getEnd() <= getBegin() + 1)
		throw "too much deleting from the end";
	end--;
}

template<typename T>
bool Vector<T>::isInValidRealAddress(long realAddress) const
{
	return realAddress <= getBegin() || realAddress >= getEnd();
}
