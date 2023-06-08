#include "HighScore.h"

HighScore::HighScore()
{
	for (int i = 0; i < 5; i++)
	{
		scores.push_back(0);
		names.push_back("-");
	}
	size = 0;
}

HighScore::HighScore(std::vector<unsigned short int> sc, std::vector<std::string> ns) : scores(sc), names(ns)
{
	size = sc.size();
}

HighScore::HighScore(const HighScore& hs) : scores(hs.scores), names(hs.names), size(hs.size)
{

}

HighScore::~HighScore()
{

}

void HighScore::setNewScore(unsigned short int sc, int pos)
{
	for (int i = 4; i > pos; i--)
	{
		scores[i] = scores[i - 1];
	}
	scores[pos] = sc;
}

void HighScore::setNewName(std::string nm, int pos)
{
	for (int i = 4; i > pos; i--)
	{
		names[i] = names[i - 1];
	}
	names[pos] = nm;
}

unsigned short int HighScore::getScore(int i)
{
	return scores[i];
}

std::string HighScore::getName(int i)
{
	return names[i];
}

int HighScore::getSize()
{
	size = 0;

	for (int i = 0; i < 5; i++)
	{
		if (scores[i] > 0)
		{
			size++;
		}
	}

	return size;
}

bool HighScore::empty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
