#pragma once
namespace acetza::muza::primitives {
using Primitive = double (*)(double part);
double Saw(double part);
double Sqr(double part);
double Tri(double part);
double Sin(double part);
}  // namespace acetza::muza::primitives