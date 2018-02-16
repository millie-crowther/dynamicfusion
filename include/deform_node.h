#ifndef DEFORM_NODE_H
#define DEFORM_NODE_H

#include "point.h"
#include "warp_field.h"

/*
 *  a class representing one of the deformation nodes that make up the 
 *  warp field.
 */
class deform_node_t {
public:
    // constructor
    deform_node_t(warp_field_t * warp_field);

    // energy function used for enforcing warp field regularisation
    float regularisation(float phi);
    
    // weight for altering radius of influence
    float weight(point_t p);
    
private:
    // constants
    static int NUM_NEIGHBOURS = 8;

    // pointer to warp field to allow node to find neighbours
    warp_field_t * warp_field;

    // properties of deformation node as in dynamic fusion paper
    point_t position;
    dual_quaternion_t transform;
    float radial_weight;
};

#endif
