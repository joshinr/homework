#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Node
{
public:
    Node()
    {
        wordCount = 0;
        isWord = false;
    }
    std::map<char, Node*> data;
    int wordCount;
    bool isWord;
    
    void add(std::string word)
    {
        add(word, 0);
    }
    
    void add(string s, int index)
    {
        ++wordCount;
        if (index == s.length() )
            return;
        
        Node *node = nullptr;
        char chr = s.at(index);
        auto itr = data.find(chr);
        if (itr == data.end())
        {
            node = new Node();
            data[chr] = node;
        }
        else
        {
            node = itr->second;
        }
        
        node->add(s, ++index);
    }
    
    void find(string word)
    {
        int count = find(word, 0);
        cout << count << endl;
    }
    
    int find(string word, int index)
    {
        if (index == word.length() )
            return wordCount;
        
        auto itr = data.find(word.at(index));
        if (itr == data.end())
        {
            return 0;
        }
        return itr->second->find(word, ++index);
    }
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   
    Node *root = new Node();
    
    int opnum;
    string op;
    string word;
    cin >> opnum;
    
    for (int i=0; i < opnum; ++i)
    {
        cin >>op >>word;
        if (op == "add")
        {
            root->add(word);
        }
        else
        {
            root->find(word);
        }
    }
    return 0;
    
}

/*
Sample Input

4
add hack
add hackerrank
find hac
find hak

Sample Output

2
0
*/
