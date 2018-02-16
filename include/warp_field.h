#ifndef WARP_FIELD_H
#define WARP_FIELD_H

#include <vector>
#include "point_cloud.h"

// includes for nanoflann, as well as a typedef for brevity
#include "nanoflann/nanoflann.hpp"
using namespace nanoflann;
typedef KDTreeSingleIndexAdaptor<
    L2_Simple_Adaptor<float, point_cloud_t>, 
    point_cloud_t, 
    3
> kd_tree_t;

class warp_field_t {
public:
    // constructor
    warp_field_t();

    // destructor
    ~warp_field_t();

    // application of warp function to field
    frame_t warp_canonical_frame_to_live(frame_t * canonical_frame);

private:
    // constants
    static int NUM_NEIGHBOURS = 8;

    // kd-tree for efficient closest neighbour search
    kd_tree_t kd_tree;

    /*
      private methods 
    */

    // vector of deformation nodes in the warp field defining the state of the warp field
    std::vector<deform_node_t *> nodes;

    // retrieve the N closest neighbouring nodes from a given point
    std::vector<std::pair<deform_node_t *, float>> find_neighbours(int n, point_t p);

    // calculate dual-quaternion blending for a given point
    dual_quat_t dual_quaternion_blending(point_t p);    
};

#endif
