#pragma once

class logistic_regression
{
public:
	explicit logistic_regression(const double* coef, const double euler, double (*pow)(double, double)) :
		coef_{ coef },
		euler_{ euler },
		pow_{ pow }
	{
	}
	double predict(double** matrix, unsigned short nof_rows, unsigned short nof_columns) const;

private:
	const double* coef_;
	const double euler_{};
	double (*pow_)(double, double);
};