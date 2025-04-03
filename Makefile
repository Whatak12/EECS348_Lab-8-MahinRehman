# define the compiler to use
CXX = g++

# define the compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# define the output executable name
TARGET = matrix_program

# define the source files
SRC = main.cpp matrix.cpp

# define the header files
HEADERS = matrix.hpp

# define the object files by replacing .cpp with .o
OBJ = $(SRC:.cpp=.o)

# default target to build the program
all: $(TARGET)

# rule to link object files into the final executable
$(TARGET): $(OBJ)
	# link object files to create executable
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# rule to compile .cpp files into .o files
%.o: %.cpp $(HEADERS)
	# compile each .cpp file into .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# rule to remove all generated files
clean:
	# remove object files and executable
	rm -f $(OBJ) $(TARGET)
