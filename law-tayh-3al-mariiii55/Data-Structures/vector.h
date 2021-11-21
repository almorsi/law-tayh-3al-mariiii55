#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void insertEnd(const T&);
	void insertBegin(const T&);
	void deleteBegin();
	void deleteEnd();

	T getFirst()const;
	void setFirst(T);
	T getLast() const;
	void setLast(T);

	T getAt(long k) const;
	void setAt(long, T);

	long getCapacity() const;
	long getLength() const;
	bool isEmpty()const;

private:
	T* array;

	long capacity;
	long begin;
	long end;

	static constexpr long INITIIAL_CAPACITY = 4;
	static constexpr long INITIIAL_BEGIN = 1;
	static constexpr long INITIIAL_END = 2;

	static constexpr long INSERTION_RESIZE_FACTOR = 2;
	static constexpr double BEGIN_RATIO = 0.33;

private:
	void resize(double);

	long getBegin()const;
	void setBegin(long);
	long getEnd()const;
	void setEnd(long);

	void incrementEnd();
	void incrementBegin();
	void decrementBegin();
	void decrementEnd();

	void setCapacity(long);

	long getRealAddress(long) const;
	bool isValidRealAddress(long) const;

	bool isHasToResizeOnInsertion();
};
#endif
