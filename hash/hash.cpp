#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/md5.h>
#include <iostream>

using namespace CryptoPP;
using namespace std;

int main() {
  // Путь к файлу для хэширования
  const char *filename = "/home/23ptv206@ibst.psu/CryptoProg/hash/text";

  // Переменные для хранения хэша
  string hashMsg;

  // Используем FileSource для чтения содержимого файла
  try {
    // Создание объекта MD5
    Weak::MD5 hash;

    // Чтение файла и обновление хэша
    FileSource fileSource(
        filename, true,
        new HashFilter(hash, new HashFilter(hash, new StringSink(hashMsg))));

    // Получаем размер хэша
    hashMsg.resize(hash.DigestSize());
    hash.Final((byte *)&hashMsg[0]);

  } catch (const Exception &e) {
    cerr << "Ошибка при чтении файла: " << e.what() << endl;
    return 1;
  }

  // Кодирование хэша в шестнадцатеричном формате
  string encodedHash;
  StringSource(hashMsg, true, new HexEncoder(new StringSink(encodedHash)));

  // Вывод результата
  cout << "Text HASH: " << encodedHash << endl;

  return 0;
}
