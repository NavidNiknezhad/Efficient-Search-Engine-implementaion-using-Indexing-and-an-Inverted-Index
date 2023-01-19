#include <list>
#include <iostream>

int WORDCOUNT;

struct Document
{
    string docName;// Document name
    //int location;
    vector<int> locations;// location
    int freq() { return locations.size(); }
};

struct DATA
{
    string key; //word
    int info; //Frequency
    vector<Document> positioning;//Record Form
    double freq(){
        double freq;
        for(int i = 0; i < positioning.size(); i++)
            freq += positioning[i].freq();
        return (freq / WORDCOUNT) * 1000;
    }
};
ofstream fout;

void print(DATA ss) {
    //Document d;
    for(int i = 0; i < ss.positioning.size(); i++){
        for(int j=0; j < ss.positioning[i].locations.size(); j++ )
        //if(ss.positioning[i].docName == ){
            cout << ss.key << "     " << ss.info << "     " << ss.positioning[i].docName << "     " << ss.positioning[i].locations[j] << endl;
       // }

    }

    //return;
}
void fprint(DATA ss) {

    for(int i = 0; i < ss.positioning.size(); i++){
        for(int j=0; j < ss.positioning[i].locations.size(); j++ )
            fout << ss.key << "     " << ss.info << "     " << ss.positioning[i].docName << "     " << ss.positioning[i].locations[j] << endl;
    }
    //return;
}


class CIndex {
   // vector <IndexItem> indexList;//direction chart
    //vector <Document> collection;//Document set
   AVLTreeExt<DATA, string> tree;

public:
    CIndex(){

    }
    void printDictionary(){

        tree.AVL_Traverse(print);
    }
    void printAVLTree(){
         tree.AVL_Print();
    }
    void getTotalWord(){
        cout << "The total words in the dictionary is  " << WORDCOUNT<< "  and there are  " << tree.AVL_Count() << "  nodes in the tree " << endl;
    }
    void printD2File(){
        fout.open("C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\data_out.TXT");
        tree.AVL_Traverse(fprint);
        fout.close();
    }

    void LoadDictionary(){
        ifstream fin;
        string inFileName, filePath;
        cout << "What is your input file: (assuming the file is in C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\ directory)";
        cin >> inFileName;
        filePath = "C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\" + inFileName;
        fin.open(filePath);
        if (cout.fail( ))    {
            cout << "Output file opening failed.\n";
            exit(1);
        }
        string line;
        while (getline(fin, line))
        {
            std::istringstream iss(line);
            string a, c;
            int b, d;
            if (!(iss >> a >> b >> c >> d)) { break; } // error

            // process pair (a,b,c,d)
            cout << a << b << c << d << endl;
        }

    }

    void readFile() {
        ifstream fin;
        string inFileName, filePath;
        cout << "What is your input file: (assuming the file is in C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\FileInputs directory)";
        cin >> inFileName;
        filePath = "C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\FileInputs\\" + inFileName;
        fin.open(filePath);
        if (cout.fail( ))    {
            cout << "Output file opening failed.\n";
            exit(1);
        }
        WORDCOUNT = 0;
        int location = 1;
        string word;
        while (fin >> word) {
            word = trim(word);
            if (word == ""){
                continue;
            }

            DATA item;
            item.key = word;
            item.info = 1;
            WORDCOUNT++;
            Document d;
            d.locations.push_back(location);
            d.docName = inFileName;
            item.positioning.push_back(d);
            if (tree.AVL_Retrieve(word, item)){
                item.info++;
                tree.AVL_Update(item.key, item);
                //continue;
            } else{
                //item.posting.push_back();// Add the document ID of this file to posting
                tree.AVL_Insert(item);
                location++;
            }

        }
        //Indexing();
        fin.close();
    }

