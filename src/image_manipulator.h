#pragma once

class image_manipulator
{
public:
	explicit image_manipulator(double** image, const unsigned short nof_rows, const unsigned short nof_columns) :
		image_{ image }, nof_rows_{ nof_rows }, nof_columns_{ nof_columns }
	{
	}

	void compress() const;
	double** get() const;
	double treshhold() const;
	char* hex_array() const;
	bool* binary_array() const;
private:
	double** image_;
	const unsigned short nof_rows_{};
	const unsigned short nof_columns_{};
};
