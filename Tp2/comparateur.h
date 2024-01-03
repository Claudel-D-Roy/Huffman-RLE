#ifndef COMPARATEUR_H__
#define COMPARATEUR_H__


#include "huffman.h"
class Comparateur : Huffman
{
public:
	bool operator() (const Noeud* gauche, const Noeud* droite) const {
		return gauche->freq > droite->freq;
	}
};


#endif // !COMPARATEUR_H__