    void readFiles() {
        ifstream fin;
        string inFileName, filePath, filename;
        cout << "What is your input file: (assuming the file is in C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\FileInputs directory)";
        cin >> inFileName;
        list <string> fileList;
        while (cin >> inFileName) {
            filename = trim(inFileName);
            cout << filename;
            fileList.push_back(filename);

        }
        list<string>::iterator it;
        fileList.begin();
        for (int i = 0; i < fileList.size(); i++) {
            advance(it, i);
            filePath = "C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\FileInputs\\" + *it;
            fin.open(filePath);
            //fout.open("C:\\Users\\navid\\CLionProjects\\Prc7_Task4\\data_out.TXT");
            WORDCOUNT = 0;
            int location = 1;
            string word;
            while (fin >> word) {
                word = trim(word);
                if (word == ""){
                    continue;
                }

                DATA item;
                item.key = word;
                item.info = 1;
                WORDCOUNT++;
                Document d;
                d.locations.push_back(location);
                d.docName = inFileName;
                item.positioning.push_back(d);
                if (tree.AVL_Retrieve(word, item)){
                    item.info++;
                    tree.AVL_Update(item.key, item);
                    //continue;
                } else {
                    //  item.posting.push_back();// Add the document ID of this file to posting
                    tree.AVL_Insert(item);
                    location++;
                }
            }
        }// }
    fin.close();
    }

    string trim(string input) {
        stringstream ss;
        for (int x = 0; x < (int) input.size(); x++) {
            if (isalpha(input[x])){
                input[x] = tolower(input[x]);
                ss << input[x];
            }
        }

        if (ss.str().length() > 0)
            return ss.str();
        else
            return "";

    }

};

/*

bool cmp(DATA a, DATA b)
{
    return a.key<b.key;// Items are sorted from small to large
}
int CIndex::sortIndex()
{
    sort(indexList.begin(), indexList.end(), cmp);
    return 0;
}

//@name <CIndex::mergeIndex>
//@brief <index table merges similar items>

int CIndex::mergeIndex()
{
    DATA item1,item2;

    sortIndex();
    vector<IndexItem>::iterator it_cur=indexList.begin();/ / Create an iterator
    vector<IndexItem>::iterator it_next = it_cur + 1;
    vector<int> temp;
    vector<int>::iterator p1, p2;/ / Iterator for merging posting
    while (it_cur != indexList.end())
    {
        if(it_cur+1!=indexList.end()) it_next = it_cur + 1;
        else break;
        while((*it_cur).term == (*it_next).term)
        {/ / All the terms that are duplicated with the current term are processed in this loop

                                                                                           / / Sort the two posts
            sort((*it_cur).posting.begin(), (*it_cur).posting.end());
            sort((*it_next).posting.begin(), (*it_next).posting.end());
            / / Orderly merge the posting of both
            p1 = (*it_cur).posting.begin();
            p2 = (*it_next).posting.begin();
            while (p1 != (*it_cur).posting.end() && p2 != (*it_next).posting.end())
            {
                if ((*p1) < (*p2))/ / Add a small element to the result set
                        {
                                temp.push_back(*p1);
                        //This while is used to skip duplicate elements

                        p1++;
                        }
                else if((*p1) > (*p2))
                {
                    temp.push_back(*p2);

                    p2++;
                }
                else
                {
                    temp.push_back(*p1);
                    / / The same two, then both move backwards to avoid duplication
                    p1++;
                    p2++;
                }
            }
            while(p1 != (*it_cur).posting.end())/ / If string 1 is not merged, then copy the part directly after string 1
            {
                temp.push_back(*p1);
                p1++;
            }
            while(p2 != (*it_next).posting.end())
            {
                temp.push_back(*p2);
                p2++;
            }
            / / Delete the result set repeat
            temp.erase(unique(temp.begin(), temp.end()), temp.end());

            (*it_cur).frequence++;/ / word frequency increase
            (*it_cur).posting.assign(temp.begin(), temp.end());/ / Copy the results
            indexList.erase(it_next);/ / Remove duplicates
            temp.clear();
            if (it_cur + 1 != indexList.end()) it_next = it_cur + 1;
            else break;
        }

        it_cur++;
    }

*/