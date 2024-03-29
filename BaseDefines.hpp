﻿#ifndef DEF_BASEDEF00_HEADER_DEF
#define DEF_BASEDEF00_HEADER_DEF

/* オリジナル名前空間(静止器/回転機FEMライブラリ) */
namespace SRLfem{

/* 整数型の定義～大規模にする際はlongにする */
using femint = int;

/* その他、世界定数 */
namespace CommonDef{
	constexpr double PI = 3.14159265358979323846;		/* 円周率 */
	constexpr double PI_2 = 1.57079632679489661923;		/* 円周率/2 */
	constexpr double PI_4 = 0.785398163397448309616;	/* 円周率/4 */
	constexpr double L_SPEED = 299792458.0;				/* 光の速度 */
	constexpr double MYU0 = 4.0*PI*1.0e-7;				/* 真空透磁率 */
	constexpr double VNYU0 = 1.0/MYU0;					/* 真空磁気抵抗率 */
	constexpr double EPS0 = 8.8541878128*1.0e-12;		/* 真空誘電率 */	
	constexpr double NORMB_EPS = 1.0e-10;				/* 微小ゼロとみなす磁束密度ノルム */
	constexpr double MATH_E = 2.71828182845904523536;	/* eの値 */
	constexpr double SQRT2 = 1.41421356237309504880;	/* sqrt(2) */
	constexpr double SQRT1_2 = 1.41421356237309504880;	/*1/sqrt(2) */
};


/* end of namespace */
};

#endif

