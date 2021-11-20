#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
	long getLength() const;
	long getCapacity() const;
	void insertEnd(const T&);
	void insertBegin(const T&);
	void deleteBegin();
	void deleteEnd();
	T getAt(long k) const;
	void setAt(long, T);
	T getFirst()const;
	void setFirst(T);
	bool isEmpty()const;

private:
	T* array;
	long capacity;
	long begin;
	long end;
	static constexpr long INSERTION_RESIZE_FACTOR = 2;
	static constexpr double BEGIN_RATIO = 0.33;
	static constexpr long INITIIAL_CAPACITY = 4;
	static constexpr long INITIIAL_BEGIN = 1;
	static constexpr long INITIIAL_END = 2;

private:
	void resize(double);
	void setCapacity(long);
	long getBegin()const;
	void setBegin(long);
	void setEnd(long);
	long getEnd()const;
	long getRealAddress(long) const;
	void incrementEnd();
	void incrementBegin();
	void decrementBegin();
	void decrementEnd();
	bool isValidRealAddress(long) const;
	bool isHasToResizeOnInsertion();
};
#endif
