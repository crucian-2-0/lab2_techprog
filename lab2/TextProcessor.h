#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>

class TextProcessor {
public:
    // Читает файл, выводит только строки, НЕ содержащие двузначные числа
    // Возвращает true при успехе, false при ошибке открытия
    static bool processFile(const std::string& filename);
};

#endif