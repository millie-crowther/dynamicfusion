#include "deform_node.h"

#include "warp_field.h"

#include <algorithm>

deform_node_t::deform_node_t(warp_field_t * wf, point_t p, dual_quat_t dq, float w){
    warp_field = wf;
    position = p;
    transform = dq;
    radial_weight = w;
}

float
deform_node_t::regularisation(float phi){
    // TODO: this knn search will return this node as well.
    //       the terms cancel so it will end up being zero, but may want to
    //       remove for efficiency or check an extra one to compensate.
    auto neighbours = warp_field->find_neighbours(position);
    
    float result = 0.0f;
    for (deform_node_t * neighbour : neighbours){
        float alpha = std::max(radial_weight, neighbour->radial_weight);
    }

    return result;
}

float
deform_node_t::weight(point_t p){
    //TODO
    return 0;
}

dual_quat_t 
deform_node_t::get_transform(){
    return transform;
}

point_t 
deform_node_t::get_position(){
    return position;
}


