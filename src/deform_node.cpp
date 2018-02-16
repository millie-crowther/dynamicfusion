#include "deform_node.h"

#include <algorithm>

deform_node_t::deform_node_t(warp_field_t * warp_field){
    this->warp_field = warp_field;
}

float
deform_node_t::regularisation(float phi){
    // TODO: this knn search will return this node as well.
    //       the terms cancel so it will end up being zero, but may want to
    //       remove for efficiency or check an extra one to compensate.
    auto neighbours = warp_field->find_neighbours(num_neighbours, position);
    
    float result = 0.0f;
    for (auto neighbour : neighbours){
        float alpha = max(radial_weight, neighbour->radial_weight);
    }

    return result;
}
