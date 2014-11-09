/*
 * rbtreeNode.cpp
 *
 *  Created on: Feb 1, 2009
 *      Author: asoliman
 */

#include <rbtrees.h>

namespace ASoliman {
	RBTreeNode::RBTreeNode(RBTreeNode *parent, int32_t key, void *data) {
		this->parent_ = parent;
		this->left_ = NULL;
		this->right_ = NULL;
		this->color_ = RED_;
		this->key_ = key;
		this->data_ = data;
	}

	short RBTreeNode::getColor() {
		return this->color_;
	}

	void **RBTreeNode::getData() {
		return &this->data_;
	}

	int32_t RBTreeNode::getKey() {
		return this->key_;
	}

	RBTreeNode *RBTreeNode::getLeft() {
		return this->left_;
	}

	RBTreeNode *RBTreeNode::getRight() {
		return this->right_;
	}

	RBTreeNode *RBTreeNode::getParent() {
		return this->parent_;
	}

	void RBTreeNode::setLeft(RBTreeNode *node) {
		this->left_ = node;
	}

	void RBTreeNode::setRight(RBTreeNode *node) {
		this->right_ = node;
	}

	void RBTreeNode::setParent(RBTreeNode *node) {
		this->parent_ = node;
	}

	void RBTreeNode::setKey(int key) {
		this->key_ = key;
	}

	void RBTreeNode::setData(void *data) {
		this->data_ = data;
	}
	void RBTreeNode::setColor(short color) {
		this->color_ = color;
	}
	RBTreeNode::~RBTreeNode() {
		delete this->left_;
		delete this->right_;
	}

}
