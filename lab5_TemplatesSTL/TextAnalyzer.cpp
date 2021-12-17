#include "TextAnalyzer.h"

TextAnalyzer::TextAnalyzer(const string& path) {
	this->path = path;
    analyzeFile();
    sort();
}

void TextAnalyzer::sort() {
    copy(dict.begin(),
         dict.end(),
         back_inserter<vector<pair>>(vec));
    std::sort(vec.begin(), vec.end(),
        [](const pair& l, const pair& r)
        {
            if (l.second != r.second) {
                return l.second > r.second;
            }
            return l.first > r.first;
        });
}

void TextAnalyzer::analyzeFile() {
    string line;

    ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            const size_t MAXLEN = 1000;
            char text[MAXLEN];
            in.getline(text, MAXLEN);
            char* substr = std::strtok(text, ".,:!;? ");
            while (substr != 0)
            {
                string word = substr;
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                if (word.size() >= 3) dict[word]++;
                substr = std::strtok(NULL, ".,:!;? ");
            }

        }
    }
    in.close();
}
