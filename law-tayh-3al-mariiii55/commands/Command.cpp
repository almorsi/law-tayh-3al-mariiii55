#include "Command.h"

bool Command::isTimeToExecute(const int stationdDataCurrentDay) const
{
    return md.eventDay == stationdDataCurrentDay;
}
