#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

std::vector<std::string> ft_split(const std::string &str, const std::string &delim) {
    std::vector<std::string> vec;
    if (str.empty() || delim.empty())
        return vec;

    std::string::const_iterator posBegin = str.begin();
    std::string::const_iterator posEnd;

    while (posBegin != str.end()) {
        posEnd = std::search(posBegin, str.end(), delim.begin(), delim.end());
        if (posBegin != posEnd)
            vec.push_back(std::string(posBegin, posEnd));
        if (posEnd == str.end())
            break;
        posBegin = posEnd + delim.size();
    }

    return vec;
}

int main() {
    std::ifstream file("../input.txt");
    if (!file.is_open())
    {
        std::cerr << "Erreur: impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<int> list_1, list_2;

    while (std::getline(file, line)) {
        std::vector<std::string> splitted = ft_split(line, " ");
        if (splitted.size() != 2)
        {
            std::cerr << "Erreur: ligne mal formée dans le fichier." << std::endl;
            return 1;
        }

        char *endptr;
        int value1 = std::strtol(splitted[0].c_str(), &endptr, 10);
        if (*endptr != '\0') 
        {
            std::cerr << "Erreur: valeur non numérique détectée." << std::endl;
            return 1;
        }

        int value2 = std::strtol(splitted[1].c_str(), &endptr, 10);
        if (*endptr != '\0')
        {
            std::cerr << "Erreur: valeur non numérique détectée." << std::endl;
            return 1;
        }

        list_1.push_back(value1);
        list_2.push_back(value2);
    }

    file.close();

    if (list_1.size() != list_2.size())
    {
        std::cerr << "Erreur: les listes ont des tailles différentes." << std::endl;
        return 1;
    }

    std::sort(list_1.begin(), list_1.end());
    std::sort(list_2.begin(), list_2.end());

    long result = 0;
    for (size_t i = 0; i < list_1.size(); ++i)
        result += std::abs(list_1[i] - list_2[i]);

    std::cout << "Voici le résultat : " << result << std::endl;
    return 0;
}
