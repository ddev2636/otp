# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -I./include -L/usr/local/lib -lssl -lcrypto

# Source and Object files
SRC = src/main.cpp src/otp_generator.cpp src/hashing_utility.cpp src/time_utility.cpp src/otp_validator.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = otp_generator

# Default target to build the project
all: $(EXEC)

# Link object files into the final executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(CXXFLAGS)

# Rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)
