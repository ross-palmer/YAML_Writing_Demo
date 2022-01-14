#include "YAMLReader.h"

void YAMLReader::readHighScore(const YAML::Node& t_highScoreNode, ScoringData & t_scoreData)
{
	t_scoreData.m_name = t_highScoreNode["name"].as<std::string>();
	t_scoreData.m_score = t_highScoreNode["score"].as<int>();
}


void YAMLReader::loadFile(std::string t_filename, LevelData& t_level)
{
	try
	{
		YAML::Node baseNode = YAML::LoadFile(t_filename.c_str());
		if (baseNode.IsNull())
		{
			std::string message("File: " + t_filename + " not found");
			throw std::exception(message.c_str());
		}
		
		YAML::Node const& scoreNodes = baseNode["Highscores"].as<YAML::Node>();
		// Loop through each score mapping
		for (YAML::Node const& scoreNode : scoreNodes)
		{
			ScoringData scoreData;
			readHighScore(scoreNode, scoreData);
			t_level.m_highScores.emplace_back(scoreData);
		}
	}
	catch (YAML::ParserException& e)
	{
		std::string message(e.what());
		message = "YAML Parser Error: " + message;
		throw std::exception(message.c_str());
	}
	catch (std::exception& e)
	{
		std::string message(e.what());
		message = "Unexpected Error: " + message;
		throw std::exception(message.c_str());
	}
}


void YAMLReader::read()
{

}

