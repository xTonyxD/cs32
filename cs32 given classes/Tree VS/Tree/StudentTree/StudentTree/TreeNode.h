#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <cstddef>

namespace cs32 {

template <typename Type>
class TreeNode {
public:
	TreeNode( const Type& theElement = Type(),
			  TreeNode * theFirstChild = nullptr, 
			  TreeNode * theNextSibling = nullptr);
	TreeNode * duplicate() const;

	static int size( TreeNode * t );
	static int height( TreeNode * t );

	// no references to a TreeNode are returned
	// publicly by either Tree or TreeIterator
	// these methods are only called by Tree and
	// TreeIterator
	const Type& getElement() const;
	TreeNode* getFirstChild() const;
	TreeNode* getNextSibling() const;
	void setFirstChild( TreeNode* node );
	void setNextSibling( TreeNode* node );

	void printTreeNode( std::ostream & outs ) const;

private:
	Type element;
	TreeNode* firstChild;
	TreeNode* nextSibling;
};

}

#endif
