#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
        std::cout << "Only accept 3 arguments. No more no less." << std::endl;
    else
    {
        std::string fileName = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];

        if (s1.length() == 0)
        {
            std::cout << "s1 is empty, nothing to replace" << std::endl;
            return (1);
        }

        std::ifstream inFile(fileName);
        if (!inFile)
        {
            std::cerr << "file open failed" << std::endl;
            return (1);
        }

        std::ofstream outFile(fileName + ".replace");
		if (!outFile)
		{
			std::cerr << "Error creating outfile" << std::endl;
			inFile.close();
			return 1;
		}

        std::cout << "Files opened successfully. Ready to replace." << std::endl;

        std::ostringstream oss;
        oss << inFile.rdbuf(); // Read entire file
        std::string content = oss.str();
        inFile.close();

        size_t pos = 0;
        while ((pos = content.find(s1, pos)) != std::string::npos)
        {
            content.erase(pos, s1.length());
			content.insert(pos, s2);
            pos += s2.length();
        }

        std::cout << content << std::endl;

        outFile << content;
		outFile.close();
    }
}
