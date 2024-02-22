
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <memory>
#include <iostream>

#include "SparseMat.hpp"
#include "MatSolversICCG.hpp"

using namespace std;
using namespace SRLfem;
namespace py = pybind11;

PYBIND11_MODULE(SparseMatPy, m)
{
	 py::class_<SparseMat, shared_ptr<SparseMat>>(m, "SparseMat")
    .def(py::init<>([](const py::array_t<int>& rows,
                       const py::array_t<int>& cols,
                       const py::array_t<double>& vals,
                       int N)
	{
		auto mat = make_shared<SparseMat>(N);
		for(int i=0; i<rows.size(); i++)
		{
			mat->add(rows.at(i), cols.at(i), vals.at(i));
		}
		mat->fix();
		return mat;
	}))
;

	m.def("ICCG", [](double tol, int max_iter,  double acc, const SparseMat& A,
									 const py::array_t<double>& b, py::array_t<double>& x,
									 bool is_diag_scale, bool is_save_best, bool is_save_residual_log,
									 int diverge_judge_type, double bad_div_val, int bad_div_count_thres)
	{
		auto MatSolvesICCG = make_shared<MatSolversICCG>();
//		MatSolvesICCG->setDiagScale(is_diag_scale);
//		MatSolvesICCG->setSaveBest(is_save_best);
//		MatSolvesICCG->setSaveLog(is_save_residual_log);
//		MatSolvesICCG->setDirvegeType(diverge_judge_type);
//		MatSolvesICCG->setBadDivVal(bad_div_val);
//		MatSolvesICCG->setBadDivCount(bad_div_count_thres);
		MatSolvesICCG->solveICCG(b.size(), tol, max_iter, acc, A, b.data(), const_cast<double*>(x.data()) );
		return x;
	});
}

