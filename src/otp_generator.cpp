#include "otp_generator.h"
#include "hashing_utility.h"
#include "time_utility.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

OTPGenerator::OTPGenerator(const std::string &secret, const std::string &message, int otpLength)
    : secret(secret), otpLength(otpLength), message(message) {}

std::string OTPGenerator::generateOTP()
{
    unsigned char *hmacResult = HashingUtility::generateHMAC(secret, message);
    int truncatedValue = truncateHMAC(hmacResult);
    return std::to_string(truncatedValue).substr(0, otpLength); // Limiting OTP length
}

int OTPGenerator::truncateHMAC(unsigned char *hmacResult)
{
    int offset = hmacResult[SHA256_DIGEST_LENGTH - 1] & 0xf;
    int otp = (hmacResult[offset] & 0x7f) << 24 |
              (hmacResult[offset + 1] & 0xff) << 16 |
              (hmacResult[offset + 2] & 0xff) << 8 |
              (hmacResult[offset + 3] & 0xff);
    return otp % 1000000; // Ensure OTP is a 6-digit number
}