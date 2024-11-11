#include "time_utility.h"

unsigned long long TimeUtility::getTimeInterval()
{
    // Return time interval in seconds divided by 30 for 30-second TOTP intervals
    return std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::system_clock::now().time_since_epoch())
               .count() /
           30;
}
