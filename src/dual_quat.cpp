#include "dual_quat.h"

#include <cmath>

dual_quat_t::dual_quat_t(){

}

dual_quat_t::dual_quat_t(quat_t real, quat_t dual){
    this->real = real;
    this->dual = dual;
}

dual_quat_t
dual_quat_t::operator*(float scale){
    return dual_quat_t(real, dual * scale);
}

void
dual_quat_t::operator+=(const dual_quat_t & other){
    real += other.real;
    dual += other.dual;
}

void
dual_quat_t::normalise(){
    float dot = 
        real.R_component_1() * real.R_component_1() +
        real.R_component_2() * real.R_component_2() +
        real.R_component_3() * real.R_component_3() +
        real.R_component_4() * real.R_component_4();
    real /= sqrt(dot);
}
