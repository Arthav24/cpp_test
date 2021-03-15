#pragma once

const unsigned int OneAsInt = 0x3F800000;
const float ScaleUp = float(0x00800000);
const float ScaleDown = 1.0f / ScaleUp;

float SqrtNewRap_fp(float x);
float Sqrt_fp(float x);
float Pow_fp(float x, float p); // based on x^p=2^plog2x
float Exp2_fp(float x);
float Log2_fp(float x);
inline unsigned int AsInt(float f);
inline float AsFloat(unsigned int i);
float NegateFloat(float f);
int **create_init_a2d(int, int);
void printa2d(int **&a2d, int, int);
void swapfirst_last_col(int **&a2d, int, int);
void deletea2d(int **&a2d, int &);
float Q_rsqrt(float);
int Alpha_num_sum(std::string);
int *create_init_array(int &);
void dsum_possible(int *&array, int &, int &);
int gcdExtended(int a, int b, int *x, int *y);
void pangramCheck(std::string&);