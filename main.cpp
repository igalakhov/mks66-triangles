#include <iostream>

#include "drawing/drawer.h"
#include "parsing/mdl_parser.h"
#include "matrix/transformation_matrix.h"
#include "matrix/point_matrix.h"
#include "drawing/3d/3d.h"

int main(){

      auto m = new MDLParser("dwscript.mdl");

      m->run_file();

}
