#ifndef KEYABLE_H
#define KEYABLE_H
class Keyable
{
public:
	Keyable();
	~Keyable();
	virtual void setKey(long) = 0;
	virtual long getKey() const = 0;
private:
	long key;
};

Keyable::Keyable()
	:
	key(-1)
{
}

Keyable::~Keyable()
{
}
#endif