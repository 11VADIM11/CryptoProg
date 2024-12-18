#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/md5.h>
#include <iostream>

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
        return 1;
    }

    
    const char *filename = argv[1];

    
    byte hash[Weak::MD5::DIGESTSIZE]; 

    
    try {
        
        Weak::MD5 md5;

        
        FileSource fileSource(
            filename, true,
            new HashFilter(md5, new ArraySink(hash, sizeof(hash)))
        );
    } catch (const Exception &e) {
        cerr << "Ошибка при чтении файла: " << e.what() << endl;
        return 1;
    }

    
    string encodedHash;
    StringSource(hash, sizeof(hash), true, new HexEncoder(new StringSink(encodedHash)));

    
    cout << "Text HASH: " << encodedHash << endl;

    return 0;
}

