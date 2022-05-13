#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include"link.h"

/*«ахват: объект содержит
	номер текущего звена
	номер предыдущего звена (либо 0)
	положение захвата относительно этого звена
	текущее состо€ние (открыт/закрыт)

Ќеобходимо уметь регистрировать открытие/закрытие захвата.
*/

class Gripper : public Link {

private:
    bool grasps;

public:
    Gripper(int a, int b, double x, double y, double angle, bool grasps)
        :Link(a, b, x, y, angle), grasps(grasps) {}

    bool is_grasping() const {
        return grasps;
    }

    bool set_grasp(int n, bool grr) {
        if (this->get_my_n() == n)
            this->grasps = grr;
        else if (this->get_next() != nullptr)
            return this->get_next()->set_grasp(n, grr);
        return true;
    }

    bool toggle_grasp(int n) {
        if (this->get_my_n() == n)
            this->set_grasp(n, !(this->grasps));
        else if (this->get_next() != nullptr)
            return this->get_next()->toggle_grasp(n);
        return true;
    }

    void print() const;

    bool wants_kids() const {
        return false;
    }
};
