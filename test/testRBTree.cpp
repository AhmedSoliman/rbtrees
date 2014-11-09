#include <gtest/gtest.h>
#include <rbtrees.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <iostream>
using namespace std;
namespace ASoliman {

int returnCorrectTimeWithinSecond(short numb) {
	if (numb > 0) {
		return numb;
	}else {
		return 1000 + numb;
	}

}

TEST(TestRBTrees, testInsert)
{
	int i;
	RBTree *myTree = new RBTree(10, NULL);
	for (i = 1; i < 1000000; i++) {
		myTree->insertNode(i, NULL);
	}
	int num = rand() % 1000000 ;
	RBTreeNode *node = myTree->queryTree(num);
	ASSERT_TRUE(node != NULL);
	ASSERT_EQ(num, node->getKey());
	delete myTree;
}

}
