/* Obelchak Vyacheslav st129564@student.spbu.ru
   Lab work #1
*/
#include "bmp_processor.h"
#include <iostream>

int main() {
    BMPHeader header;
    std::vector<uint8_t> image;

    // Загрузка изображения
    if (!loadBMP("input.bmp", header, image)) {
        std::cerr << "Failed to load BMP image or header is incorrect." << std::endl;
        return 1;
    }

    if (image.size() == 0 || header.width <= 0 || header.height <= 0) {
        std::cerr << "Invalid image data or header dimensions." << std::endl;
        return 1;
    }

    // Поворот на 90 градусов по часовой стрелке
    std::cout << "Starting clockwise rotation..." << std::endl;
    std::cout << "Image size: " << image.size() << ", Width: " << header.width << ", Height: " << header.height << std::endl;
    auto rotatedClockwise = rotateClockwise(header, image);
    std::cout << "Rotation completed." << std::endl;
    saveBMP("rotated_clockwise.bmp", header, rotatedClockwise);

    // Поворот на 90 градусов против часовой стрелки
    std::cout << "Rotating conter clockwise..." << std::endl;
    auto rotatedCounterClockwise = rotateCounterClockwise(header, image);
    std::cout << "Saving rotated conter clockwise image..." << std::endl;
    saveBMP("rotated_counterclockwise.bmp", header, rotatedCounterClockwise);

    // Применение фильтра Гаусса
    std::cout << "Applying Gaussian filter..." << std::endl;
    auto blurredImage = applyGaussianFilter(header, image);
    std::cout << "Saving applied Gaussian filter..." << std::endl;
    saveBMP("blurred_image.bmp", header, blurredImage);

    std::cout << "Processing completed!" << std::endl;
    return 0;
}
