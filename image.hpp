/* Obelchak Vyacheslav st129564@student.spbu.ru
   Laboratory Work n.1 version 2
*/
#ifndef IMAGE
#define IMAGE
#include <cstdint>

#pragma pack(push, 1)
struct Fileheader
{
    uint16_t Ftype;
    uint32_t Fsize;
    uint16_t Rez1; 
    uint16_t Rez2; 
    uint32_t Px_begin;
};

struct Bitmapinfo
{
    uint32_t biSize; 
    int32_t biWidth; 
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
    uint32_t RMask; 
    uint32_t GMask;
    uint32_t BMask;
    uint32_t AMask;
    uint32_t CSType;
    struct
    {
        uint32_t RGamma;
        uint32_t GGamma;
        uint32_t BGamma;
        uint32_t AGamma;
    } Endpoints[3];

    uint32_t bIntent;
    uint32_t bProfileData;
    uint32_t bProfileSize;
    uint32_t bReserved;
};
#pragma pack(pop)

#endif

