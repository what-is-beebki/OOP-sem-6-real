#pragma once

/*������������ ��������: 
	��������� ����������� ������ ����� ������������
	�� �������� ���� �������� � ����������.
	���� � �������� ����������� ��������� ������ ������������ ���������� � �������,
	������������ �������� ��������� ������������ � �� ��������������.
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
