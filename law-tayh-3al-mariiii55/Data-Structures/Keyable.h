#ifndef KEYABLE_H
#define KEYABLE_H
class Keyable
{
public:
	Keyable();
	virtual ~Keyable();
	virtual void setKey(long);
	virtual long getKey() const;
	virtual void increaseKeyBy(long);
protected:
	long key{ -1 };
};
#endif