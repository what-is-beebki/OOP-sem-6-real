#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

/*
ѕодвижное звено: объект содержит
    номер текущего звена,
    номер предыдущего звена в кинематической цепи,
    положение звена относительно предыдущего
    (2 компонента вектора положени€ начала координат звена
    и угол поворота звена).
*/
class Link {

private:
    int my_num;
    int parent_num;
    double x;
    double y;
    double angle;
    Link* next;

public:
    Link(int a, int b, double x, double y, double angle) {
        my_num = a;
        parent_num = b;
        this->x = x;
        this->y = y;
        this->angle = fmod(angle + M_PI, 2 * M_PI) - M_PI;
        next = nullptr;
    }

    virtual ~Link() {
        if (this->next != nullptr) // кстати зачем
            delete this->next;
        return;
    }

    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }
    double get_angle() const {
        return angle;
    }
    int get_my_n() const {
        return my_num;
    }
    int get_parent_n() const {
        return parent_num;
    }

    virtual Link* get_next() const {
        return this->next;
    }

    void set_parent_n(int n) {
        this->parent_num = n;
    }

    /*Ќеобходимо уметь задать поворот звена как до заданного угла,
        так и на заданный угол.*/

    bool turn_to(double);

    bool turn_at(double);

    int append(Link*);

   // bool append(Gripper*);

    bool is_number_available(int);

    virtual void print() const;

    void print_child_links() const;

    virtual bool wants_kids() const {
        return true;
    }

    Link* find_member(int);

    virtual bool set_grasp(int, bool);

    virtual bool toggle_grasp(int);
};       
