#ifndef DUAL_QUAT_H
#define DUAL_QUAT_H

#include <boost/math/quaternion.hpp>

typedef boost::math::quaternion<float> quat_t;

class dual_quat_t {
public:
    /*
     *  constructors
     */
    dual_quat_t();
    dual_quat_t(quat_t real, quat_t dual);

    /*
     *  overloaded operators
     */ 
    dual_quat_t operator*(float scale);
    void operator+=(const dual_quat_t & other);

    /*
     *  public methods
     */    
    void normalise();

private:
    // Rotational part 
    quat_t real;
    
    // translation part
    quat_t dual;
};
#endif
