#ifndef WARP_FIELD_H
#define WARP_FIELD_H

#include <vector>
#include "dual_quat.h"
#include "deform_node.h"
#include "frame.h"

// includes for nanoflann, as well as a typedef for brevity
#include "nanoflann.hpp"
using namespace nanoflann;

class warp_field_t;
typedef KDTreeSingleIndexAdaptor<
    L2_Simple_Adaptor<float, warp_field_t>, 
    warp_field_t, 
    3
> kd_tree_t;

class warp_field_t {
public:
    // constructor
    warp_field_t();

    // destructor
    ~warp_field_t();
    
    /*
     *  interface required for nanoflann implementation of kd-tree
     */
    // size of the warp field
    size_t kdtree_get_point_count() const;
    
    // access individual elements of points in cloud
    float kdtree_get_pt(const size_t idx, int dim) const;

    // unused, optional interface method to determine bounding box
    template <class BBOX>
    bool kdtree_get_bbox(BBOX& bb) const {
        return false;
    }

    // test function
    void test_kd_tree();
    
    // retrieve the N closest neighbouring nodes from a given point
    std::vector<deform_node_t *> find_neighbours(point_t p);

private:
    // constants
    const static int NUM_NEIGHBOURS = 8;

    // kd-tree for efficient closest neighbour search
    kd_tree_t * kd_tree;

    // vector of deformation nodes in the warp field defining the state of the warp field
    std::vector<deform_node_t *> nodes;

    /*
     *  private methods 
     */

    // calculate dual-quaternion blending for a given point
    dual_quat_t dual_quaternion_blending(point_t p);    
};

#endif
