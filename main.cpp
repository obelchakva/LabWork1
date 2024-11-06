#include "bmp_processor.h"
#include <iostream>

int main() {
    BMPHeader header;
    std::vector<uint8_t> image;

    // Загрузка изображения
    if (!loadBMP("input.bmp", header, image)) {
        return 1;
    }

    // Поворот на 90 градусов по часовой стрелке
    auto rotatedClockwise = rotateClockwise(header, image);
    saveBMP("rotated_clockwise.bmp", header, rotatedClockwise);

    // Поворот на 90 градусов против часовой стрелки
    auto rotatedCounterClockwise = rotateCounterClockwise(header, image);
    saveBMP("rotated_counterclockwise.bmp", header, rotatedCounterClockwise);

    // Применение фильтра Гаусса
    auto blurredImage = applyGaussianFilter(header, image);
    saveBMP("blurred_image.bmp", header, blurredImage);

    std::cout << "Processing completed!" << std::endl;
    return 0;
}
