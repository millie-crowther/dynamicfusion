#include "warp_field.h"

warp_field_t::warp_field_t(){

}

warp_field_t::~warp_field_t(){

}

std::vector<std::pair<<deform_node_t *, float>>
warp_field_t::find_neighbours(int n, point_t p){
    // output parameters from knnSearch, representing the indices of the closest points
    // and the distance to those points
    size_t neighbour_indices[n];
    float neighbour_distances[n];    

    // unpack vector into float array
    float query[3] = { p.x, p.y, p.z };
    
    // query KD-tree
    int number_found = kd_tree.knnSearch(query, n, neighbour_indices, neighbour_distances);
    
    // create map to return
    std::vector<std::pair<deform_node_t *, float>> result;
    for (int i = 0; i < number_found; i++){
        result.emplace_back(nodes[neighbour_indices[i]], neighbour_distance[i]);
    }

    return result;
}

dual_quat_t 
warp_field_t::dual_quaternion_blending(point_t p){
    // find the N closest neighbours to the given point
    auto neighbours = find_neighbours(NUM_NEIGHBOURS, p);
 
    // sum over all neighbours transforms adjusted by their weight
    dual_quat_t q(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    for (auto neighbour : neighbours){
        // NOTE: dynfu implementation has this as a product (*=)
        //       but dynamicfusion paper specifies a summation?
        q *= neighbour.first->get_transform() * neighbour.first->weight(p);
    }

    // normalize and return
    return q.normalize();    
}

frame_t 
warp_field_t::warp_canonical_frame_to_live(frame_t * canonical_frame){
    // TODO: this function is an ideal candidate for GPU computation
    //       in fact, most of the DQB function would also need to be on the GPU   
    //       KD-tree should be able to stay on CPU but the rest has to go
}
