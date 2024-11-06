#include "bmp_processor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <array>

// Функция загрузки изображения BMP
bool loadBMP(const std::string& filename, BMPHeader& header, std::vector<uint8_t>& image) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // Чтение заголовка
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    if (header.fileType != 0x4D42) {  // Проверка сигнатуры "BM"
        std::cerr << "Error: Not a BMP file" << std::endl;
        return false;
    }

    image.resize(header.width * header.height);
    file.seekg(header.dataOffset, std::ios::beg);
    file.read(reinterpret_cast<char*>(image.data()), image.size());

    return true;
}

// Функция сохранения изображения BMP
bool saveBMP(const std::string& filename, const BMPHeader& header, const std::vector<uint8_t>& image) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return false;
    }

    file.write(reinterpret_cast<const char*>(&header), sizeof(header));
    file.write(reinterpret_cast<const char*>(image.data()), image.size());

    return true;
}

// Функция поворота изображения на 90 градусов по часовой стрелке
std::vector<uint8_t> rotateClockwise(BMPHeader& header, const std::vector<uint8_t>& image) {
    int newWidth = header.height;
    int newHeight = header.width;
    std::vector<uint8_t> rotatedImage(newWidth * newHeight);

    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            rotatedImage[x * newHeight + (newHeight - 1 - y)] = image[y * header.width + x];
        }
    }

    header.width = newWidth;
    header.height = newHeight;

    return rotatedImage;
}

// Функция поворота изображения на 90 градусов против часовой стрелки
std::vector<uint8_t> rotateCounterClockwise(BMPHeader& header, const std::vector<uint8_t>& image) {
    int newWidth = header.height;
    int newHeight = header.width;
    std::vector<uint8_t> rotatedImage(newWidth * newHeight);

    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            rotatedImage[(newWidth - 1 - x) * newHeight + y] = image[y * header.width + x];
        }
    }

    header.width = newWidth;
    header.height = newHeight;

    return rotatedImage;
}

// Функция применения фильтра Гаусса
std::vector<uint8_t> applyGaussianFilter(const BMPHeader& header, const std::vector<uint8_t>& image) {
    std::vector<uint8_t> blurredImage(image.size());
    const int kernelSize = 3;
    const float kernel[kernelSize][kernelSize] = {
        {1/16.0f, 2/16.0f, 1/16.0f},
        {2/16.0f, 4/16.0f, 2/16.0f},
        {1/16.0f, 2/16.0f, 1/16.0f}
    };

    for (int y = 1; y < header.height - 1; ++y) {
        for (int x = 1; x < header.width - 1; ++x) {
            float sum = 0.0f;
            for (int ky = -1; ky <= 1; ++ky) {
                for (int kx = -1; kx <= 1; ++kx) {
                    sum += image[(y + ky) * header.width + (x + kx)] * kernel[ky + 1][kx + 1];
                }
            }
            blurredImage[y * header.width + x] = static_cast<uint8_t>(sum);
        }
    }

    return blurredImage;
}
