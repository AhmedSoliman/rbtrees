/*
 * rbtrees.h
 *
 *
 */

#ifndef RBTREES_H_
#define RBTREES_H_
#include <iostream>
#define COLOR(color) (color == 0) ? "red" : "black"

namespace ASoliman {

static const short BLACK_ = 1;
static const short RED_ = 0;
static const short LEFT_ = 100;
static const short RIGHT_ = 200;

class RBTreeNode {
	public:
		RBTreeNode(RBTreeNode *parent, int32_t key, void *data);
		~RBTreeNode();
		RBTreeNode *getParent();
		RBTreeNode *getLeft();
		RBTreeNode *getRight();
		void setLeft(RBTreeNode *node);
		void setRight(RBTreeNode *node);
		void setParent(RBTreeNode *node);
		void setData(void *data);
		void setKey(int32_t key);
		void **getData();
		int32_t getKey();
		short getColor();
		void setColor(short color);

	private:
		RBTreeNode *parent_;
		RBTreeNode *left_;
		RBTreeNode *right_;
		void *data_;
		int32_t key_;
		unsigned short color_;
};

class RBTree {
	public:
		//Basic Functions
		RBTree();
		RBTree(int32_t key, void *data);
		~RBTree();
		//rbtreePtr createRBTree(int, void *);
		//void destroyRBTree();
		RBTreeNode *insertNode(int32_t key, void *data);
		int32_t deleteNode(int32_t key);
		short isValidRedBlackTree();
		RBTreeNode *queryTree(int32_t key);
		int32_t size();
		int32_t maxDepth();
		RBTreeNode *getMinimum();
		RBTreeNode *getMaximum();

		//Visualization Functions
		void printTree();
		void printPaths();

	private:
		// Helper Functions
		RBTreeNode *root_;
		RBTreeNode *getMinimum_(RBTreeNode *tree);
		RBTreeNode *getMaximum_(RBTreeNode *tree);
		RBTreeNode *grandparent_(RBTreeNode *node);
		RBTreeNode *uncle_(RBTreeNode *node);
		RBTreeNode *getSuccessor_(RBTreeNode *node);
		RBTreeNode *getPredecessor_(RBTreeNode *node);
		RBTreeNode *sibling_(RBTreeNode *node);
		short isValidRedBlackTreeRecur_(RBTreeNode *tree);
		short rotateRight_(RBTreeNode *node);
		short rotateLeft_(RBTreeNode *node);
		short isLeaf_(RBTreeNode *node);
		RBTreeNode *treeInsert_(RBTreeNode *tree, int32_t key, void *data);
		RBTreeNode *createNode_(RBTreeNode *parent, short loc, int32_t key,
				void *data);
		void insertFix_(RBTreeNode *node);
		int32_t count_(RBTreeNode *tree, int32_t num);
		int32_t maxDepthRecur_(RBTreeNode *tree);
		RBTreeNode *queryTreeRecur_(RBTreeNode *tree, int32_t key);
		void printTreeRecur_(RBTreeNode *node);
		void printPathsRecur_(RBTreeNode *node, RBTreeNode**, int);
};

}

#endif /* RBTREES_H_ */
