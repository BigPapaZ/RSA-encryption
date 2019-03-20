#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H
#include <cmath>
#include <iostream>
using namespace std;

template <class T>
T modPower(const T& base, const T& exponent, const T& modulus);

template <class T>
bool isPrime(const T& num);

template <class T>
T extendedEuclid(const T& a, const T& b, T* x, T* y);

#include "numberTheory.tpp"
#endif