#ifndef node_hpp
#define node_hpp
class node {
    private:
        int payload;
        node* nextNode;
    public:
        node(int payload);
        void setNextNode(node* newNode);

};
#endif