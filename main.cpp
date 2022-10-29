#include "VoxWriter.h"

//https://github.com/aiekick/MagicaVoxel_File_Writer
// example from @unphased on this topic : https://github.com/aiekick/MagicaVoxel_File_Writer/issues/2





vox::VoxWriter v;




void rectangle(size_t x_start, size_t y_start, size_t x_end, size_t y_end, unsigned char colour_index)
{
	for (int i = x_start; i < x_end; i++)
	{
		for (int j = y_start; j < y_end; j++)
		{
			v.AddVoxel(i, j, 0, colour_index);
		}
	}

}



int main() 
{




	int size = 64;

	int a = size / 8;
 


	for (int y = 0; y <= 3; y++)
	{
		for (int x = 0; x <= 3; x++)
		{
			rectangle(x * a * 2, y * a * 2, a * (2 * x + 1), a * (2 * y + 1), 0);
		}
	}

	for (int y = 0; y <= 3; y++)
	{
		for (int x = 0; x <= 3; x++)
		{
			rectangle(a * (2 * x + 1), a * (2 * y + 1), (x + 1) * a * 2, (y + 1) * a * 2, 0);
		}
	}

	rectangle(0, 0, size, size, 1);

	v.SaveToFile("output_voxwriter.vox");
}