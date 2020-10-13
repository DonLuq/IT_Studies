
class Branch:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinaryTree:

    def __init__(self):
        self.root = None

    def add(self, value):
        if self.root is None:
            self.root = Branch(value)
            # print(str(value) + ' Added')
        else:
            self._add(value, self.root)

    def _add(self, value, branch):  # self.root=branch
        if value < branch.value:
            if branch.left is None:
                branch.left = Branch(value)
                # print(str(value) + ' Added')
            else:
                self._add(value, branch.left)
        else:
            if branch.right is None:
                branch.right = Branch(value)
                # print(str(value) + ' Added')
            else:
                self._add(value, branch.right)

    def printTree(self):
        if self.root is not None:
            self._printTree(self.root)
            print()#just for new line 

    def _printTree(self, branch):
        if branch is not None:
            self._printTree(branch.left)
            print(str(branch.value), end=' ')
            self._printTree(branch.right)

    def isContain(self, value):
        if self.root is not None:
            return self._isContain(value, self.root)
        else:
            print('False')
            # return False

    def _isContain(self, value, branch):
        if branch.value == value:
            print('True')
            # return True 
        elif branch.value < value and branch.right is not None:
            self._isContain(value, branch.right)
        elif branch.value > value and branch.left is not None:
            self._isContain(value, branch.left)
        else:
            print('False')
            # return False


# TESTS
# ---------------------------
TREE = BinaryTree()
TREE.add(4)
TREE.add(5)
TREE.add(5)
TREE.add(5)
TREE.add(3)
TREE.add(1)
TREE.printTree()
TREE.isContain(5)
TREE.isContain(11)
TREE.isContain(1)
TREE.isContain(-3)
# ---------------------------
