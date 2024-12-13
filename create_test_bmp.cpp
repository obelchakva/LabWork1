/* Obelchak Vyacheslav st129564@student.spbu.ru
   Lab work #1
*/
#include "bmp_processor.h"
#include <vector>
#include <fstream>
#include <iostream>

int main() {
    BMPHeader header;
    header.width = 256;       // Ширина изображения
    header.height = 256;      // Высота изображения
    header.bitCount = 8;      // 8 бит на пиксель (оттенки серого)
    header.headerSize = 40;
    header.dataOffset = 54 + 256 * 4; // С учетом таблицы цветов (256 записей по 4 байта)
    header.fileSize = header.dataOffset + header.width * header.height;
    header.sizeImage = header.width * header.height;

    // Создаем изображение с градиентом оттенков серого
    std::vector<uint8_t> image(header.width * header.height);
    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            uint8_t intensity = static_cast<uint8_t>((x + y) / 2); // Среднее от x и y для плавного градиента
            image[y * header.width + x] = intensity;
        }
    }

    // Открываем файл для записи
    std::ofstream file("input.bmp", std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not create BMP file." << std::endl;
        return 1;
    }

    // Запись заголовка
    file.write(reinterpret_cast<const char*>(&header.fileType), sizeof(header.fileType));
    file.write(reinterpret_cast<const char*>(&header.fileSize), sizeof(header.fileSize));
    file.write(reinterpret_cast<const char*>(&header.reserved), sizeof(header.reserved));
    file.write(reinterpret_cast<const char*>(&header.dataOffset), sizeof(header.dataOffset));
    file.write(reinterpret_cast<const char*>(&header.headerSize), sizeof(header.headerSize));
    file.write(reinterpret_cast<const char*>(&header.width), sizeof(header.width));
    file.write(reinterpret_cast<const char*>(&header.height), sizeof(header.height));
    file.write(reinterpret_cast<const char*>(&header.planes), sizeof(header.planes));
    file.write(reinterpret_cast<const char*>(&header.bitCount), sizeof(header.bitCount));
    file.write(reinterpret_cast<const char*>(&header.compression), sizeof(header.compression));
    file.write(reinterpret_cast<const char*>(&header.sizeImage), sizeof(header.sizeImage));
    file.write(reinterpret_cast<const char*>(&header.xPixelsPerMeter), sizeof(header.xPixelsPerMeter));
    file.write(reinterpret_cast<const char*>(&header.yPixelsPerMeter), sizeof(header.yPixelsPerMeter));
    file.write(reinterpret_cast<const char*>(&header.colorsUsed), sizeof(header.colorsUsed));
    file.write(reinterpret_cast<const char*>(&header.colorsImportant), sizeof(header.colorsImportant));

    // Запись таблицы цветов (палитры) для 8-битного BMP (256 оттенков серого)
    for (int i = 0; i < 256; ++i) {
        uint8_t color[4] = { static_cast<uint8_t>(i), static_cast<uint8_t>(i), static_cast<uint8_t>(i), 0 };
        file.write(reinterpret_cast<const char*>(color), sizeof(color));
    }

    // Запись данных изображения
    file.write(reinterpret_cast<const char*>(image.data()), image.size());

    file.close();
    std::cout << "BMP file 'input.bmp' with gradient created successfully!" << std::endl;

    return 0;
}
