#ifndef BSTSET_H_
#define BSTSET_H_
//#include <cstddef> //for NULL
#include "TNode.h"
#include <vector>

class BSTSet
{
    private:
    	TNode* root; //THEY HAD =NULL
    	// extra // would normally make private
    	//For the extra private classes, I referenced lecture notes for trees and BSTs
    	bool isInHelper(int v) const;
    	void postOrderDelete(TNode* subroot);
    	void removeHelper(int v, TNode*& subroot);
    	TNode* findMin(TNode* subroot);
    	void inOrderUnite(TNode* subroot);


    public:
    	// required constructors/destructor
    	BSTSet();
    	BSTSet(const std::vector<int>& input);
    	~BSTSet();

    	// required methods
    	bool isIn(int v);
    	void add(int v);
    	bool remove(int v);
    	void Union(const BSTSet& s);
    	void intersection(const BSTSet& s);
    	void difference(const BSTSet& s);
    	int size();
    	int height();
    	void printNonRec(); // create and use class MyStack

    	//void Intersect(TNode* subroot, BSTSet toModify, const BSTSet& toTraverse);
    	void postOrderIntersect(TNode* subroot, const BSTSet& toTraverse);
    	void postOrderDifference(TNode* subroot, const BSTSet& toTraverse);

    	// provided recursive print method
    	void printBSTSet();

    	// Used for testing
    	TNode* getRoot()
    	{
    		return root;
    	}

    private:
    	// provided helper methods
    	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
