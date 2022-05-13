#include<cassert>
#include<cstdio>
#include"link.h"
#include"gripper.h"
#include"manip.h"

void test_Grip() {

    Manip Arm(0);
    Arm.init(1, 2, 3);
    Arm.add_member(1, 4, 5, M_PI_4);
    Arm.add_member(1, 6, 7, -M_PI_4);
    Arm.add_member(3, 2, 1, -M_PI_4, 1);
    Arm.print_all_members();

    Arm.print_permutation();

    Arm.add_elementary(4, 0);
    Arm.add_elementary(2, -0.7);
    Arm.add_elementary(5, 7.9);
    Arm.add_elementary(1, 3.12);
    Arm.add_elementary(3, 1);

    Arm.print_permutation();

    Arm.toggle_grasp(3);
    Arm.toggle_grasp(4);
    
    Arm.print_all_members();

    Arm.set_grasp(5, 1);
    Arm.set_grasp(4, 1);

    Arm.print_all_members();

    

    return;
}

int main() {
    test_Grip();
    return 0;
}
