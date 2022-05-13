#include"manip.h"

void Manip::init(double x, double y, double a) {
	delete base_link;
	this->base_link = new Link(1, 0, x, y, a);
	return;
}

// запрет на использование занятого номера
bool Manip::is_number_available(int n) {
	if (n < 0) {
        return true;
        /*  тут творится страшная вещь
         *  функция is_number_available(n) вызывается
         *      a) при попытке добавить что-то к элементу с заданным номером
         *      b) при попытке добавить перемещение
         *      c) при поиске незанятого номера функцией find_available_number()
         *  в случаях (a, b) нужно вернуть true, если элемента с таким номером не существует
         *      поэтому для отрицательных номеров возвращаем true
         *  в случае (b) проверяются только номера, большие 0
         */
    }

	if (this->base_link != nullptr) {
		return base_link->is_number_available(n);
	}
	else
		return true;//вообще, так быть не должно, хотя вроде можно удалить базовый
};

// поиск свободного номера
int Manip::find_available_number() {
	int i = 1;
	while (1) {
		if (this->is_number_available(i))
			return i;
		else i++;
	}
};

// удаление элемента с заданным номером
// удалить base_link можно, только если к нему не присоединёно ни звено, ни захват
bool Manip::del_member(int) {
	return true;
};

int Manip::add_member(int parent_num, double x, double y, double a) {
// link
	if (is_number_available(parent_num)) {
		return -1; // не существует родителя с заданным номером
	}
	Link* father = find_member(parent_num);
	if (!father->wants_kids()) {
		return -2; // попытка присоединить что-то к захвату
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
	//и вот здесь попытаться найти вектор детей папаши. И проверить, чтобы он был пустым
	int my_num = find_available_number();
	Gripper* new_grip = new Gripper(my_num, parent_num, x, y, a, g); 
	return base_link->append(new_grip);
}

// распечатать структуру манипулятора и относительные координаты каждого из элементов
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
	//недоступно, если перемещение пустое
	//если перемещение возможно (полученному в результате манипулятору хорошо)
	//то нужно стереть информацию о старом манипуляторе и записать новый
	return false;
}

void Manip::calc_abs_coordinates() {
	return;
}

bool Manip::add_elementary(int n, double a) {
	if (this->is_number_available(n))
		return false; //номер не занят, значит элемента под таким номером нет
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
