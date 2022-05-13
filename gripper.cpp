#include<cstdio>
#include"gripper.h"

void Gripper::print() const {
    printf("Gripper #%i is jointed to link #%i at an angle of %.2f radian(s) with position (%.3f,%.3f)\n\tGrasps: %d\n",
        get_my_n(), get_parent_n(), get_angle(), get_x(), get_y(), grasps);
    return;
}
