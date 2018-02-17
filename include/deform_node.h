#ifndef DEFORM_NODE_H
#define DEFORM_NODE_H

#include "point.h"
#include "dual_quat.h"

class warp_field_t;

/*
 *  a class representing one of the deformation nodes that make up the 
 *  warp field.
 */
class deform_node_t {
public:
    // constructor
    deform_node_t(warp_field_t * wf, point_t p, dual_quat_t dq, float w);

    // energy function used for enforcing warp field regularisation
    float regularisation(float phi);
    
    // weight for altering radius of influence
    float weight(point_t p);

    // getters
    dual_quat_t get_transform();
    point_t get_position();
    
private:
    // pointer to warp field to allow node to find neighbours
    warp_field_t * warp_field;

    // properties of deformation node as in dynamic fusion paper
    point_t position;
    dual_quat_t transform;
    float radial_weight;
};

#endif
