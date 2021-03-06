
#ifndef MAIN_H
#define MAIN_H
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include <random>
#include "o2.h"
#include "montecarlo.h"
#include "initialization.h"
#include "robust_filesystem.h"
#include <mpi.h>
#include "rng.h"


extern unsigned int Lx, Ly, N;

namespace paths_dir{
    inline std::string TEMP_DIROUT;
    inline std::string DIROUT;
}

/*! \brief MatLab-style modulo operator
 *   \param x first number
 *   \param y second number
 *   \return modulo of x and y.
 *   Example,
 *     mod(7,2)  = 1 but  7%2=1
 *     mod(-0.5,10)  = 9.5 instead of -0.5%10=-0.5 as given by x%y.
 */
template<typename T>
inline auto mod(const T x, const T y) {
    return (x % y + y) % y;
}

int power(int x, int y);
void mainloop(struct O2* Site, struct MC_parameters &MCp, struct H_parameters &Hp, double &my_beta, int &my_ind, struct PT_parameters PTp, struct PTroot_parameters PTroot, std::string directory_parameters, int NSTART);
void parallel_temp(double &my_E , double &my_beta,  int &my_ind, struct PT_parameters &PTp, struct PTroot_parameters &PTroot);
void myhelp(int argd, char** argu);


#endif
