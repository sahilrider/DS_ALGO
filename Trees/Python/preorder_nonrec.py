class BinaryTree:
	def __init__(self,data):
		self.key=data
		self.left=None
		self.right=None
	def getLeftChild(self):
		return self.Left
	def getRightChild(self):
		return self.right
	def insertLeft(self,data):
		newNode = BinaryTree(data)
		if self.left is not None:
			self.left=newNode
		else:
			newNode.left=self.left
			self.left=newNode
	def insertRight(self,data):
		newNode=BinaryTree(data)
		if self.right is not None:
			self.right=newNode
		else:
			newNode.right=self.right
			self.right=newNode
	def __str__(self):
		return str(self.key)

def Preorder(root):
	if not root:
		return 
	stack=[]
	stack.append(root)
	while stack :
		node=stack.pop()
		print(node.key)
		if node.right:
			stack.append(node.right)
		if node.left:
			stack.append(node.left)

root=BinaryTree(1)
root.insertLeft(2)
root.insertRight(3)
Preorder(root)