CXX = gcc
CXXFLAGS = -std=c23 -Iinclude -Wall -g
TARGET = linreg 

SRC = $(wildcard *.c)
HDR = $(wildcard *.h) 

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

all: $(TARGET)

clean:
	rm -f $(TARGET)
