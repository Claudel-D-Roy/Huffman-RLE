#include "huffman.h"
#include <iostream>
#include <queue>
#include "comparateur.h"
#include "bitpacker.h"
#include <iomanip>
#include <bitset>
std::string Huffman::Compresser(const std::string& data)
{
	m_dictionnaire.clear();
	m_Comphuff = data;
	int frequence[256] = { 0 };

	for (int i = 0; i < m_Comphuff.length(); i++)
		frequence[(unsigned char)m_Comphuff[i]]++;

	std::priority_queue < Noeud*, std::vector<Noeud*>, Comparateur> q;

	for (int i = 0; i < 256; i++)
	{
		if (frequence[i] != 0)
			q.push(new Noeud((char)i, frequence[i], nullptr, nullptr));
	}

	while (q.size() != 1)
	{
		Noeud* gauche = q.top();
		q.pop();
		Noeud* droite = q.top();
		q.pop();

		q.push(new Noeud(0, gauche->freq + droite->freq, gauche, droite));
	}

	Noeud* racine = q.top();
	GenererDictionnaire(racine, "", m_dictionnaire);
	std::string sortie;

	BitPacker bp;
	for (char c : m_Comphuff) {
		bp << m_dictionnaire[c];
		sortie += m_dictionnaire[c];
	}

	int kilobp = bp.Size() * 0.000125;
	std::cout << "Taille originale: " << m_Comphuff.length() * 8 << " bits" << std::endl;
	std::cout << "Taille finale: " << kilobp << " Ko" << std::endl;

	return sortie;
}

std::string Huffman::Decompresser(const std::string& data)
{
	m_Decomphuff = data;
	std::string sortie = "";
	int countNoeud = 0;
	Noeud* racine = new Noeud(0, 0, nullptr, nullptr);
	Noeud* Parent = racine;

	for (const auto& e : m_dictionnaire)
	{
		Noeud* courant = racine;
		for (char c : e.second) {
			if (c == '0') {

				if (!courant->Gauche) {
					courant->Gauche = new Noeud(0, 0, nullptr, nullptr);
				}
				courant = courant->Gauche;
			}
			else {
				if (!courant->Droite) {
					courant->Droite = new Noeud(0, 0, nullptr, nullptr);
				}
				courant = courant->Droite;
			}
			countNoeud++;
		}
		courant->c = e.first;
		courant->freq = stoi(e.second, nullptr, 2);
	}

	char Temp;
	int count = 0;

	for (int i = 0; i < m_Decomphuff.length(); i++)
	{
		Noeud* courant = racine;
		Temp = 0;
		while (Temp == 0) {

			if (count > m_Decomphuff.length())
				break;			

			char c = (char)m_Decomphuff[count];

			if (c == '0') {
				Parent = courant;
				courant = courant->Gauche;
				if (courant == nullptr) {
					courant = Parent;
					Temp = courant->c;
					break;
				}
				else
					Temp = courant->c;
			}
			else if (c == '1') {
				Parent = courant;
				courant = courant->Droite;
				if (courant == nullptr) {
					courant = Parent;
					Temp = courant->c;
					break;
				}
				else
					Temp = courant->c;
			}
			count++;
		}
		sortie += Temp;
		//sortie.length() == m_Comphuff.length() * /
		if (courant->freq == 0 && courant->c == 0)
			break;
	}
	return sortie;

}


void Huffman::GenererDictionnaire(Noeud* n, std::string code, Dictionnaire& dictionnaire)
{
	if (!n)
		return;
	GenererDictionnaire(n->Gauche, code + "0", dictionnaire);
	GenererDictionnaire(n->Droite, code + "1", dictionnaire);

	if (!n->Gauche && !n->Droite)
	{
		if (code == "")
			code = "0";

		dictionnaire[n->c] = code;
	}
}
