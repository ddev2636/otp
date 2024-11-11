#include "otp_validator.h"
#include "otp_generator.h"
#include "time_utility.h" // Include TimeUtility header
#include <string>
#include <iostream>

using namespace std; // Include this if needed
// using namespace util; // Use this if TimeUtility is in the "util" namespace

bool OTPValidator::validateOTP(const string &otp, const string &secret)
{
    OTPGenerator otpGenerator(secret);
    string generatedOtp = otpGenerator.generateOTP();
    cout << "Generated OTP: " << generatedOtp << endl;
    cout << "Entered OTP: " << otp << endl;

    if (otp == generatedOtp)
    {
        cout << "OTP validated successfully." << endl;
        return true;
    }
    else
    {
        cout << "Invalid OTP." << endl;
        return false;
    }
}

bool OTPValidator::isOTPValid(const std::string &enteredOTP, const std::string &secret)
{
    std::string message = "default_message"; // or fetch from somewhere else
    int otpLength = 6;                       // Set OTP length as needed

    // Create OTPGenerator with all required parameters
    OTPGenerator otpGenerator(secret, message, otpLength);

    // Now, you can call methods on otpGenerator to validate OTP
    std::string generatedOTP = otpGenerator.generateOTP(); // Assuming generateOTP() exists

    if (enteredOTP == generatedOTP)
    {
        return true; // OTPs match
    }
    return false; // OTPs don't match
}
