#ifndef OTP_VALIDATOR_H
#define OTP_VALIDATOR_H

#include <string>

class OTPValidator
{
public:
    bool validateOTP(const std::string &otp, const std::string &secret); // Validate OTP
    bool isOTPValid(const std::string &otp, const std::string &secret);  // Validate OTP within time window
};

#endif
