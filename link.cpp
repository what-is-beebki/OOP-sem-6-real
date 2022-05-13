#include<cstdio>
#include"link.h"
#include"gripper.h"

bool Link::turn_to(double to_angle) {
    if (parent_num == 0) {
        angle = to_angle;
        angle = fmod(angle + M_PI, 2 * M_PI) - M_PI;

        return true;
    }

    if (to_angle > -M_PI && to_angle < M_PI) {
        angle = to_angle;
        return true;
    }
    else {
        return false;
    }
}
bool Link::turn_at(double at_angle) {
    double res = angle + at_angle;
    return turn_to(res);
}


int Link::append(Link* new_link) {

    if (this->next != nullptr) {
        return this->next->append(new_link);
    }
    else {
        this->next = new_link;
        return 0;
    }
};



bool Link::is_number_available(int n) {
    if (this->my_num == n) {
        return false;
    }
    else if (this->next != nullptr) {
        return this->next->is_number_available(n);
    }
    else {
        return true;
    }
};


void Link::print() const {
    printf("Link    #%i is jointed to link #%i at an angle of %.2f radian(s) with position (%.3f,%.3f)\n",
        my_num, parent_num, angle, x, y);
    return;
}

void Link::print_child_links() const {
    this->print();
    if (this->next != nullptr)
        this->next->print_child_links();
    return;
}

Link* Link::find_member(int n) {
    if (this->my_num == n)
        return this;
    else if (this->next != nullptr)
        return this->next->find_member(n);
    else return nullptr;
}

bool Link::set_grasp(int n, bool grr) {
    if ((this->next == nullptr) || (this->my_num == n))
        return false;
    else
        return this->next->set_grasp(n, grr);
}

bool Link::toggle_grasp(int n) {
    if ((this->next == nullptr) || (this->my_num == n))
        return false;
    else
        return this->next->toggle_grasp(n);
}
