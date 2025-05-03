/* Obelchak Vyacheslav st129564@student.spbu.ru
   Laboratory Work n.1 version 2
*/
#include "bmp_processor.hpp"
#include "image.hpp"

int main() {
    Rotatebmp a;
    a.rotate_clockwise();
    a.show();
    a.clear();
    a.rotate_counterclw();
    a.show();
    a.clear();
    a.rotate_clockwise();
    a.create_kernel();
    a.apply_gaussian_blur();
    a.show();
    a.clear();
    return 1;
}
