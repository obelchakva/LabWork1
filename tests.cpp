#include "gtest/gtest.h"
#include "bmp_processor.hpp"
#include <fstream>
#include <vector>

TEST(BMPProcessorTests, ReadingBMP) {
    Rotatebmp bmp;
    bmp.read();
    ASSERT_TRUE(bmp.hasHeader());
    ASSERT_TRUE(bmp.hasBitmapInfo());
}

TEST(BMPProcessorTests, RotationCW) {
    Rotatebmp bmp;
    bmp.read();
    bmp.rotate_clockwise();
    EXPECT_EQ(bmp.getOrigHeight(), bmp.getOrigWidth());
    EXPECT_EQ(bmp.getOrigWidth(), bmp.getOrigHeight());
}

TEST(BMPProcessorTests, GaussianBlur) {
    Rotatebmp bmp;
    bmp.read();
    bmp.create_kernel();
    bmp.apply_gaussian_blur();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
