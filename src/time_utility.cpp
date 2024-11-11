#include "time_utility.h"

unsigned long long TimeUtility::getTimeInterval()
{
    using namespace std::chrono;
    auto now = system_clock::now();
    auto duration = duration_cast<seconds>(now.time_since_epoch());
    return duration.count(); // Return time interval in seconds
}
