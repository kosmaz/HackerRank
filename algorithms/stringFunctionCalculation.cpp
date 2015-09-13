#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    Node():fLeaf(false),fIndex(-1),fLeft(nullptr),fRight(nullptr){}
    Node* left(){return fLeft;}
    Node* right(){return fRight;}
    int index(){return fIndex;}
    bool isLeaf(){return fLeaf;}
    string pattern(){return fPattern;}

    void setIndex(int index){fIndex=index;}
    void setLeaf(bool status){fLeaf=status;}
    void setLeftNode(Node* left){fLeft=left;}
    void setRightNode(Node* right){fRight=right;}
    void setPattern(string pattern){fPattern=pattern;}

private:
    Node(const Node&)=delete;
    Node(Node&&)=delete;
    Node& operator=(const Node&)=delete;
    Node& operator=(const Node&&)=delete;

    bool fLeaf;
    int fIndex;
    string fPattern;
    Node* fLeft;
    Node* fRight;
};


class suffixTree
{
public:
    explicit suffixTree(string generate):fString(generate)
    {
        buildTree();
    }

    void buildTree()
    {

    }

private:
    suffixTree(const suffixTree&)=delete;
    suffixTree(suffixTree&&)=delete;
    suffixTree& operator=(const suffixTree&)=delete;
    suffixTree& operator=(const suffixTree&&)=delete;

    string fString;
    Node* root;
};

void Run()
{
    string input;
    getline(cin,input,'\n');
    suffixTree tree=new suffixTree(input);

    return;
}


int main()
{
    Run();
    return 0;
}
