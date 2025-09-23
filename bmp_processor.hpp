/* Obelchak Vyacheslav st129564@student.spbu.ru
   Laboratory Work n.1 version 2
*/
#ifndef BMP_PROCESSOR
#define BMP_PROCESSOR
#include "image.hpp"
#include <cstdint>

class Rotatebmp {
public:
    Rotatebmp(int kernelSize, double sigmaa);
    Rotatebmp();
    void rotate_clockwise();
    void rotate_counterclw();
    void create_kernel();
    void apply_gaussian_blur();

    void show();       // Оставляем публичным
    void clear();      // Оставляем публичным
    void read();       // Делаем публичным

    ~Rotatebmp();
private:
    Fileheader* header;
    Bitmapinfo* bitmap;
    int origrowSize;
    int32_t origWidth;
    int32_t origHeight;
    uint32_t origbiSizeImage;
    uint32_t origFsize;
    char* origbiTable;

    int currowSize;
    char* curbiTable;

    double** kernel;
    int kSize;
    double sigma;
};

#endif
