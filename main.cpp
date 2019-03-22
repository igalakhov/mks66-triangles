#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "drawing/display.h"
#include "drawing/drawer.h"
#include "matrix/edge_matrix.h"
#include "matrix/transformation_matrix.h"
#include "parsing/obj_parser.h"
#include "parsing/mdl_parser.h"
#include "drawing/parametric/parametric.h"
#include "matrix/unit_matrix.h"

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
