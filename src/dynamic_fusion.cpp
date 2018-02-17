#include "dynamic_fusion.h"

#include <iostream>

dynamic_fusion_t::dynamic_fusion_t(){

}

dynamic_fusion_t::~dynamic_fusion_t(){

}

void
dynamic_fusion_t::execute(){
    warp_field.test_kd_tree();    
}
