from package import Queue
from package import BinaryTree

def LevelOrderTraversal(root):
	if root is None:
		return 
	q=Queue()
	q.enqueue(root)
	node=None
	while not q.isEmpty():
		node=q.dequeue()
		print(node.key)
		if node.leftChild is not None:
			q.enqueue(node.leftChild)
		if node.rightChild is not None:
			q.enqueue(node.rightChild)


root=BinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
newroot=root.getLeftChild()
newroot.insertLeft(4)
newroot.insertRight(5)
newroot=root.getRightChild()
newroot.insertLeft(6)
newroot.insertRight(7)
LevelOrderTraversal(root)
