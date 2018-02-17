#include "warp_field.h"

#include <iostream>

warp_field_t::warp_field_t(){
    kd_tree = new kd_tree_t(3, *this, KDTreeSingleIndexAdaptorParams(10)); 
}

warp_field_t::~warp_field_t(){
    delete kd_tree;
}

std::vector<deform_node_t *>
warp_field_t::find_neighbours(point_t p){
    // output parameters from knnSearch, representing the indices of the closest points
    // and the distance to those points, which for now are discarded
    size_t neighbour_indices[NUM_NEIGHBOURS];
    float neighbour_distances[NUM_NEIGHBOURS];    

    // unpack vector into float array
    float query[3];
    p.unpack(query);

    // query KD-tree
    kd_tree->buildIndex();
    int number_found = kd_tree->knnSearch(query, NUM_NEIGHBOURS, neighbour_indices, neighbour_distances);
    
    // create map to return
    std::vector<deform_node_t *> result;
    for (int i = 0; i < number_found; i++){
        result.push_back(nodes[neighbour_indices[i]]);
    }

    return result;
}

dual_quat_t 
warp_field_t::dual_quaternion_blending(point_t p){
    // find the N closest neighbours to the given point
    auto neighbours = find_neighbours(p);
 
    // sum over all neighbours transforms adjusted by their weight
    dual_quat_t q;
    for (auto neighbour : neighbours){
        // NOTE: dynfu implementation has this as a product (*=)
        //       but dynamicfusion paper specifies a summation?
        q += neighbour->get_transform() * neighbour->weight(p);
    }

    // normalize and return
    q.normalise();
    return q;    
}

size_t
warp_field_t::kdtree_get_point_count() const {
    return nodes.size();
}

float 
warp_field_t::kdtree_get_pt(const size_t idx, int dim) const {
    return nodes[idx]->get_position().get_element(dim);
}

void
warp_field_t::test_kd_tree(){
    int n = 100000;

    for (int i = 0; i < n; i++){
        nodes.push_back(new deform_node_t(this, point_t(0, 0, i), dual_quat_t(), 0));
    }

    point_t p(0, 0, 500.5f);
    std::vector<deform_node_t *> nodes = find_neighbours(p);	
 
    // clean up
    for (auto node : nodes){
        delete node;
    }
    nodes.clear();
}
