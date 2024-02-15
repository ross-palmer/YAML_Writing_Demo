#include "YAMLWriter.h"

void YAMLWriter::write()
{
	// Some high score data...
	std::string names[] = { "Jim", "John", "Mary", "Jane"};
	int scores[] = { 1,2,3,4 };

	// A YAML::Emitter acts as a YAML output stream 	
	YAML::Emitter out;
	out << YAML::BeginMap;
	// Highscores is the top level mapping
	// (it maps to a sequence as shown below)
	out << YAML::Key << "Highscores";
	out << YAML::Value << YAML::BeginSeq;
	
	// Hard coded loop - 4 iterations, one per name/score combo
	for (int i = 0; i < 4; i++)
	{
		// Write out the sequence...
		// Each entry in the sequence is a mapping of 
	    //  name: playersname 	    
		//  score: playerscore
		out << YAML::BeginMap;
		out << YAML::Key << "name";
		out << YAML::Value << names[i];
		out << YAML::Key << "score";
		out << YAML::Value << std::to_string(scores[i]);
		out << YAML::EndMap;
	}
	out << YAML::EndSeq;
	out << YAML::EndMap;
	std::cout << "Here's the raw YAML data:\n" << out.c_str() << "\n";
	
	// Now write it to a file..
	std::string file = ".\\Highscores.yaml";
	std::ofstream fout(file); // This is the path to the YAML file
	
	fout << out.c_str() << std::endl;
	fout.close();
}
