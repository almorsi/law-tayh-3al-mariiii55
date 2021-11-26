#ifndef KEYABLE_H
#define KEYABLE_H
class Keyable
{
public:
	virtual void setKey(long) = 0;
	virtual long getKey() const = 0;
protected:
	long key{ -1 };
};
#endif