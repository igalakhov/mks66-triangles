//
// Created by Ivan Galakhov on 2019-03-15.
//

#include "3d.h"

void add_sphere(TriangleMatrix * m, float cx, float cy, float cz, float r){
    auto sphere_points = generate_sphere_points(cx, cy, cz, r);
    int num_points = sphere_points->size();

    int i, p1, p2, p3, p4;

    float_mat * s = sphere_points->start();

    for(int lat = 0; lat < SPHERE_NUM_STEPS + 1; lat++){
        for(int lon = 0; lon < SPHERE_NUM_STEPS; lon++){
            i = lat * SPHERE_NUM_STEPS + lon + 1;

            p1 = (i % num_points)*4;
            p2 = ((i+1) % num_points)*4;
            p3 = ((SPHERE_NUM_STEPS + i + 1) % num_points)*4;
            p4 = ((SPHERE_NUM_STEPS + i + 2) % num_points)*4;

            m->add_triangle(
                    s[p1], s[p1 + 1], s[p1 + 2],
                    s[p2], s[p2 + 1], s[p2 + 2],
                    s[p3], s[p3 + 1], s[p3 + 2]);

            m->add_triangle(
                    s[p2], s[p2 + 1], s[p2 + 2],
                    s[p4], s[p4 + 1], s[p4 + 2],
                    s[p3], s[p3 + 1], s[p3 + 2]);

        }
    }

    delete sphere_points; // don't need this anymore
}

PointMatrix * generate_sphere_points(float cx, float cy, float cz, float r){
    auto ret = new PointMatrix();

    double theta, phi;

    float x, y, z;

    for(int i = 0; i < SPHERE_NUM_STEPS; i++){
        phi = (((float) i)/((float) SPHERE_NUM_STEPS)) * 2 * M_PI;
        for(int j = 0; j <= SPHERE_NUM_STEPS; j++){
            theta = (((float) j)/((float) SPHERE_NUM_STEPS)) * M_PI;

            x = (float) (r*cos(theta) + cx);
            y = (float) (r*sin(theta)*cos(phi) + cy);
            z = (float) (r*sin(theta)*sin(phi) + cz);

            ret->add_point(x, y, z);

        }
    }

//    double theta, phi = 0;
//
//    float x, y, z;
//
//    for(int i = 0; i < SPHERE_NUM_STEPS; i++){
//        theta = 0;
//        for(int j = 0; j <= SPHERE_NUM_STEPS; j++){
//
//            x = (float) (r*cos(theta) + cx);
//            y = (float) (r*sin(theta)*cos(phi) + cy);
//            z = (float) (r*sin(theta)*sin(phi) + cz);
//
//            ret->add_point(x, y, z);
//
//            theta += M_PI/SPHERE_NUM_STEPS;
//        }
//
//        phi += 2 * M_PI/SPHERE_NUM_STEPS;
//    }

    return ret;
}

void add_box(EdgeMatrix * m, float x, float y, float z, float w, float h, float d){
    m->add_edge(x, y, z, x + w, y, z);
    m->add_edge(x + w, y, z, x + w, y + h, z);
    m->add_edge(x + w, y + h, z, x, y + h, z);
    m->add_edge(x, y + h, z, x, y, z);

    m->add_edge(x, y, z + d, x + w, y, z + d);
    m->add_edge(x + w, y, z + d, x + w, y + h, z + d);
    m->add_edge(x + w, y + h, z + d, x, y + h, z + d);
    m->add_edge(x, y + h, z + d, x, y, z + d);

    m->add_edge(x, y, z, x, y, z + d);
    m->add_edge(x + w, y, z, x + w, y, z + d);
    m->add_edge(x, y + h, z, x, y + h, z + d);
    m->add_edge(x + w, y + h, z, x + w, y + h, z + d);
}

void add_sphere(EdgeMatrix * m, float cx, float cy, float cz, float r){



}

void add_torus(EdgeMatrix * m, float tx, float ty, float tz, float r, float R){
    float px, py, pz, x, y, z;

    const int steps = 50;

    float theta, phi = 0;

    for(int i = 0; i <= steps; i++){

        theta = 0;

        px = cos(phi) * (R + r*cos(theta)) + tx;
        py = r*sin(theta) + ty;
        pz = -sin(phi)*(r*cos(theta) + R) + tz;

        for(int j = 0; j <= steps; j++){
            x = cos(phi) * (R + r*cos(theta)) + tx;
            y = r*sin(theta) + ty;
            z = -sin(phi)*(r*cos(theta) + R) + tz;

            m->add_edge(px, py, pz, x, y, z);

            px = x;
            py = y;
            pz = z;

            theta += 2 * M_PI/steps;
        }

        phi += 2 * M_PI/steps;
    }
}