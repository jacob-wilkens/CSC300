#ifndef node_hpp
#define node_hpp

class node {
    private:
        int payload;
        node* nextNode;
    public:
        node(int payload);
        int getPayload();
        node* getNextNode();
        void setNextNode(node* newNode);
        void setPayload(int payload);

};
#endif