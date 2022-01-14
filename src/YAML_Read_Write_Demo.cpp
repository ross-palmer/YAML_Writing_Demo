#include <iostream>
#include "YAMLWriter.h"
#include "YAMLReader.h"

#ifdef _DEBUG 
#pragma comment(lib,"libyaml-cppmdd.lib")
#else 
#pragma comment(lib,"libyaml-cppmd.lib")
#endif

// Very simple demonstration program showing how to write a high score table in 
//  a structured YAML format.
int main()
{
	// Create a YAML file with some high score data
	// Format is a key called HighScores that maps to a sequence of names and scores, for example:
	// HighScores:
	//    - name: (name 1)
	//      score: (score 1)
	//    - name: (name 2)
	//      score: (score 2)
	// etc.
	// Create the YAML file with some sample score data.
	YAMLWriter::write();
	// To read back the YAML file, we need a struct to hold the data 
	// LevelData is defined in YAMLReader.h
	LevelData levelData;
	// Load the YAML file we created earlier, put the data into the levelData struct.
	YAMLReader::loadFile(".\\Highscores.yaml", levelData);
	// Output the data we just read:
	std::cout << "\nHere's the data just read from the YAML file: \n";
	for (ScoringData data : levelData.m_highScores)
	{
		std::cout << "Name: " << data.m_name << ", score: " << data.m_score << "\n";
	}

	std::cin.get();
}
