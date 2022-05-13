#include"manip.h"

void Manip::init(double x, double y, double a) {
	delete base_link;
	this->base_link = new Link(1, 0, x, y, a);
	return;
}

// ������ �� ������������� �������� ������
bool Manip::is_number_available(int n) {
	if (n < 0) {
        return true;
        /*  ��� �������� �������� ����
         *  ������� is_number_available(n) ����������
         *      a) ��� ������� �������� ���-�� � �������� � �������� �������
         *      b) ��� ������� �������� �����������
         *      c) ��� ������ ���������� ������ �������� find_available_number()
         *  � ������� (a, b) ����� ������� true, ���� �������� � ����� ������� �� ����������
         *      ������� ��� ������������� ������� ���������� true
         *  � ������ (b) ����������� ������ ������, ������� 0
         */
    }

	if (this->base_link != nullptr) {
		return base_link->is_number_available(n);
	}
	else
		return true;//������, ��� ���� �� ������, ���� ����� ����� ������� �������
};

// ����� ���������� ������
int Manip::find_available_number() {
	int i = 1;
	while (1) {
		if (this->is_number_available(i))
			return i;
		else i++;
	}
};

// �������� �������� � �������� �������
// ������� base_link �����, ������ ���� � ���� �� ����������� �� �����, �� ������
bool Manip::del_member(int) {
	return true;
};

int Manip::add_member(int parent_num, double x, double y, double a) {
// link
	if (is_number_available(parent_num)) {
		return -1; // �� ���������� �������� � �������� �������
	}
	Link* father = find_member(parent_num);
	if (!father->wants_kids()) {
		return -2; // ������� ������������ ���-�� � �������
	}
	Link* new_link = new Link(find_available_number(), parent_num, x, y, a);
	return base_link->append(new_link);
}

int Manip::add_member(int parent_num, double x, double y, double a, bool g) {
// gripper	
	if (is_number_available(parent_num)) {
		return -1;
	}
	Link* father = find_member(parent_num);
	if (!father->wants_kids()) {
		return -2;
	}
	//� ��� ����� ���������� ����� ������ ����� ������. � ���������, ����� �� ��� ������
	int my_num = find_available_number();
	Gripper* new_grip = new Gripper(my_num, parent_num, x, y, a, g); 
	return base_link->append(new_grip);
}

// ����������� ��������� ������������ � ������������� ���������� ������� �� ���������
void Manip::print_all_members() {
	if (this->base_link != nullptr)
		base_link->print_child_links();
	return;
};

bool Manip::toggle_grasp(int n) {
	return base_link->toggle_grasp(n);

}

bool Manip::set_grasp(int n, bool b) {
	return base_link->set_grasp(n, b);
}
bool Manip::are_you_good() {
	return true;
}

bool Manip::permutate() {
	//����������, ���� ����������� ������
	//���� ����������� �������� (����������� � ���������� ������������ ������)
	//�� ����� ������� ���������� � ������ ������������ � �������� �����
	return false;
}

void Manip::calc_abs_coordinates() {
	return;
}

bool Manip::add_elementary(int n, double a) {
	if (this->is_number_available(n))
		return false; //����� �� �����, ������ �������� ��� ����� ������� ���
	this->permut->add_elem(n, a);
	return true;
}

void Manip::print_permutation() {
	this->permut->print_perm();
	return;
}

Link* Manip::find_member(int n) {
	return base_link->find_member(n);
}
