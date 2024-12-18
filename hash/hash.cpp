#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/md5.h>
#include <iostream>

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[]) {
    // Проверка наличия аргумента командной строки
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " <путь к файлу>" << endl;
        return 1;
    }

    // Путь к файлу для хэширования
    const char *filename = argv[1];

    // Переменные для хранения хэша
    byte hash[Weak::MD5::DIGESTSIZE]; // Массив для хранения значений хэша

    // Используем FileSource для чтения содержимого файла
    try {
        // Создание объекта MD5
        Weak::MD5 md5;

        // Чтение файла и обновление хэша
        FileSource fileSource(
            filename, true,
            new HashFilter(md5, new ArraySink(hash, sizeof(hash)))
        );
    } catch (const Exception &e) {
        cerr << "Ошибка при чтении файла: " << e.what() << endl;
        return 1;
    }

    // Кодирование хэша в шестнадцатеричном формате
    string encodedHash;
    StringSource(hash, sizeof(hash), true, new HexEncoder(new StringSink(encodedHash)));

    // Вывод результата
    cout << "Text HASH: " << encodedHash << endl;

    return 0;
}

