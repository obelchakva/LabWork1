/* Обельчак Вячеслав st129564@student.spbu.ru
   Лабораторная работа №1 версия 2
*/
#include "bmp_processor.hpp"
#include "image.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono;

int main() {
    auto start_time = high_resolution_clock::now();

    Rotatebmp a;
    auto t_read_start = high_resolution_clock::now();
    a.read();
    auto t_read_end = high_resolution_clock::now();

    auto t_rotate_cw_start = high_resolution_clock::now();
    a.rotate_clockwise();
    auto t_rotate_cw_end = high_resolution_clock::now();

    auto t_write_cw_start = high_resolution_clock::now();
    a.show();
    auto t_write_cw_end = high_resolution_clock::now();

    a.clear();

    auto t_rotate_ccw_start = high_resolution_clock::now();
    a.rotate_counterclw();
    auto t_rotate_ccw_end = high_resolution_clock::now();

    auto t_write_ccw_start = high_resolution_clock::now();
    a.show();
    auto t_write_ccw_end = high_resolution_clock::now();

    a.clear();

    auto t_gauss_start = high_resolution_clock::now();
    a.create_kernel();
    a.apply_gaussian_blur();
    auto t_gauss_end = high_resolution_clock::now();

    auto t_write_gauss_start = high_resolution_clock::now();
    a.show();
    auto t_write_gauss_end = high_resolution_clock::now();

    a.clear();

    auto end_time = high_resolution_clock::now();

    std::cout << "Reading time: " << duration_cast<milliseconds>(t_read_end - t_read_start).count() << " ms\n";
    std::cout << "Clockwise rotation time: " << duration_cast<milliseconds>(t_rotate_cw_end - t_rotate_cw_start).count() << " ms\n";
    std::cout << "Writing clockwise rotation time: " << duration_cast<milliseconds>(t_write_cw_end - t_write_cw_start).count() << " ms\n";
    std::cout << "Counterclockwise rotation time: " << duration_cast<milliseconds>(t_rotate_ccw_end - t_rotate_ccw_start).count() << " ms\n";
    std::cout << "Writing counterclockwise rotation time: " << duration_cast<milliseconds>(t_write_ccw_end - t_write_ccw_start).count() << " ms\n";
    std::cout << "Gauss filter time: " << duration_cast<milliseconds>(t_gauss_end - t_gauss_start).count() << " ms\n";
    std::cout << "Writing Gauss filter time: " << duration_cast<milliseconds>(t_write_gauss_end - t_write_gauss_start).count() << " ms\n";
    std::cout << "Total execution time: " << duration_cast<milliseconds>(end_time - start_time).count() << " ms\n";

    return 0;
}
