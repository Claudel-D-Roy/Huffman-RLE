#include "rle.h"
#include <iostream>


std::string RLE::Compresser(const std::string& data)
{
	std::string resultat = "";
	int count = 1;
	char Carac;

	for (int i = 1; i < data.length() + 1; i++) {
		Carac = data[i - 1];
		if (data[i] == data[i - 1]) {
			
			if (i == data.length())
			{
				resultat += (char)count;
				resultat += Carac;
				count = 1;
			}
			
			if (count == 255)
			{
				resultat += (char)count;
				resultat += Carac;
				count = 1;
			}
			else
				count++;
		}
		else {
			resultat += (char)count;
			resultat += Carac;
			count = 1;
		}
	}

	int kilo = resultat.length() * 8;
	std::cout << "Taille originale: " << data.length() * 8 << " bits" << std::endl;
	std::cout << "Taille finale: " << kilo * 0.000125 << " ko" << std::endl;

	return resultat;

}

std::string RLE::Decompresser(const std::string& data)
{
	std::string Resultat = "";
	char Cara;
	int count = 0;
	for (int i = 0; i < data.length(); i++) {
		count = (unsigned char)data[i];
		i++;
		Cara = data[i];
		while (count != 0) {
			Resultat += Cara;
			--count;
		}
	}
	return Resultat;

}


