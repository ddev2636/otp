#include "hashing_utility.h"
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <string> // Include this header for std::string

using namespace std;

unsigned char *HashingUtility::generateHMAC(const string &key, const string &message)
{
    unsigned int len = SHA256_DIGEST_LENGTH;
    unsigned char *result = HMAC(EVP_sha256(), key.c_str(), key.length(),
                                 (unsigned char *)message.c_str(), message.length(), nullptr, &len);
    return result;
}
