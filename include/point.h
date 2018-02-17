#ifndef POINT_H
#define POINT_H

#include <string>

class point_t {
public:
    /*
     * constructors
     */
    point_t();
    point_t(float x, float y, float z);

    // unpack values into a float array
    void unpack(float * array);

    // get element of point by index. used for nanoflann kd tree
    float get_element(int index);

    // pretty print
    std::string to_string();

private:
    float elems[3];
};

#endif
