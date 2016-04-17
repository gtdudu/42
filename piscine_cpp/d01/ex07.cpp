
#include <iostream>
#include <fstream>
#include <sstream>


void replace_occurences(std::string& data, const std::string& search, const std::string& replace)
{
    size_t pos = 0;

    while ((pos = data.find(search, pos)) != std::string::npos) {
         data.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

bool is_file_exist(const char *file)
{
    std::ifstream infile(file);
    return infile.good();
}


std::string		get_file_content(std::string file)
{
	std::ifstream		ifs(file);
	std::stringstream	buffer;

	buffer << ifs.rdbuf();
	ifs.close();

	return 		buffer.str();
}

void			create_file(std::string file, std::string data)
{
	std::string			new_file;

	new_file = file;
	new_file += ".REPLACE";

	std::ofstream		out(new_file);

	out << data;
	out.close();
}

int		main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "usage: ./replace file s1 s2" << std::endl;
		return (-1);
	}

	if (!is_file_exist(av[1]))
	{
		std::cout << "file not exist" << std::endl;
		return (-1);
	}

	std::string			search(av[2]);
	std::string			replace(av[3]);

	if (search.empty() || replace.empty())
	{
		std::cout << "usage: ./replace file s1 s2" << std::endl;
		std::cout << "s1 or s2 should not be empty" << std::endl;
		return (-1);
	}

	std::string			data(get_file_content(av[1]));

	replace_occurences(data, search, replace);

	create_file(av[1], data);

	return (0);
}
