#ifndef DEF_MAT_SOLVER_EIGEN_AND_MKL_DEF
#define DEF_MAT_SOLVER_EIGEN_AND_MKL_DEF


#include "SparseMat.hpp"
#include "SparseMatC.hpp"
#include <000_thirdparty/Eigen/Core>


/* �I���W�i�����O���(�Î~��/��]�@FEM���C�u����) */
namespace SRLfem{


/*
//=======================================================
// �� �X�p�[�X�s��p�\���o(Eigen��MKL�����̃\���o�̃��b�p�[)
//=======================================================*/
class MatSolversEigenMKL{
	/**/
	/* MKL�\���o�̃��b�p�[ */
	/**/
	template<typename MType, typename VType>
	static bool solveMLKpardisoBase(const slv_int size0, const MType& matA, VType* vecB, VType *results, int mat_mode, int num_para=1);
	/**/
	/*---------------*/
public:
	//
	/* Eigen�����\���o�̃��b�p�[���� */
	//
	static bool solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const Eigen::VectorXd& vecB, Eigen::VectorXd& results, bool init=false);
	static bool solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const double* vecB, double* results, bool init=true);
	static bool solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const Eigen::VectorXd& vecB, Eigen::VectorXd& results, bool init=false);
	static bool solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const double* vecB, double* results, bool init=true);
	static bool solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const Eigen::VectorXcd& vecB, Eigen::VectorXcd& results, bool init=false);
	static bool solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const dcomplex* vecB, dcomplex* results, bool init=true);
	static bool solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const Eigen::VectorXcd& vecB, Eigen::VectorXcd& results, bool init=false);
	static bool solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA,  const dcomplex* vecB, dcomplex* results, bool init=false);
	static bool solveEigenSimplicialLDLT(const slv_int size0, const SparseMat& matA,  const Eigen::VectorXd& vecB, Eigen::VectorXd& results);
	static bool solveEigenSimplicialLDLT(const slv_int size0, const SparseMatC& matA,  const Eigen::VectorXcd& vecB, Eigen::VectorXcd& results);
	//
	/* MKL�\���o�̃��b�p�[ */
	//
	static bool solveMLKpardisoSym(const slv_int size0, const SparseMat& matA, double* vecB, double *results, int num_para=1);
	static bool solveMLKpardisoSym(const slv_int size0, const SparseMatC& matA, dcomplex* vecB, dcomplex *results, int num_para=1);
	static bool solveMLKpardiso(const slv_int size0, const SparseMat& matA, double* vecB, double *results, int num_para=1);
	static bool solveMLKpardiso(const slv_int size0, const SparseMatC& matA, dcomplex* vecB, dcomplex *results, int num_para=1);
};

/* end of namespace */
};



#endif