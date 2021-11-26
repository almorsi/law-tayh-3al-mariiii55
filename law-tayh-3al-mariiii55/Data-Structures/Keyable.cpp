#include <climits>
#include "Keyable.h"

Keyable::Keyable()
	:
	key(-1)
{
}

Keyable::~Keyable()
{
}

void Keyable::setKey(long k)
{
	key = k;
}

long Keyable::getKey() const
{
	return key;
}

void Keyable::increaseKeyBy(long dk)
{
	if (dk > LONG_MAX - key)
		throw "overflow";

	setKey(key + dk);
}
