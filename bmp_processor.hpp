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

    void show();               
    void clear();              
    void read();               

    bool hasHeader() const { return header != nullptr; } 
    bool hasBitmapInfo() const { return bitmap != nullptr; } 
    int32_t getOrigWidth() const { return origWidth; }  
    int32_t getOrigHeight() const { return origHeight; }  
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
