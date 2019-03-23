#include <iostream>

#include "drawing/drawer.h"
#include "matrix/transformation_matrix.h"
#include "matrix/point_matrix.h"
#include "drawing/3d/3d.h"

int main(){

      auto d = new Drawer();

      auto e = new TriangleMatrix();

      add_sphere(e, 0, 0, 0, 250);

      e->apply_transformation(TransformationMatrix::rotationXYZ(45, 45, 45));
      e->apply_transformation(TransformationMatrix::translation(250, 250, 0));

      d->draw_polygons(e);

      d->save("../leon.ppm", "leon");

}
