#include <iostream>

#include <pybind11/embed.h> // everything needed for embedding

namespace py = pybind11;
using namespace py::literals;

using std::cout;
using std::endl;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    
    // example 1
    py::print("Hello, World!"); // use the Python API

    // example 2
    auto kwargs = py::dict("name"_a="World", "number"_a=42);
    auto message = "Hello, {name}! The answer is {number}"_s.format(**kwargs);
    py::print(message);

    // example 3
    py::module_ os = py::module_::import("os");
    py::print(os.attr("path"));

    auto math = py::module_::import("math");
    //py::object result1 = math.attr("sqrt")(2.0);
    //double root_two = result1.cast<double>();
    double root_two = math.attr("sqrt")(2.0).cast<double>();
    cout << "The square root of 2 is: " << root_two << "\n";

    // example 4
    py::module_ calc = py::module_::import("modules.calc");
    py::object result2 = calc.attr("add")(1, 2);
    int n = result2.cast<int>();
    cout << "the resoult of add(1, 2) is: " << n << endl;
}
