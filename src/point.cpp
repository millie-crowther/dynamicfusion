#include "point.h"

point_t::point_t() : point_t(0, 0, 0){

}

point_t::point_t(float x, float y, float z){
    elems[0] = x;
    elems[1] = y;
    elems[2] = z;
}

void
point_t::unpack(float * array){
    if (array != nullptr){
        for (int i = 0; i < 3; i++){
            array[i] = elems[i];
        }
    }
}

float 
point_t::get_element(int index){
    if (index < 0 || index > 3){
        // AAAAH
        return 0;
    } else {
        return elems[index];
    }
}

std::string
point_t::to_string(){
    return "point(" + std::to_string(elems[0]) + ", " + std::to_string(elems[1]) + ", " + std::to_string(elems[2])  + ")";
}
