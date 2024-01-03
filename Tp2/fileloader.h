#ifndef FILELOADER_H__
#define FILELOADER_H__
#include <string>
#include <fstream>
#include <iostream>

class FileLoader {

public:
	std::string LoadFile(const std::string& filename)
	{
		std::ifstream f(filename.c_str(), std::ios::binary);
		if (!f.is_open())
			return "";
		
		f.seekg(0, std::ios::end);
		unsigned int len = f.tellg();
		f.seekg(0, std::ios::beg);
		char* tmp = new char[len];
		f.read(tmp, len);
		f.close();
		std::string buffer(tmp, len);
		delete[] tmp;
		return buffer;
	}


};
#endif