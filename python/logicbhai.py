from string import ascii_uppercase
from copy import deepcopy

VARIABLES = [x for x in ascii_uppercase]
OPERATORS = ['|', '&', '!', '>', '=']
PARENTHESIS = ['(', ')']


def inputfn():
    n, mode = map(int, input().strip().split())
    sentences = []
    for i in range(0, n):
        s = input().strip()
        s = "".join(s.split())
        sentences.append(s)

    result = "".join(input().strip().split())
    return n, mode, sentences, result


def parse(sentence):
    expressions = []
    operators = []
    i = 0
    while i < len(sentence):
        if sentence[i] == '!':
            if sentence[i+1] == '(':
                i += 2
                sub_str = ''
                count = 1
                while count != 0:
                    if sentence[i] == '(':
                        count += 1
                    elif sentence[i] == ')':
                        count -= 1
                    if count > 0:
                        sub_str += sentence[i]
                    i += 1
                expressions.append(['!', parse(sub_str)])
            else:
                expressions.append(['!', sentence[i+1]])
                i += 2

        elif sentence[i] not in PARENTHESIS and sentence[i] not in OPERATORS:
            expressions.append(sentence[i])
            i += 1

        elif sentence[i] in OPERATORS:
            operators.append(sentence[i])
            i += 1

        elif sentence[i] == '(':
            i += 1
            sub_str = ''
            count = 1
            while count != 0:
                if sentence[i] == '(':
                    count += 1
                elif sentence[i] == ')':
                    count -= 1
                if count > 0:
                    sub_str += sentence[i]
                i += 1
            expressions.append(parse(sub_str))

    while operators:
        operand1 = expressions.pop()
        operand2 = expressions.pop()
        operator = operators.pop()
        expressions.append([operator, operand2, operand1])

    if len(expressions) == 1:
        return expressions[0]
    return expressions


class BinaryTreeNode:
    def __init__(self, c):
        self.data = c
        self.isOperator = True if c in OPERATORS else False
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        pass

    def make_tree(self, formula):
        x = formula[0]
        if x in OPERATORS:
            if x == '!':
                node = BinaryTreeNode(x)
                node.right = self.make_tree(formula[1])
            else:
                node = BinaryTreeNode(x)
                p = self.make_tree(formula[1])
                q = self.make_tree(formula[2])
                node.left = p
                node.right = q
        else:
            node = BinaryTreeNode(x)
        return node

    def generate_expr(self, root: BinaryTreeNode):
        if not root:
            return ""
        else:
            if root.data in OPERATORS:
                result = ""
                # result += "("
                result += self.generate_expr(root.left)
                result += root.data
                result += self.generate_expr(root.right)
                # result += ")"
                return result
            else:
                return root.data

    def divide_tree(self, root: BinaryTreeNode):
        if not root:
            return []
        roots = []
        if root.data == '&':
            roots += self.divide_tree(root.left)
            roots += self.divide_tree(root.right)
            return roots
        else:
            return [root]


def remove_implications(root: BinaryTreeNode):
    if not root:
        return None
    elif root.data == '>':
        root.left = remove_implications(root.left)
        root.right = remove_implications(root.right)

        p = root.left
        new_node = BinaryTreeNode('!')
        root.left = new_node
        root.left.right = p
        root.data = '|'

        return root
    else:
        root.left = remove_implications(root.left)
        root.right = remove_implications(root.right)
        return root


def remove_equivalence(root: BinaryTreeNode):
    if not root:
        return None
    elif root.data == '=':
        root.left = remove_equivalence(root.left)
        root.right = remove_equivalence(root.right)

        root.data = '&'
        p = root.left
        q = root.right

        negate_q = BinaryTreeNode('!')
        negate_q.right = q
        negate_p = BinaryTreeNode('!')
        negate_p.right = p

        left_node = BinaryTreeNode('|')
        left_node.left = p
        left_node.right = negate_q

        right_node = BinaryTreeNode('|')
        right_node.left = q
        right_node.right = negate_p

        root.left = left_node
        root.right = right_node
        return root
    else:
        root.left = remove_equivalence(root.left)
        root.right = remove_equivalence(root.right)
        return root


def move_not_inwards(root: BinaryTreeNode):
    if not root:
        return None
    elif root.data == '!':
        root.right = move_not_inwards(root.right)

        if root.right.data == '!':
            p = root.right.right
            print("MIN = ",p.data)
            return p
        elif root.right.data == '|':
            root.data = '&'
        elif root.right.data == '&':
            root.data = '|'
        else:
            root.right = move_not_inwards(root.right)
            print("MNI = ",root.right.data)
            return root

        p = root.right.left
        q = root.right.right

        negate_p = BinaryTreeNode('!')
        negate_p.right = p
        negate_q = BinaryTreeNode('!')
        negate_q.right = q

        root.right = negate_q
        root.left = negate_p

        root.left = move_not_inwards(root.left)
        root.right = move_not_inwards(root.right)
        print("MNI = ",root.data)
        return root
    else:
        root.left = move_not_inwards(root.left)
        root.right = move_not_inwards(root.right)
        print("MNI = ",root.data)
        return root


def spread_or_over_and(root: BinaryTreeNode):
    if not root:
        return None
    elif root.data == '|':
        if root.left.data == '&':
            r = root.right
            p = root.left.left
            q = root.left.right

        elif root.right.data == '&':
            r = root.left
            p = root.right.left
            q = root.right.right
        else:
            root.left = spread_or_over_and(root.left)
            root.right = spread_or_over_and(root.right)
            return root

        root.data = '&'
        left_node = BinaryTreeNode('|')
        left_node.left = p
        left_node.right = r

        right_node = BinaryTreeNode('|')
        right_node.left = q
        right_node.right = r

        root.left = left_node
        root.right = right_node

        root.left = spread_or_over_and(root.left)
        root.right = spread_or_over_and(root.right)
        return root
    else:
        root.left = spread_or_over_and(root.left)
        root.right = spread_or_over_and(root.right)
        return root


