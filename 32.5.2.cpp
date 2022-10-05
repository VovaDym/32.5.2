#include <iostream>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"


void createJSON()
{
	std::ofstream file("movies.json");
	nlohmann::json json = {
		{ "Legends of the Fall",	{
			{"country",  "United States of America"},
			{"released",     "December 23, 1994 (US)"},
			{"studio",   {
				"TriStar Pictures", 
				"The Bedford Falls Company"
			}} ,
			{"screenplay by", {
				"Susan Shilliday", 
				"William D. Wittliff"
			}},
			{"director", {
				"Edward Zwick"
			}},
			{"producer", {
				"Marshall Herskovitz",
				"William D.Wittliff"
			}},
			{"starring", {
				{"Anthony Hopkins",  "Colonel William Ludlow"},
				{"Brad Pitt", "Tristan Ludlow"},
				{"Aidan Quinn", "Alfred Ludlow"},
				{"Julia Ormond", "Susannah Fincannon-Ludlow"}
				}
			}
		  }
		},

		{ "Seven", {
			{"country",  "United States of America"},
			{"released",     "September 22, 1995 (US)"},
			{"studio",   "Andrew Kevin Walker's"},
			{"screenplay by",   "Richard Francis-Bruce"},
			{"director", "David Fincher"},
			{"producer", {
				"Arnold Kopelson",
				"Phyllis Carlyle"	
			}},
			{"starring", {
				{"Brad Pitt", "David Mills"},
				{"Morgan Freeman", "William Somerset"},
				{"Gwyneth Paltrow",  "Tracy Mills"},
				{"Kevin Spacey", "John Doe"}
				}
			}
		  }
		},

		{ "The Curious Case of Benjamin Button", {
			{"country", "United States of America"},
			{"released",    "December 25, 2008"},
			{"studio",  {
				"Paramount Pictures",
				"Warner Bros. Pictures",
				"The Kennedy/Marshall Company"
			}},
			{"screenplay by", "Eric Roth"},
			{"director", "David Fincher"},
			{"producer", {
				"Ceán Chaffin",
				"Kathleen Kennedy",
				"Frank Marshall"
			}},
			{"starring", {
				{"Brad Pitt",  "Benjamin Button (adult)"},
				{"Robert Towers", "Benjamin Button (apparent adult)"},
				{"Peter Donald Badalamenti II",  "Benjamin Button (apparent adult)"},
				{"Tom Everett",  "Benjamin Button (apparent adult)"}
				}
			}
		  }
		},

		{ "Meet Joe Black", {
			{"country", "United States of America"},
			{"released",    "November 13, 1998"},
			{"studio",  {
				"City Light Films",
				"Universal Pictures"
			}},
			{"screenplay by", {
				"Bo Goldman",
				"Kevin Wade",
				"Ron Osborn",
				"Jeff Reno"
			}},
			{"director", "Martin Brest"},
			{"producer", "Martin Brest"},
			{"starring", {
				{"Brad Pitt", "Death/Joe Black"},
				{"Anthony Hopkins",  "Bill Parrish"},
				{"Claire Forlani",   "Susan Parrish"},
				{"Jake Weber",   "Drew"}
				}
			}
		  }
		},

		{ "Seven Years in Tibet", {
			{"country",  "United States of America"},
			{"released", "October 10, 1997 (US)"},
			{"studio",   "TriStar Pictures"},
			{"screenplay by", "Becky Johnston"},
			{"director", "Jean-Jacques Annaud"},
			{"producer", {
				"Jean-Jacques Annaud",
				"Iain Smith",
				"John H. Williams"
			}},
			{"starring", {
				{"Brad Pitt", "Heinrich Harrer"},
				{"David Thewlis", "Ngapoi Ngawang Jigme"},
				{"Mako",  "Kungo Tsarong"},
				{"Danny Denzongpa",  "Regent"}
				}
			}
		  }
		}
	};

	file << json;
	file.close();
}



int main()
{
    createJSON();

	std::cout << "Enter actor's name: ";
	std::string name;
	std::getline(std::cin, name);

	std::ifstream file("movies.json");
	if (file.is_open())
	{
		nlohmann::json json;
		file >> json;
		file.close();

		bool found = false;
		for (auto itJson = json.begin(); itJson != json.end(); ++itJson)
		{
			auto actors = itJson.value().at("starring");
			auto role = actors.find(name);
			if (role != actors.end())
			{
				std::cout.width(15);
				std::cout << itJson.key() << " as " << *role << std::endl;
				found = true;
			}
		}

		if (!found)
		{
			std::cout << "Actor " << name << " not found" << std::endl;
		}		
	}
	else
	{
		std::cerr << "Movies.json not found" << std::endl;
	}		
}