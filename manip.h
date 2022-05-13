#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include "link.h"
#include "gripper.h"
#include "permutation.h"

/*�����������: ������������� ������.
	�������� �������� �����������, ��������� �� ��������� �������������� ��������������

	������ ��������� ������� ���� �������� ��� ������������� �����
	� �������� / �������� ��������.
	����� ������ ����� ������������ ��������� ������ ���������� �����
	� �������� ����������� ������������ ��������(��������� ������������ �������).
*/

class Manip {
private:
	Link* base_link;
	Permut* permut;
public:
	Manip(int n) {
	// ��� 'int n' ������ �� ����� ��������
		this->base_link = nullptr;
		this->permut = new Permut(0);
	}

	~Manip() {
		delete permut;
		delete base_link;
	}

	void init(double, double, double);

	bool is_number_available(int);
	int find_available_number();

	int add_member(int, double, double, double);       // link
	int add_member(int, double, double, double, bool); // gripper

	bool toggle_grasp(int);
	bool set_grasp(int, bool);

	bool del_member(int);
	void print_all_members();

	bool are_you_good();
	//���������, ��� �� ��� �������, �������������� ����� �����

	bool permutate();

	void calc_abs_coordinates();
	//�������� � ������ ���� ����� �, � �� �������

	bool add_elementary(int, double);

	void print_permutation();

	Link* find_member(int);
};