def is_equal(left_root: BinaryTreeNode, right_root: BinaryTreeNode):
    if left_root and right_root:
        if left_root.data != right_root.data:
            return False
        return is_equal(left_root.left, right_root.left) and is_equal(left_root.right, right_root.right)
    elif not left_root and not right_root:
        return True
    else:
        return False


def remove_true_terms(root: BinaryTreeNode):
    if not root:
        return None
    elif root.data == '&':
        if is_equal(root.left, root.right):
            return None
        else:
            root.left = remove_true_terms(root.left)
            root.right = remove_true_terms(root.right)
            return root
    elif root.data == '|':
        if is_equal(root.left, root.right):
            return None
        elif root.left.data == '!' and is_equal(root.left.right, root.right):
            return None
        elif root.right.data == '!' and is_equal(root.right.right, root.left):
            return None
        else:
            root.left = remove_true_terms(root.left)
            root.right = remove_true_terms(root.right)
            return root
    else:
        root.left = remove_true_terms(root.left)
        root.right = remove_true_terms(root.right)
        return root


def remove_unused_ops(root: BinaryTreeNode):
    if not root:
        return None
    if not root.left or not root.right:
        if root.data == '!':
            root.right = remove_unused_ops(root.right)
            return root
        elif root.data in OPERATORS:
            if not root.left:
                root.right = remove_unused_ops(root.right)
                temp = root.right
            elif not root.right:
                root.left = remove_unused_ops(root.left)
                temp = root.left
            else:
                return None
            root.data = temp.data
            root.left = temp.left
            root.right = temp.right
            return root
        else:
            root.right = remove_unused_ops(root.right)
            root.left = remove_unused_ops(root.left)
            return root
    else:
        root.right = remove_unused_ops(root.right)
        root.left = remove_unused_ops(root.left)
        return root


def convert_to_nnf(root):
    root = remove_implications(root)
    root = remove_equivalence(root)
    root = move_not_inwards(root)
    root = spread_or_over_and(root)
    return root


def simplify(root):
    root = remove_true_terms(root)
    root = remove_unused_ops(root)
    return root


def convert_to_cnf(expressions):
    modified_sentences = []
    for expression in expressions:
        expr_tree = BinaryTree()
        root = expr_tree.make_tree(expression)
        print("expr tree = ",root.data)
        root = convert_to_nnf(root)
        root = simplify(root)
        roots = expr_tree.divide_tree(root)

        for root in roots:
            modified_sentences.append(expr_tree.generate_expr(root))

    return modified_sentences


def print_sentences(sentences):
    for sentence in sentences:
        if len(sentence) == 0:
            print("")
            continue
        pr_str = sentence[0]
        for i in range(1, len(sentence)):
            pr_str += "|" + sentence[i]
        print(pr_str)
    print("###############")


def resolution(sentences, mode):
    expressions = deepcopy(sentences)
    changed = True
    while changed:
        changed = False
        for i in range(len(expressions)):
            expr1 = expressions[i]
            for j in range(i+1,len(expressions)):
                expr2 = expressions[j]
                if(not expr1 or not expr2):
                    continue
                if(len(expr1)==1 and len(expr2)==1):
                    if expr1[0] == '!'+expr2[0] or '!'+expr1[0] == expr2[0]:
                        if mode:
                            print("performed r", i+1 , " and r", j+1)
                        return 1   
                for x in expr1:
                    if len(x) == 1:
                        temp = '!'+x
                    else:
                        temp = x[0]

                    if temp in expr2:
                        if mode:
                            print("performed r", i+1 , " and r", j+1)
                        expr1.remove(x)
                        expr2.remove(temp)
                        changed = True
                        expr = expr1+expr2
                        expressions.append(expr)
                        if mode:
                            print_sentences(expressions)
                        break
    return resolve(sentences, mode)


def resolve(expressions, mode):
    sentences = deepcopy(expressions)
    changed = True
    while changed:
        changed = False
        for i in range(len(sentences)):
            if len(sentences[i]) == 1:
                temp = sentences[i][0]
                if len(temp) == 2:
                    var = temp[1]
                else:
                    var = "!" + temp
                for j in range(len(sentences)):
                    if var in sentences[j]:
                        sentences[j].remove(var)
                        if mode:
                            print("performed r", i+1, " and r", j+1)
                        changed = True
                        if len(sentences[j]) == 0:
                            return 1
                        if mode:
                            print_sentences(sentences)
                    else:
                        continue
    return 0


def main():
    n, mode, sentences, result = inputfn()

    if not len(sentences):
        print(1)
        exit(1)

    if len(result) == 1:
        result = '!' + result
    elif len(result) == 2:
        result = result[1:]
    else:
        result = '!' + '(' + result + ')'

    sentences.append(result)
    expressions = []
    for sentence in sentences:
        expr = parse(sentence)
        expressions.append(expr)

    modified_sentences = convert_to_cnf(expressions)

    sentences = modified_sentences.copy()
    for i in range(len(modified_sentences)):
        modified_sentences[i] = modified_sentences[i].split('|')

    if mode:
	    print("After Converting To CNF")
	    for x in sentences:
	        print(x)
	    print("--------------")

    # for x in modified_sentences:
    #     print(x)

    ans = resolution(modified_sentences, mode)
    print_sentences(modified_sentences)
    print(ans)


if __name__ == "__main__":
    main()