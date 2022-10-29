#include "VoxWriter.h"

//https://github.com/aiekick/MagicaVoxel_File_Writer
// example from @unphased on this topic : https://github.com/aiekick/MagicaVoxel_File_Writer/issues/2

// https://github.com/jpaver/opengametools

#include <iostream>
using namespace std;

vox::VoxWriter v;




//void rectangle(size_t x_start, size_t y_start, size_t x_end, size_t y_end, unsigned char colour_index)
//{
//	for (int i = x_start; i < x_end; i++)
//	{
//		for (int j = y_start; j < y_end; j++)
//		{
//			v.AddVoxel(i, j, 0, colour_index);
//		}
//	}
//}

void rectangle(size_t x_start, size_t y_start, size_t x_end, size_t y_end, std::vector<unsigned char> &pixels, size_t size)
{
	for (int i = x_start; i < x_end; i++)
	{
		for (int j = y_start; j < y_end; j++)
		{
			size_t index = j * size + i;
			pixels[index] = 1;
		}
	}
}


int main() 
{
	int size = 64;

	std::vector<unsigned char> pixels(size * size, 0);





	int a = size / 8;
 
	int red_index = 0, gray_index = 1;

	v.AddColor(255, 0, 0, 255, red_index);
	v.AddColor(127, 127, 127, 255, gray_index);

	for (int y = 0; y <= 3; y++)
	{
		for (int x = 0; x <= 3; x++)
		{
			rectangle(x * a * 2, y * a * 2, a * (2 * x + 1), a * (2 * y + 1), pixels, size);
		}
	}

	for (int y = 0; y <= 3; y++)
	{
		for (int x = 0; x <= 3; x++)
		{
			rectangle(a * (2 * x + 1), a * (2 * y + 1), (x + 1) * a * 2, (y + 1) * a * 2, pixels, size);
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			size_t index = j * size + i;

			if (pixels[index] == 1)
			{
				//std::cout << "red pixel" << endl;
				v.AddVoxel(i, j, 1, gray_index);
			}
			else
			{
				//cout << "gray pixel" << endl;
				v.AddVoxel(i, j, 1, 127);
			}
		}
	}

	v.SaveToFile("output_voxwriter.vox");
}