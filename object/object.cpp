#include <pybind11/pybind11.h>

struct Personne{
	Personne(const std::string &name) : name(name){}
	void setName(const std::string &name_) {name = name_;}
	const std::string &getName() const {return name;}

std::string name;
};

namespace py = pybind11;

PYBIND11_MODULE(object, o) {

	py::class_<Personne>(o, "Personne")
		.def(py::init<const std::string &>())
		.def("setName", &Personne::setName)
		.def("getName", &Personne::getName);
}
