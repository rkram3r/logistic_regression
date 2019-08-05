#include "pch.h"
#include "ok.h"
#include "nok.h"
#include "src/logistic_regression.h"
#include "src/image_manipulator.h"

double coef[] = { 0.96162954, 1.5798257, 1.15578957, 0.87683753, -2.0659162, -1.79649967,
				 -1.99569325, -2.12694536, -2.03716275, -1.84588508, -2.18402691, -1.55599748,
				 -1.26471973, -1.42254674, 1.10134503, 0.98292626, 1.24841439, 0.94516222,
				 1.16034822, 1.10906249, 0.99024727, 1.28927712, 1.3650571, 1.11811895,
				 1.61958369, 0.81111923, 0.70412172, 0.57261735, 0.67881138, 0.46075267,
				 0.17998909, 0.56560843, 0.53451477, 0.46506116, -0.60542082, -0.38136447,
				 -0.18131959, -0.26099146, -0.2399914, -0.2635798, 0.01175717, 0.00743979,
				 0.30875504, -0.09764507, -0.32788512, -0.80935435, -0.87904561, -0.6895562,
				 -0.5326027, -1.06616436, -0.68904028, -0.64145815, -0.89266816, -1.20789193,
				 -0.27950533, -0.27384109, 0.34178456, 0.21106685, -0.01997451, 0.13528488,
				 0.01200242, 0.26121166, 0.34261025, 0.87087366, 0.96592315, 0.77510937,
				 0.5226508, 0.41862142, 0.44527862, 0.46403118, 0.34592521, 0.61041455,
				 0.90292049, 0.59783172 };
double intercept = 1;

TEST(Model, predict_ok)
{
	const auto model = new logistic_regression{ intercept, coef, 74, std::exp(1.0), pow };
	for (auto& index : ok)
	{
		const auto image = new image_manipulator{ index,3996 };
		const auto prediction = model->predict(image->get());
		auto rounded_prediction = int(round(prediction));

		EXPECT_EQ(rounded_prediction, 1);
		EXPECT_TRUE(true);
	}
}

TEST(Model, predict_nok)
{
	const auto model = new logistic_regression{ intercept, coef, 74, std::exp(1.0), pow };
	for (auto& index : nok)
	{
		const auto image = new image_manipulator{ index, 3996 };
		const auto prediction = model->predict(image->get());
		auto rounded_prediction = int(round(prediction));
		EXPECT_EQ(rounded_prediction, 0);
		EXPECT_TRUE(true);
	}
}

TEST(Model, convert_to_binary)
{
	double* treshold_should_be_two[2] = {
		new double[2]{1, 3},
		new double[2]{3, 1},
	};
	const auto image = new image_manipulator{ treshold_should_be_two, 2, 2 };
	const auto bin_img = image->binary_array();
	const auto x = new bool[4]{ true, false, false, true };
	for (auto index = 0; index < 4; index++)
	{
		EXPECT_EQ(bin_img[index], x[index]);
		EXPECT_TRUE(true);
	}
}

TEST(Model, convert_to_number)
{
	double* treshold_should_be_two[2] = {
		new double[5]{1, 3, 3, 1, 1},
		new double[5]{3, 1, 1, 3, 3},
	};
	const auto image = new image_manipulator{ treshold_should_be_two, 2, 5 };
	const auto img_as_number = image->hex_array();
	const auto nof_tests = 3;
	const auto x = new char[nof_tests] {'9', 'B', '0'};
	for (auto index = 0; index < nof_tests; index++)
	{
		EXPECT_EQ(img_as_number[index], x[index]);
	}
}