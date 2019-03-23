#include <iostream>

#include "drawing/drawer.h"

int main(){

      auto u = new UnitMatrix(2);

      u->add_unit({100, 0, 23, 14, 23, 1});

      u->print();

      delete u;

//    auto d = new Drawer();
//
//    auto m = new EdgeMatrix();
//    auto t = TransformationMatrix::identity();
//
//    auto p = new MDLParser("script.mdl");
//
//    p->run_file(m, t, d);
}
