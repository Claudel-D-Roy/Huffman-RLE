#include "huffman.h"
#include "fileloader.h"
#include <iostream>
#include "rle.h"


int main() {
	std::string fileUnload1 = "01.txt";
	std::string fileUnload2 = "02.html";
	std::string fileUnload3 = "03.bmp";
	std::string fileUnload4 = "04.jpg";
	std::string fileUnload5 = "05.exe";
	std::string fileUnload6 = "06.zip";
	std::string fileUnload7 = "07.bin";
	std::string fileUnload8 = "08.bin";
	std::string fileUnload9 = "09.bin";
	std::string fileUnload10 = "10.bin";
	std::string fileUnload11 = "11.bin";

	std::string fileLoaded1 = "";
	std::string fileLoaded2 = "";
	std::string fileLoaded3 = "";
	std::string fileLoaded4 = "";
	std::string fileLoaded5 = "";
	std::string fileLoaded6 = "";
	std::string fileLoaded7 = "";
	std::string fileLoaded8 = "";
	std::string fileLoaded9 = "";
	std::string fileLoaded10 = "";
	std::string fileLoaded11 = "";

	FileLoader load;
	
	fileLoaded1 = load.LoadFile(fileUnload1);
	fileLoaded2 = load.LoadFile(fileUnload2);
	fileLoaded3 = load.LoadFile(fileUnload3);
	fileLoaded4 = load.LoadFile(fileUnload4);
	fileLoaded5 = load.LoadFile(fileUnload5);
	fileLoaded6 = load.LoadFile(fileUnload6);
	fileLoaded7 = load.LoadFile(fileUnload7);
	fileLoaded8 = load.LoadFile(fileUnload8);
	fileLoaded9 = load.LoadFile(fileUnload9);
	fileLoaded10 = load.LoadFile(fileUnload10);
	fileLoaded11 = load.LoadFile(fileUnload11);


	std::string data1 = fileLoaded1;
	std::string data2 = fileLoaded2;
	std::string data3 = fileLoaded3;
	std::string data4 = fileLoaded4;
	std::string data5 = fileLoaded5;
	std::string data6 = fileLoaded6;
	std::string data7 = fileLoaded7;
	std::string data8 = fileLoaded8;
	std::string data9 = fileLoaded9;
	std::string data10 = fileLoaded10;
	std::string data11 = fileLoaded11;

	std::cout << "=========================================================================" << std::endl;
	std::cout << "Huffman" << std::endl;
	//Huffman 
	Huffman huff;

	if (data1 == huff.Decompresser(huff.Compresser(data1)))
		std::cout << "oui" << " 01" << std::endl;
	else
		std::cout << "non" << " 01" << std::endl;
	if (data2 == huff.Decompresser(huff.Compresser(data2)))
		std::cout << "oui" << " 02" << std::endl;
	else
		std::cout << "non" << " 02" << std::endl;
	if (data3 == huff.Decompresser(huff.Compresser(data3)))
		std::cout << "oui" << " 03" << std::endl;
	else
		std::cout << "non" << " 03" << std::endl;
	if (data4 == huff.Decompresser(huff.Compresser(data4)))
		std::cout << "oui" << " 04" << std::endl;
	else
		std::cout << "non" << " 04" << std::endl;
	if (data5 == huff.Decompresser(huff.Compresser(data5)))
		std::cout << "oui" << " 05" << std::endl;
	else
		std::cout << "non" << " 05" << std::endl;
	if (data6 == huff.Decompresser(huff.Compresser(data6)))
		std::cout << "oui" << " 06" << std::endl;
	else
		std::cout << "non" << " 06" << std::endl;
	if (data7 == huff.Decompresser(huff.Compresser(data7)))
		std::cout << "oui" << " 07" << std::endl;
	else
		std::cout << "non" << " 07" << std::endl;
	if (data8 == huff.Decompresser(huff.Compresser(data8)))
		std::cout << "oui" << " 08" << std::endl;
	else
		std::cout << "non" << " 08" << std::endl;
	if (data9 == huff.Decompresser(huff.Compresser(data9)))
		std::cout << "oui" << " 09" << std::endl;
	else
		std::cout << "non" << " 09" << std::endl;
	if (data10 == huff.Decompresser(huff.Compresser(data10)))
		std::cout << "oui" << " 10" << std::endl;
	else
		std::cout << "non" << " 10" << std::endl;
	if (data11 == huff.Decompresser(huff.Compresser(data11)))
		std::cout << "oui" << " 11" << std::endl;
	else
		std::cout << "non" << " 11" << std::endl;

	//RLE 
	RLE rle;

	std::cout << "=========================================================================" << std::endl;
	std::cout << "RLE" << std::endl;

	if (data1 == rle.Decompresser(rle.Compresser(data1)))
		std::cout << "oui" << " 01" << std::endl;
	else
		std::cout << "non" << " 01" << std::endl;
	if (data2 == rle.Decompresser(rle.Compresser(data2)))
		std::cout << "oui" << " 02" << std::endl;
	else
		std::cout << "non" << " 02" << std::endl;
	if (data3 == rle.Decompresser(rle.Compresser(data3)))
		std::cout << "oui" << " 03" << std::endl;
	else
		std::cout << "non" << " 03" << std::endl;
	if (data4 == rle.Decompresser(rle.Compresser(data4)))
		std::cout << "oui" << " 04" << std::endl;
	else
		std::cout << "non" << " 04" << std::endl;
	if (data5 == rle.Decompresser(rle.Compresser(data5)))
		std::cout << "oui" << " 05" << std::endl;
	else
		std::cout << "non" << " 05" << std::endl;
	if (data6 == rle.Decompresser(rle.Compresser(data6)))
		std::cout << "oui" << " 06" << std::endl;
	else
		std::cout << "non" << " 06" << std::endl;
	if (data7 == rle.Decompresser(rle.Compresser(data7)))
		std::cout << "oui" << " 07" << std::endl;
	else
		std::cout << "non" << " 07" << std::endl;
	if (data8 == rle.Decompresser(rle.Compresser(data8)))
		std::cout << "oui" << " 08" << std::endl;
	else
		std::cout << "non" << " 08" << std::endl;
	if (data9 == rle.Decompresser(rle.Compresser(data9)))
		std::cout << "oui" << " 09" << std::endl;
	else
		std::cout << "non" << " 09" << std::endl;
	if (data10 == rle.Decompresser(rle.Compresser(data10)))
		std::cout << "oui" << " 10" << std::endl;
	else
		std::cout << "non" << " 10" << std::endl;
	if (data11 == rle.Decompresser(rle.Compresser(data11)))
		std::cout << "oui" << " 11" << std::endl;
	else
		std::cout << "non" << " 11" << std::endl;


}