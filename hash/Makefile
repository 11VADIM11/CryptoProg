CXX = g++
CXXFLAGS = -g -Wall -std=c++11
LDFLAGS = -lcryptopp

TARGET = hash
SRCS = hash.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
