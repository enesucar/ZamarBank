#include "DateTime.h"

string DateTimeHelper::GetCurrentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d.%m.%Y %R", &tstruct);

    return buf;
}
