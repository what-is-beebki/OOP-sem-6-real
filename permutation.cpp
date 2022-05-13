#include<cstdio>
#include"permutation.h"

void Permut::print_perm(){
    if ((this->movement).empty()) {
        printf("Empty permutation\n\n");
        return;
    }
    std::vector<Elem>::iterator i = this->movement.begin();
    printf("Permutation:\n");
    while (i != this->movement.end()) {
        i->print_ys();
        i++;
    }
    return;
}

void Permut::add_elem(int n, double a) {
    Elem *addition = new Elem(n, a);
    this->movement.push_back(*addition);
    return;

}