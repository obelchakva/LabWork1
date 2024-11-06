#include "bmp_processor.h"
#include <vector>

int main() {
    BMPHeader header;
    header.width = 256;
    header.height = 256;
    header.fileSize = header.dataOffset + header.width * header.height;
    header.bitCount = 8;

    // Создание градиентного изображения (оттенки серого)
    std::vector<uint8_t> image(header.width * header.height);
    for (int y = 0; y < header.height; ++y) {
        for (int x = 0; x < header.width; ++x) {
            image[y * header.width + x] = static_cast<uint8_t>(x);
        }
    }

    saveBMP("input.bmp", header, image);
    return 0;
}
