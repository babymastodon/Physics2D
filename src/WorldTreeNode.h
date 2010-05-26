#ifndef WORLDTREENODE_H
#define WORLDTREENODE_H

#include "PObject.h"
#include "Collision.h"
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

#define MAX_ELEMENTS 9
#define MIN_ELEMENTS 4
#define MIN_NODE_DIMENSION 10.0

/*!
 *	Represents a section of the world and stores the objects within that section
 *	Objects can be added or removed, if a node contains too many elements
 *	it creates 4 children each containing a smaller section of the world and adds
 *	its elements to the appropriate child
 */
class WorldTreeNode
{
	
	private:
	
		/*!
		 *	The floats cornerx, cornery, height, and width
		 *	store the location and dimentions that the
		 *	node is keeping track of in the larger world
		 *	tree.
		 */
		float cornerx;
		float cornery;
		float height;
		float width;
	
		/*!
		 *	numElements stores the number of elements stored in
		 *	the node and its children.  The haschildren boolean
		 *	stores whether or not the node has children.
		 */
		int numElements;
		bool haschildren;
	
		/*!
		 *	The children array stores null if the node has no 
		 *	childen, if the node does have children, then 
		 *	it stores pointers to the node's childre.
		 */
		WorldTreeNode* children[4];
	
		/*!
		 *	parent stores the parent node of the current node.
		 *	It stores null if the current node is the root.
		 */
		WorldTreeNode* parent;
	
		/*!
		 *	element_deque stores the elements containted in this
		 *	node in a sorted deque for faster searching.
		 */
		deque<PObject*> element_deque;

	
	public:
	
		/*!
		 *	The WorldTreeNode constructor takes the dimensions that
		 *	the WorldTreeNode occupies in the larger world tree.
		 */
		WorldTreeNode(float cx, float cy, float wi, float hi);
		~WorldTreeNode();
	
		/*!
		 *	the getChild method returns one of the node's child
		 *	nodes from the children array.
		 */
		WorldTreeNode* getChild(int x);
	
		/*!
		 *	The hasChildren method returns true if the node 
		 *	has children.
		 */ 
		bool hasChildren();
	
		/*!
		 *	The add method adds the PObject to the node.  If the node
		 *	has children, then it adds the PObject to its correct child
		 *	instead.  If adding the PObject would cause the node to have 
		 *	more than the maximum number of elements, it creates four child
		 *	nodes and adds it to the correct child(ren).
		 */
		void add(PObject* addthis);
	
		/*!
		 *	The remove method removes the given object from the node.
		 *	The given object must be at least partially within the node.
		 */
		void remove(PObject* removethis);
	
	`	/*!
		 *	The getNumElements method returns the number of elements
		 *	in the node.
		 */
		int getNumElements();
	
		/*!
		 *	The methods getcornerx, getcornery, getheight, and
		 *	getwidth return the bottom left coordinate of the node
		 *	and its dimensions.
		 */
		float getcornerx();
		float getcornery();
		float getheight();
		float getwidth();
	
		/*!
		 *	The getParent method returns the node's parent node.
		 *	It returns null if the current node doesn't have a 
		 *	parent (if it's the root of the tree).
		 */
		WorldTreeNode* getParent();
	
		/*!
		 *	The update method checks to see if all the elements
		 *	that were in the node before they moved are still in
		 *	the node, if they are not, then it adds them to the 
		 *	proper node on the tree.
		 */
		void update(int cycle);
	
		/*!
		 *	The getElements method return a deque containing all
		 *	the elemtns in the node.
		 */
		const deque<PObject*>& getElements() const;
	
		/*!
		 *	The draw method draws the boundaries of the node to
		 *	the screen.
		 */
		void draw();
	
		/*!
		 *	The addPossibleCollisions method add the given list of
		 *	collisions to the current list of possible collisions.
		 */
		void addPossibleCollisions(list<Collision*> & addToThis);
	
	private:
	
		/*!
		 *	The setParent method sets the node's parent node.
		 */
		void setParent(WorldTreeNode* thisisp);
	
		/*!
		 *	The addToChildren method adds the given PObject
		 *	to its correct position in the node's children.
		 */
		void addToChildren(PObject* addthis);
	
		/*!
		 *	The method addToDeque adds the given PObject to the 
		 *	sorted deque.  It returns true if the object was 
		 *	successfully added, false if it wasn't.
		 */ 
		bool addToDeque(PObject* addthis);
	
		/*!
		 *	The method removeFromDeque removes the given PObject
		 *	from the sorted deque.  It returns true if the object was 
		 *	successfully removed, false if it wasn't.
		 */ 		
		bool removeFromDeque(PObject* removethis);
	
		/*!
		 *	The deleteChildren method deletes the node's children.
		 *	It is used if the number of elements in the node's
		 *	children is less than a minimum number.
		 */
		void deleteChildren();
};

#endif

