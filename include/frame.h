#ifndef FRAME_H
#define FRAME_H

#include "point.h"

#include <vector>

/*
    a small container class representing a frame.
    contains a unique id, and the vertex positions and normals of the frame
*/
class frame_t {
public:
    // constructor
    frame_t(int frame_id);

    // destructor
    ~frame_t();

private:
    // unique id for frame
    int frame_id;

    // point clouds storing position and normal data
    std::vector<point_t> vertices;
    std::vector<point_t> normals;
};

#endif
