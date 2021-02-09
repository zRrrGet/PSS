#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// я бы бахнул синглтон для оптимизации, но лень :(((
class stringParse {
private:
    string raw;
    vector<string> queryWords;
public:
    // ввод
    stringParse(string dataPath) {
        fstream in(dataPath, ios_base::in);

        getline(in,raw);

        int n;
        in >> n;

        queryWords.resize(n);
        for(int i = 0;i < n;++i)
            in >> queryWords[i];

        in.close();
    }

    // делим сырые данные на предложения
    vector<string> splitRaw() {

        vector<string> ans;

        for (int i = 0;i != -1;) {
            int t = i;
            i=raw.find('.',i);
            if (i>t) ans.push_back(raw.substr(t, i-t));
            if (i!=-1) ++i;

        }
        return ans;
    }

    // поиск слова в векторе предложений
    vector<string> search(string word, vector<string> inVec) {
        vector<string> ans;

        for (string &a : inVec) {

            size_t pos = a.find(word);

            if (pos != string::npos) {

                    // uppercase всех найденных слов
                    while (pos != string::npos) {
                        transform(a.begin()+pos,a.begin()+pos+word.length(),a.begin()+pos,::toupper);
                        pos = a.find(word, pos+1);
                    }

                ans.push_back(a);
            }

        }
        return ans;
    }

    vector<string> getQueryWords() const
    {
        return queryWords;
    }
};


int main()
{
    stringParse sp("in.txt");
    fstream out("out.txt", ios_base::out);
    vector<string> snt = sp.splitRaw();

    for (string &w : sp.getQueryWords()) {

        vector<string> s(sp.search(w, snt));

        out << s.size() << "\n";
        for (string &sntc : s)
            out << sntc << "." << endl;
    }

    out.close();

}




