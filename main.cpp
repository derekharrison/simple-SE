/*
 * main.cpp
 *
 *  Created on: Dec 19, 2020
 *      Author: d-w-h
 *
 *      Solution of a simple complex differential equation:
 *      ih*d(psi)/dt = psi
 */

#include <math.h>
#include <stdio.h>
#include "complex.hpp"

int main(int argc, char* argv[]) {

    int Nt;
    double to, tf, h, a, b;
    Complex psi_p0(0,0);
    Complex psi_p(0,0);

    /* Parameters */
    Nt = 100000;       //Number of timesteps
    to = 0.0;          //Initial time
    tf = 1.0;          //Final time
    h = 1.0;           //Constant
    a = 1.0;           //Real part psi0
    b = 1.0;           //Imaginary part psi0

    /* Initialize wave function */
    Complex psi0(a,b);

    /* Start calculations */
    double d_t = (tf - to)/Nt;
    double t = 0.0;
    double B = 1 + h*h/(d_t*d_t);
    Complex dummy(h*h/d_t, -h);

    /* Initialize psi_p0*/
    psi_p0.a = psi0.a;
    psi_p0.b = psi0.b;

    /* Start main iterations */
    while(t < tf) {
        /* Calculate psi_p */
        psi_p = psi_p0 * dummy;
        psi_p.a = psi_p.a/(d_t * B);
        psi_p.b = psi_p.b/(d_t * B);

        /* Update psi_p0 */
        psi_p0.a = psi_p.a;
        psi_p0.b = psi_p.b;

        t = t + d_t;
    }

    /* Print analytical results */
    Complex psi_fact(cos(tf/h), -sin(tf/h));
    Complex psi_ana = psi0 * psi_fact;
    printf("psi analytical:\n");
    printf("a: %f, b: %f\n", psi_ana.a, psi_ana.b);

    /* Print numerical results */
    printf("psi numerical:\n");
    printf("a: %f, b: %f\n", psi_p.a, psi_p.b);

    return 0;
}
