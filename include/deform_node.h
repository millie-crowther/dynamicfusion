#ifndef DEFORM_NODE_H
#define DEFORM_NODE_H

typedef pcl::PointXYZ point_t;
typedef DualQuaternion<float> dual_quat_t;

class deform_node_t {
public:
    // weight for altering radius of influence
    float weight(point_t p);

    dual_quat_t get_transform();
    
private:
    // private fields
    point_t position;
    dual_quaternion_t transform;
    float radial_basis_weight;
};

#endif
