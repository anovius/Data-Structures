#include "Node.h"
Node::Node(int d, Node* n, Node* p) {
	data = d;
	next = n;
	prev = p;
}