#include "otp_generator.h"
#include "hashing_utility.h"
#include "time_utility.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip> // Include this header for setw and setfill

using namespace std;

OTPGenerator::OTPGenerator(const std::string &secret, const std::string &message, int otpLength)
    : secret(secret), otpLength(otpLength), message(message) {}

std::string OTPGenerator::generateOTP()
{
    // Create a TimeUtility object to get the current time interval
    TimeUtility timeUtility;
    unsigned long long timeInterval = timeUtility.getTimeInterval();
    message = std::to_string(timeInterval); // Update message with the current time interval

    unsigned char *hmacResult = HashingUtility::generateHMAC(secret, message);
    int truncatedValue = truncateHMAC(hmacResult);

    // Format OTP to match specified length
    std::ostringstream otpStream;
    otpStream << std::setw(otpLength) << std::setfill('0')
              << (truncatedValue % static_cast<int>(std::pow(10, otpLength)));

    return otpStream.str();
}

int OTPGenerator::truncateHMAC(unsigned char *hmacResult)
{
    int offset = hmacResult[SHA256_DIGEST_LENGTH - 1] & 0xf;
    int otp = (hmacResult[offset] & 0x7f) << 24 |
              (hmacResult[offset + 1] & 0xff) << 16 |
              (hmacResult[offset + 2] & 0xff) << 8 |
              (hmacResult[offset + 3] & 0xff);
    return otp;
}
