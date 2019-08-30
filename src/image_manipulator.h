#pragma once

class image_manipulator
{
public:
	static double calculate_treshold(unsigned char* image, unsigned short nof_cells);
	static unsigned short compromise_image_return_new_index(unsigned char* image, const unsigned short nof_cells);
	static void compromise_image(unsigned char* image, const unsigned short nof_cells);
};

inline double image_manipulator::calculate_treshold(unsigned char* image, const unsigned short nof_cells)
{
	double sum = 0;
	for (auto index = 0; index < nof_cells; index++)
	{
		sum += image[index];
	}
	return sum / nof_cells;
}

inline bool is_cell_lte_treshold(const unsigned char* image, const double treshold, const unsigned short index)
{
	return image[index] <= treshold;
}

inline unsigned short image_manipulator::compromise_image_return_new_index(unsigned char* image, const unsigned short nof_cells)
{
	const auto digits = "0123456789ABCDEF";
	const auto int_size = sizeof(int);
	const auto treshold = calculate_treshold(image, nof_cells);

	for (auto index = 0; index < nof_cells; index += 4)
	{
		const auto add_8 = is_cell_lte_treshold(image, treshold, index);
		const auto add_4 = index + 1 < nof_cells && is_cell_lte_treshold(image, treshold, index + 1);
		const auto add_2 = index + 2 < nof_cells && is_cell_lte_treshold(image, treshold, index + 2);
		const auto add_1 = index + 3 < nof_cells && is_cell_lte_treshold(image, treshold, index + 3);

		image[index / int_size] = digits[(add_8 ? 8 : 0) | (add_4 ? 4 : 0) | (add_2 ? 2 : 0) | (add_1 ? 1 : 0)];
	}

	return nof_cells / int_size + 1;
}

inline bool is_in_square(const int index, const int squares_per_row_col, const unsigned int nof_rows, const unsigned int nof_cols)
{
	const auto grid_length = nof_rows / squares_per_row_col;
	const auto grid_height = nof_cols / squares_per_row_col;

	const auto is_in_left_area = (index * grid_length) % nof_rows < grid_length;
	return false;
}

inline bool get_square_of(const int index, const int squares_per_row_col, const unsigned int nof_rows, const unsigned int nof_cols)
{
	const auto grid_length = nof_rows / squares_per_row_col;
	const auto grid_height = nof_cols / squares_per_row_col;
	
	const auto is_in_left_area = index / grid_length % squares_per_row_col;
	return false;
}

inline void compromise_image(unsigned char* image, const unsigned int nof_rows, const unsigned int nof_cols, const unsigned short compromise_level)
{
	const auto squares_per_row_col = 1 << compromise_level;
	const auto compromise_factor = 1 << (compromise_level * 2);
	for(auto index = 0; index < compromise_factor; index ++)
	{
		
	}
}