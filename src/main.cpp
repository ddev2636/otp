#include <iostream>
#include "otp_generator.h"
#include "otp_validator.h"

using namespace std;

int main()
{
    std::string secret = "mysecretkey"; // Example secret key
    std::string message = "my message"; // Example message used in OTP generation
    int otpLength = 6;                  // Length of the generated OTP

    // Create OTPGenerator object with secret, message, and otpLength
    OTPGenerator otpGenerator(secret, message, otpLength);

    // Generate OTP
    std::string otp = otpGenerator.generateOTP();
    std::cout << "Generated OTP: " << otp << std::endl;

    // Take user input for OTP validation
    std::string enteredOtp;
    std::cout << "Enter OTP: ";
    std::cin >> enteredOtp;

    // Validate OTP (you can implement the validation logic here)
    if (enteredOtp == otp)
    {
        std::cout << "OTP validated successfully!" << std::endl;
    }
    else
    {
        std::cout << "Invalid OTP." << std::endl;
    }

    return 0;
}