CXX = g++
CXXFLAGS = -std=c++11 -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lcryptopp
TARGET = md5_hash
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
 $(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
 rm -f $(TARGET)

.PHONY: all clean
