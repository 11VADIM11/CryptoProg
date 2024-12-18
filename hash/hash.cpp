#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string file_content;
    std::string hash;

    
    std::ifstream file(filename, std::ios::binary);
    if (file) {
        std::ostringstream ss;
        ss << file.rdbuf(); 
        file_content = ss.str();
        file.close();
    } else {
        std::cerr << "Error reading file: " << filename << std::endl;
        return 1;
    }

    try {
        
        CryptoPP::MD5 md5;
        CryptoPP::StringSource(file_content, true,
            new CryptoPP::HashFilter(md5,
                new CryptoPP::HexEncoder(
                    new CryptoPP::StringSink(hash), false 
                )
            )
        );

        std::cout << "Hash: " << hash << std::endl;
    } catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

