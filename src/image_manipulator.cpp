#include "image_manipulator.h"


unsigned char* image_manipulator::get() const
{
	return image_;
}

double image_manipulator::treshhold() const
{
	double sum = 0;
	for (auto index = 0; index < length_; index++)
	{
		sum += image_[length_];
	}
	return sum / length_;
}

bool* image_manipulator::binary_array() const
{
	const auto treshold = treshhold();
	const auto binary_array_image = new bool[length_];

	for (auto index = 0; index < length_; index++)
	{
		binary_array_image[index] = image_[index] <= treshold;
	}

	return binary_array_image;
}

char* image_manipulator::hex_array() const
{
	const auto binary_array_image = binary_array();
	const auto digits = "0123456789ABCDEF";
	const auto int_size = sizeof(int);
	const auto image_as_numbers = new char[length_ / int_size + 1];
	for (auto index = 0; index < length_; index += 4)
	{
		const auto add_8 = binary_array_image[index];
		const auto add_4 = index + 1 < length_ && binary_array_image[index + 1];
		const auto add_2 = index + 2 < length_ && binary_array_image[index + 2];
		const auto add_1 = index + 3 < length_ && binary_array_image[index + 3];

		image_as_numbers[index / int_size] = digits[(add_8 ? 8 : 0) | (add_4 ? 4 : 0) | (add_2 ? 2 : 0) | (add_1 ? 1 : 0)];
	}
	return image_as_numbers;
}
