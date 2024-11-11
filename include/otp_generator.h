#ifndef OTP_GENERATOR_H
#define OTP_GENERATOR_H

#include <string>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include "hashing_utility.h"

class OTPGenerator
{
public:
    std::string secret;  // Secret key used for OTP generation
    int otpLength;       // Length of the generated OTP
    std::string message; // Message to generate OTP from

    // Constructor: Takes secret, message, and otpLength as arguments
    OTPGenerator(const std::string &secret, const std::string &message, int otpLength);
    OTPGenerator(const std::string &secret) : OTPGenerator(secret, "default_message", 6) {} // Defaults

    std::string generateOTP();                   // Function to generate OTP
    int truncateHMAC(unsigned char *hmacResult); // Function to truncate HMAC result
};

#endif // OTP_GENERATOR_H
