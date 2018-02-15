#ifndef FRAME_H
#define FRAME_H

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

    // getters
    point_cloud_t get_vertices();
    normal_cloud_t get_normals();

private:
    // unique id for frame
    int frame_id;

    // point clouds storing position and normal data
    point_cloud_t vertices;
    normal_cloud_t normals;
};

#endif
