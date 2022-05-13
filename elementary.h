#pragma once

/*Элементарное движение: 
	описывает перемещение одного звена манипулятора
	от текущего угла поворота к указанному.
	Если в процессе перемещения некоторые звенья манипулятора столкнутся с другими,
	элементарное движение считается недопустимым и не осуществляется.
*/

class Elem {
private:
	int mem_num;
	double to_angle;
	//double at_angle;
public:
	Elem(int n, double a) :mem_num(n), to_angle(a) {}

	void print_ys() {
		printf("\t%d: %f\n", this->mem_num, this->to_angle);
		return;
	}
};
