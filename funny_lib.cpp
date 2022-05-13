#include"manip.h"

extern "C" {
	Manip* init_manip(double x, double y, double a) {
		Manip* Man = new Manip(0);
		Man->init(x, y, a);
		return Man;
	}

	int add_member_l(Manip* Man, int p, double x, double y, double a) {
		return Man->add_member(p, x, y, a);
	}

	int add_member_g(Manip* Man, int p, double x, double y, double a, int g) {
		return Man->add_member(p, x, y, a, g);
	}

	void print_all_members(Manip* Man) {
		Man->print_all_members();
		return;
	}

	void print_permutation(Manip* Man) {
		Man->print_permutation();
		return;
	}

	bool add_elementary(Manip* Man, int n, double a) {
		return Man->add_elementary(n, a);
	}

	bool toggle_grasp(Manip* Man, int n) {
		return Man->toggle_grasp(n);
	}

	bool set_grasp(Manip* Man, int n, int g) {
		return Man->set_grasp(n, g);
	}

	void delete_manip(Manip* Man) {
        delete Man;
        return;
    }
	
};
