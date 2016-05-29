// not finished

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
	char val;
	Node *left;
	Node *right;
};

Node *buildTree(char *preorder_first, char *preorder_last, char *inorder_first, char *inorder_last) {
	if (inorder_first >= inorder_last) return NULL;
	Node *root = (Node*) malloc(sizeof(Node));
	root->val = *preorder_first;
	int r_in = strchr(inorder_first, root->val) - inorder_first;
	printf("root->val = %c. r_in = %d.\n", root->val, r_in);
	root->left = buildTree(preorder_first+1, preorder_first+r_in, inorder_first, inorder_first+r_in-1);
	root->right = buildTree(preorder_first+r_in+1, preorder_last, inorder_first+r_in+1, inorder_last);
}

void printTree(Node *root) {
	if (root == NULL) return;
	printTree(root->left);
	printTree(root->right);
	putchar(root->val);
}

int main() {
	for (;;) {
		char line[100];
		gets(line);
		if (line[0] == '\0') break;

		char *space = strchr(line, ' ');
		//*space = '\0';
		printf("line: '%s'\n", line);
		printf("space-1: '%s'\n", space-1);
		printf("space+1: '%s'\n", space+1);
		printf("line+strlen(line)-1: '%s'\n", line+strlen(line)-1);
		Node *root = buildTree(line, space-1, space+1, line+strlen(line)-1);
		printTree(root);
		putchar('\n');
	}

	return 0;
}
