/* Obelchak Vyacheslav st129564@student.spbu.ru
   Lab work #1
*/
#include "bmp_processor.h"
#include <iostream>
#include <fstream>
#include <vector>

bool loadBMP(const std::string& filename, BMPHeader& header, std::vector<uint8_t>& image) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // Считываем заголовок BMP
    file.read(reinterpret_cast<char*>(&header.fileType), sizeof(header.fileType));
    file.read(reinterpret_cast<char*>(&header.fileSize), sizeof(header.fileSize));
    file.read(reinterpret_cast<char*>(&header.reserved), sizeof(header.reserved));
    file.read(reinterpret_cast<char*>(&header.dataOffset), sizeof(header.dataOffset));
    file.read(reinterpret_cast<char*>(&header.headerSize), sizeof(header.headerSize));
    file.read(reinterpret_cast<char*>(&header.width), sizeof(header.width));
    file.read(reinterpret_cast<char*>(&header.height), sizeof(header.height));
    file.read(reinterpret_cast<char*>(&header.planes), sizeof(header.planes));
    file.read(reinterpret_cast<char*>(&header.bitCount), sizeof(header.bitCount));
    file.read(reinterpret_cast<char*>(&header.compression), sizeof(header.compression));
    file.read(reinterpret_cast<char*>(&header.sizeImage), sizeof(header.sizeImage));
    file.read(reinterpret_cast<char*>(&header.xPixelsPerMeter), sizeof(header.xPixelsPerMeter));
    file.read(reinterpret_cast<char*>(&header.yPixelsPerMeter), sizeof(header.yPixelsPerMeter));
    file.read(reinterpret_cast<char*>(&header.colorsUsed), sizeof(header.colorsUsed));
    file.read(reinterpret_cast<char*>(&header.colorsImportant), sizeof(header.colorsImportant));

    // Отладочный вывод загруженных значений
    std::cout << "File type: " << header.fileType << std::endl;
    std::cout << "File size: " << header.fileSize << std::endl;
    std::cout << "Data offset: " << header.dataOffset << std::endl;
    std::cout << "Header size: " << header.headerSize << std::endl;
    std::cout << "Width: " << header.width << std::endl;
    std::cout << "Height: " << header.height << std::endl;
    std::cout << "Bit count: " << header.bitCount << std::endl;
    std::cout << "Compression: " << header.compression << std::endl;
    std::cout << "Image size: " << header.sizeImage << std::endl;

    // Проверяем, правильно ли загружены основные параметры
    if (header.fileType != 0x4D42) {
        std::cerr << "Error: Not a BMP file." << std::endl;
        return false;
    }

    // Перемещаем указатель на начало данных изображения и загружаем их
    file.seekg(header.dataOffset, std::ios::beg);
    image.resize(header.sizeImage);
    file.read(reinterpret_cast<char*>(image.data()), header.sizeImage);

    // Проверяем, что данные изображения загружены
    if (image.empty()) {
        std::cerr << "Error: Failed to load image data." << std::endl;
        return false;
    }

    return true;
}

bool saveBMP(const std::string& filename, const BMPHeader& header, const std::vector<uint8_t>& image) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // Запись заголовка BMP
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

    // Запись данных изображения
    file.write(reinterpret_cast<const char*>(image.data()), image.size());

    return true;
}

std::vector<uint8_t> rotateClockwise(BMPHeader& header, const std::vector<uint8_t>& image) {
    std::cout << "Starting clockwise rotation..." << std::endl;

    // Размеры после поворота
    int newWidth = header.height;
    int newHeight = header.width;

    std::vector<uint8_t> rotatedImage(newWidth * newHeight);
    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            rotatedImage[(x * newHeight) + (newHeight - y - 1)] = image[(y * header.width) + x];
        }
    }

    header.width = newWidth;
    header.height = newHeight;

    std::cout << "Clockwise rotation completed. New dimensions: " << header.width << "x" << header.height << std::endl;
    return rotatedImage;
}

std::vector<uint8_t> rotateCounterClockwise(BMPHeader& header, const std::vector<uint8_t>& image) {
    std::cout << "Starting counter-clockwise rotation..." << std::endl;

    // Размеры после поворота
    int newWidth = header.height;
    int newHeight = header.width;

    std::vector<uint8_t> rotatedImage(newWidth * newHeight);
    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            rotatedImage[((newWidth - x - 1) * newHeight) + y] = image[(y * header.width) + x];
        }
    }

    header.width = newWidth;
    header.height = newHeight;

    std::cout << "Counter-clockwise rotation completed. New dimensions: " << header.width << "x" << header.height << std::endl;
    return rotatedImage;
}

std::vector<uint8_t> applyGaussianFilter(const BMPHeader& header, const std::vector<uint8_t>& image) {
    // Применение фильтра Гаусса (можно реализовать, если нужно)
    return image; // Просто возвращаем изображение без изменений
}
