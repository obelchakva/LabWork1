#include "gtest/gtest.h"
#include "bmp_processor.hpp"
#include "image.hpp"
#include <fstream>
#include <vector>

TEST(BMPProcessorTests, ReadingBMP) {
    Rotatebmp bmp;
    bmp.read();

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
