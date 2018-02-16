#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H

#include "point.h"
#include <vector>

class point_cloud_t {
public:
    /*
     *  Interface required by nanoflann kd-tree implementation
     */
    
    // get the number of points
    size_t kdtree_get_point_count() const;

    // retrieves an element of a point
    float kdtree_get_pt(const size_t idx, int dim) const;

    // optional, unused bounding-box computation
    template <class BBOX>
    bool kdtree_get_bbox(BBOX& bb){
        return false;
    }

private:
    std::vector<point_t> points;
};

#endif
