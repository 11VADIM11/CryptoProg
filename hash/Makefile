TARGET = hash
SRC = hash.cpp

INCLUDE = /usr/include/cryptopp
LIBS = /usr/lib

CXXFLAGS = -std=c++11 -I$(INCLUDE)
LDFLAGS = -lcryptopp

all: $(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
clean:
	rm -f $(TARGET)


