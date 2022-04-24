// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int	HEADER_SIZE = 44;

int	main(int argc, char *argv[])
{
	FILE	*input;
	FILE	*output;
	float	factor;
	uint8_t	header[HEADER_SIZE];

	// Check command-line arguments
	if (argc != 4)
	{
		printf("Usage: ./volume input.wav output.wav factor\n");
		return (1);
	}
	// Open files and determine scaling factor
	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		printf("Could not open file.\n");
		return (1);
	}
	output = fopen(argv[2], "w");
	if (output == NULL)
	{
		printf("Could not open file.\n");
		return (1);
	}
	factor = atof(argv[3]);
	// TODO: Copy header from input file to output file
	fread(header, sizeof(u_int8_t), HEADER_SIZE, input);
	fwrite(header, sizeof(u_int8_t), HEADER_SIZE, output);
	printf("%s", header);
	// TODO: Read samples from input file and write updated data to output file
	// Close files
	fclose(input);
	fclose(output);
}
