#ifndef DYNAMIC_FUSION_H
#define DYNAMIC_FUSION_H

#include "warp_field.h"

class dynamic_fusion_t {
public:
    /*
      constructors and destructors
    */
    dynamic_fusion_t();
    ~dynamic_fusion_t();

    // main public method
    void execute();

private:
    warp_field_t warp_field;
};

#endif
