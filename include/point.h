#ifndef POINT_H
#define POINT_H

class point_t {
public:
    // unpack values into a float array
    void unpack(float * array);

private:
    float x;
    float y;
    float z;
};

#endif
