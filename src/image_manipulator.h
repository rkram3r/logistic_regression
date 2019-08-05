#pragma once

class image_manipulator
{
public:
	explicit image_manipulator(unsigned char *image, const unsigned short length) : image_{image}, length_{ length }
	{
	}

	unsigned char *get() const;
	double treshhold() const;
	char *hex_array() const;
	bool *binary_array() const;

private:
	unsigned char *image_;
	const unsigned short length_{};
};
