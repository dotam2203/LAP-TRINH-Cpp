#include <stdio.h>
#include <cstdlib>
const unsigned char oneBits[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int tinh(int c)
{
	int n=0;
	while (c > 0)
	{
		n += oneBits[c&0xf];
		//65: 1101 0101
		c = c>>4;
	}
	return n;
}

int main()
{
	int memory[256];
	
	FILE *f;
	unsigned char *buffer;
	unsigned long filelen, count=0;
	int i=0;
	
	f = fopen("text.txt", "rt");
	fseek(f, 0, SEEK_END); 
	filelen = ftell(f);             
	rewind(f);   
	buffer = (unsigned char *)malloc(filelen * sizeof(char)); 
	fread(buffer, filelen, 1, f); 
	fclose(f);
	
	for (;i<256; i++)
		memory[i] = -1;
		
	for (i=0;i < filelen; i++)
	{
		unsigned int temp = buffer[i];
		if (memory[temp] == -1)
		{
			memory[temp] = tinh(temp);
			count += memory[temp];
		}
		else
		{
			count += memory[temp];
		}
	}
	printf("So bit 1 co trong file: %d", count);
	return 0;
}
