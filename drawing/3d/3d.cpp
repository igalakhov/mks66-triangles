//
// Created by Ivan Galakhov on 2019-03-15.
//

#include "3d.h"

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


    float px, py, pz, x, y, z;

    const int steps = 50;

    float theta, phi = 0;

    for(int i = 0; i <= steps; i++){

        theta = 0;

        px = r*cos(theta) + cx;
        py = r*sin(theta)*cos(phi) + cy;
        pz = r*sin(theta)*sin(phi) + cz;

        for(int j = 0; j <= steps; j++){
            x = r*cos(theta) + cx;
            y = r*sin(theta)*cos(phi) + cy;
            z = r*sin(theta)*sin(phi) + cz;

            m->add_edge(px, py, pz, x, y, z);

            px = x;
            py = y;
            pz = z;

            theta += M_PI/steps;
        }

        phi += 2 * M_PI/steps;
    }

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