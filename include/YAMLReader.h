#pragma once
#include "yaml-cpp\yaml.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct ScoringData
{
	std::string m_name;
	int m_score;
};


struct LevelData
{
	std::vector<ScoringData> m_highScores;
};

class YAMLReader
{
public:
	static void readHighScore(const YAML::Node& t_highScoreNode, ScoringData& t_scoreData);
	static void loadFile(std::string t_fileName, LevelData& t_level);
	static void read();

private:
};

