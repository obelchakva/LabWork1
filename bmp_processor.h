/* Obelchak Vyacheslav st129564@student.spbu.ru
   Lab work #1
*/
#ifndef BMP_PROCESSOR_H
#define BMP_PROCESSOR_H

#include <string>
#include <vector>
#include <cstdint>

// Структура для хранения заголовка BMP
struct BMPHeader {
    uint16_t fileType{0x4D42};  // Тип файла ('BM' для BMP)
    uint32_t fileSize{0};       // Размер файла
    uint32_t reserved{0};       // Зарезервировано
    uint32_t dataOffset{54};    // Смещение до данных изображения
    uint32_t headerSize{40};    // Размер заголовка
    int32_t width{0};           // Ширина изображения
    int32_t height{0};          // Высота изображения
    uint16_t planes{1};         // Цветовые плоскости (всегда 1)
    uint16_t bitCount{8};       // Глубина цвета (8 бит/пиксель)
    uint32_t compression{0};    // Сжатие (0 - не сжато)
    uint32_t sizeImage{0};      // Размер данных изображения
    int32_t xPixelsPerMeter{2835}; // Разрешение по горизонтали
    int32_t yPixelsPerMeter{2835}; // Разрешение по вертикали
    uint32_t colorsUsed{256};   // Количество цветов
    uint32_t colorsImportant{256}; // Важные цвета
};

// Функции для работы с BMP
bool loadBMP(const std::string& filename, BMPHeader& header, std::vector<uint8_t>& image);
bool saveBMP(const std::string& filename, const BMPHeader& header, const std::vector<uint8_t>& image);
std::vector<uint8_t> rotateClockwise(BMPHeader& header, const std::vector<uint8_t>& image);
std::vector<uint8_t> rotateCounterClockwise(BMPHeader& header, const std::vector<uint8_t>& image);
std::vector<uint8_t> applyGaussianFilter(const BMPHeader& header, const std::vector<uint8_t>& image);

#endif
