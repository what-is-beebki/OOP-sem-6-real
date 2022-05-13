#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "elementary.h"

/*Перемещение:
	Набор исполняемых последовательно элементарных движений.
	Необходимо вычислять конечное положение манипулятора после перемещения,
	если все его элементарные движения выполнимы.
*/
class Permut {

private:
    std::vector<Elem> movement;

public:
	Permut(int n){}
	void print_perm();

	void add_elem(int, double);
    
};