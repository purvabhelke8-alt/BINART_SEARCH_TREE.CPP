### PROGRAM:
from collections import deque
import copy

# ============================================================
# 🌳 BINARY SEARCH TREE - PRACTICAL 4
# ============================================================

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:

    def __init__(self):
        self.root = None

    # 1. INSERT
    def insert(self, node, data):
        if node is None:
            return Node(data)

        if data < node.data:
            node.left = self.insert(node.left, data)
        elif data > node.data:
            node.right = self.insert(node.right, data)
        else:
            print("⚠️ Duplicate value is not allowed.")

        return node

    def add(self, data):
        self.root = self.insert(self.root, data)

    # 2. SEARCH
    def search(self, node, data):
        if node is None:
            return False

        if node.data == data:
            return True
        elif data < node.data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)

    # 3. DELETE
    def delete(self, node, data):

        if node is None:
            return None

        if data < node.data:
            node.left = self.delete(node.left, data)

        elif data > node.data:
            node.right = self.delete(node.right, data)

        else:
            # No child
            if node.left is None and node.right is None:
                return None

            # Only right child
            elif node.left is None:
                return node.right

            # Only left child
            elif node.right is None:
                return node.left

            # Two children
            else:
                temp = node.right

                while temp.left is not None:
                    temp = temp.left

                node.data = temp.data
                node.right = self.delete(node.right, temp.data)

        return node

    # 4. INORDER
    def inorder(self, node):
        if node is not None:
            self.inorder(node.left)
            print(node.data, end=" ")
            self.inorder(node.right)

    # 5. PREORDER
    def preorder(self, node):
        if node is not None:
            print(node.data, end=" ")
            self.preorder(node.left)
            self.preorder(node.right)

    # 6. POSTORDER
    def postorder(self, node):
        if node is not None:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.data, end=" ")

    # 7. DEPTH
    def depth(self, node):
        if node is None:
            return 0

        left = self.depth(node.left)
        right = self.depth(node.right)

        return 1 + max(left, right)

    # 8. MIRROR
    def mirror(self, node):
        if node is not None:
            node.left, node.right = node.right, node.left

            self.mirror(node.left)
            self.mirror(node.right)

    # 9. COPY
    def create_copy(self):
        new_tree = BST()
        new_tree.root = copy.deepcopy(self.root)
        return new_tree

    # 10. PARENT NODES
    def display_parents(self, node):

        if node is not None:

            if node.left is not None or node.right is not None:

                left = node.left.data if node.left else "None"
                right = node.right.data if node.right else "None"

                print(
                    "Parent:", node.data,
                    "Left Child:", left,
                    "Right Child:", right
                )

            self.display_parents(node.left)
            self.display_parents(node.right)

    # 11. LEAF NODES
    def display_leaves(self, node):

        if node is not None:

            if node.left is None and node.right is None:
                print(node.data, end=" ")

            self.display_leaves(node.left)
            self.display_leaves(node.right)

    # 12. LEVEL-WISE DISPLAY
    def level_order(self):

        if self.root is None:
            print("🌱 Tree is empty.")
            return

        queue = deque()
        queue.append(self.root)

        print("Level-wise Tree:")

        while queue:

            current = queue.popleft()

            print(current.data, end=" ")

            if current.left is not None:
                queue.append(current.left)

            if current.right is not None:
                queue.append(current.right)

        print()


# ============================================================
# 🎯 MAIN PROGRAM
# ============================================================

def main():

    tree = BST()

    while True:

        print("\n====================================")
        print("🌳 BINARY SEARCH TREE")
        print("====================================")
        print("1. Insert")
        print("2. Delete")
        print("3. Search")
        print("4. Inorder Traversal")
        print("5. Preorder Traversal")
        print("6. Postorder Traversal")
        print("7. Depth of Tree")
        print("8. Mirror Image")
        print("9. Create Copy")
        print("10. Display Parent Nodes")
        print("11. Display Leaf Nodes")
        print("12. Level-wise Display")
        print("0. Exit")
        print("====================================")

        choice = input("👉 Enter your choice: ")

        # INSERT
        if choice == "1":

            try:
                data = int(input("Enter value: "))

                if tree.search(tree.root, data):
                    print("⚠️ Duplicate value!")
                else:
                    tree.root = tree.insert(tree.root, data)
                    print("✅ Value inserted successfully.")

            except ValueError:
                print("❌ Enter an integer only.")

        # DELETE
        elif choice == "2":

            try:
                data = int(input("Enter value to delete: "))

                if tree.search(tree.root, data):
                    tree.root = tree.delete(tree.root, data)
                    print("✅ Value deleted successfully.")
                else:
                    print("❌ Value not found.")

            except ValueError:
                print("❌ Enter an integer only.")

        # SEARCH
        elif choice == "3":

            try:
                data = int(input("Enter value to search: "))

                if tree.search(tree.root, data):
                    print("✅ Value found.")
                else:
                    print("❌ Value not found.")

            except ValueError:
                print("❌ Enter an integer only.")

        # INORDER
        elif choice == "4":

            print("Inorder:", end=" ")
            tree.inorder(tree.root)
            print()

        # PREORDER
        elif choice == "5":

            print("Preorder:", end=" ")
            tree.preorder(tree.root)
            print()

        # POSTORDER
        elif choice == "6":

            print("Postorder:", end=" ")
            tree.postorder(tree.root)
            print()

        # DEPTH
        elif choice == "7":

            print("📏 Depth of Tree:", tree.depth(tree.root))

        # MIRROR
        elif choice == "8":

            if tree.root is None:
                print("🌱 Tree is empty.")
            else:
                tree.mirror(tree.root)
                print("🪞 Mirror image created.")
                print("Inorder:", end=" ")
                tree.inorder(tree.root)
                print()

        # COPY
        elif choice == "9":

            copied_tree = tree.create_copy()

            print("📋 Tree copied successfully.")
            print("Copied Tree Inorder:", end=" ")
            copied_tree.inorder(copied_tree.root)
            print()

        # PARENT NODES
        elif choice == "10":

            if tree.root is None:
                print("🌱 Tree is empty.")
            else:
                print("\n👨‍👩‍👧 Parent Nodes:")
                tree.display_parents(tree.root)

        # LEAF NODES
        elif choice == "11":

            if tree.root is None:
                print("🌱 Tree is empty.")
            else:
                print("🍃 Leaf Nodes:", end=" ")
                tree.display_leaves(tree.root)
                print()

        # LEVEL-WISE
        elif choice == "12":

            tree.level_order()

        # EXIT
        elif choice == "0":

            print("👋 Thank you!")
            break

        else:

            print("❌ Invalid choice. Try again.")


# ============================================================
# 🚀 START PROGRAM
# ============================================================

if __name__ == "__main__":
    main()

