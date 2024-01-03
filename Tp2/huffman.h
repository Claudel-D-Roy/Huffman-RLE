#ifndef HUFFMAN_H__
#define HUFFMAN_H__
#include <string>
#include <map>


class Huffman
{
public:
	std::string Compresser(const std::string& data);
	std::string Decompresser(const std::string& data);
	struct Noeud {
		char c;
		int freq;
		Noeud* Gauche;
		Noeud* Droite;
		Noeud(char c, int freq, Noeud* Gauche, Noeud* Droite) : c(c), freq(freq), Gauche(Gauche), Droite(Droite) {}
	};
private:
	typedef std::map<char, std::string> Dictionnaire;
	Dictionnaire m_dictionnaire;
	void GenererDictionnaire(Noeud* n, std::string code, Dictionnaire& dictionnaire);
	std::string m_Comphuff;
	std::string m_Decomphuff;
};
#endif // !HUFFMAN_H__
