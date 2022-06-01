#include <stdio.h>
#include <math.h>

class	auto_diff {
public:
	double f;
	double df;


	auto_diff(double x = 0, double y = 0) {
		f = x;
		df = y;
	}

	void print() {
		printf("%.3lf", f);
		printf(" < ");

		printf("%.3lf", df);
		printf(" >\n");
	}

};


auto_diff operator+(auto_diff a, auto_diff b) {

	auto_diff r;
	r.f = a.f + b.f;
	r.df = a.df + b.df;

	return r;
}


auto_diff operator+(double a, auto_diff b) {

	auto_diff r;
	r.f = a + b.f;
	r.df = b.df;

	return r;
}

auto_diff operator+(auto_diff b, double a) {

	auto_diff r;
	r.f = a + b.f;
	r.df = b.df;

	return r;
}

auto_diff operator*(auto_diff a, auto_diff b) {

	auto_diff r;
	r.f = a.f * b.f;
	r.df = a.f * b.df + a.df * b.f;

	return r;
}
