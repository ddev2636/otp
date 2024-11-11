#ifndef HASHING_UTILITY_H
#define HASHING_UTILITY_H

#include <string>

class HashingUtility
{
public:
    static unsigned char *generateHMAC(const std::string &key, const std::string &message); // Generate HMAC
};

#endif
