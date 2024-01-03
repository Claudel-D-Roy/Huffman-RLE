#ifndef RLE_H__
#define RLE_H__

#include <string>

class RLE
{

public:
	std::string Compresser(const std::string& data);

	std::string Decompresser(const std::string& data);

};

#endif 