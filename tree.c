#include "defs.h"
#include "data.h"
#include "decl.h"

// Build and return a generic AST node
// Build and return a generic AST node
struct ASTnode *mkastnode(int op, int type,
                          struct ASTnode *left,
                          struct ASTnode *mid,
                          struct ASTnode *right,
                          struct symtable *sym, int intvalue)
{
    struct ASTnode *n;

    // Malloc a new ASTnode
    n = (struct ASTnode *)malloc(sizeof(struct ASTnode));
    if (n == NULL)
        fatal("Unable to malloc in mkastnode()");

    // Copy in the field values and return it
    n->op = op;
    n->type = type;
    n->left = left;
    n->mid = mid;
    n->right = right;
    n->sym = sym;
    n->intvalue = intvalue;
    return (n);
}

// Make an AST leaf node
struct ASTnode *mkastleaf(int op, int type,
                          struct symtable *sym, int intvalue)
{
    return (mkastnode(op, type, NULL, NULL, NULL, sym, intvalue));
}

// Make a unary AST node: only one child
struct ASTnode *mkastunary(int op, int type, struct ASTnode *left,
                           struct symtable *sym, int intvalue)
{
    return (mkastnode(op, type, left, NULL, NULL, sym, intvalue));
}

// Generate and return a new label number
// just for AST dumping purposes
static int gendumplabel(void)
{
    static int id = 1;
    return (id++);
}

// Given an AST tree, print it out and follow the
// traversal of the tree that genAST() follows
void dumpAST(struct ASTnode *n, int label, int level)
{
    int Lfalse, Lstart, Lend;

    switch (n->op)
    {
    case A_IF:
        Lfalse = gendumplabel();
        for (int i = 0; i < level; i++)
            fprintf(stdout, " ");
        fprintf(stdout, "A_IF");
        if (n->right)
        {
            Lend = gendumplabel();
            fprintf(stdout, ", end L%d", Lend);
        }
        fprintf(stdout, "\n");
        dumpAST(n->left, Lfalse, level + 2);
        dumpAST(n->mid, NOLABEL, level + 2);
        if (n->right)
            dumpAST(n->right, NOLABEL, level + 2);
        return;
    case A_WHILE:
        Lstart = gendumplabel();
        for (int i = 0; i < level; i++)
            fprintf(stdout, " ");
        fprintf(stdout, "A_WHILE, start L%d\n", Lstart);
        Lend = gendumplabel();
        dumpAST(n->left, Lend, level + 2);
        dumpAST(n->right, NOLABEL, level + 2);
        return;
    }

    if (n->op == A_GLUE)
    {
        level -= 2;
    }

    for (int i = 0; i < level; i++)
    {
        fprintf(stdout, "  ");
    }
    switch (n->op)
    {
    case A_GLUE:
        break;
    case A_FUNCTION:
        fprintf(stdout, "A_FUNCTION %s\n\n", n->sym->name);
        break;
    case A_ADD:
        fprintf(stdout, "A_ADD\n");
        break;
    case A_SUBTRACT:
        fprintf(stdout, "A_SUBTRACT\n");
        break;
    case A_MULTIPLY:
        fprintf(stdout, "A_MULTIPLY\n");
        break;
    case A_DIVIDE:
        fprintf(stdout, "A_DIVIDE\n");
        break;
    case A_EQ:
        fprintf(stdout, "A_EQ\n");
        break;
    case A_NE:
        fprintf(stdout, "A_NE\n");
        break;
    case A_LT:
        fprintf(stdout, "A_LE\n");
        break;
    case A_GT:
        fprintf(stdout, "A_GT\n");
        break;
    case A_LE:
        fprintf(stdout, "A_LE\n");
        break;
    case A_GE:
        fprintf(stdout, "A_GE\n");
        break;
    case A_INTLIT:
        fprintf(stdout, "A_INTLIT %d\n", n->intvalue);
        break;
    case A_STRLIT:
        fprintf(stdout, "A_STRLIT rval label L%d\n", n->intvalue);
        break;
    case A_IDENT:
        if (n->rvalue)
            fprintf(stdout, "A_IDENT rval %s\n", n->sym->name);
        else
            fprintf(stdout, "A_IDENT %s\n", n->sym->name);
        break;
    case A_ASSIGN:
        fprintf(stdout, "A_ASSIGN\n");
        break;
    case A_WIDEN:
        fprintf(stdout, "A_WIDEN\n");
        break;
    case A_RETURN:
        fprintf(stdout, "A_RETURN\n");
        break;
    case A_BREAK:
        fprintf(stdout, "A_BREAK\n");
        break;
    case A_CONTINUE:
        fprintf(stdout, "A_CONTINUE\n");
        break;
    case A_FUNCCALL:
        fprintf(stdout, "A_FUNCCALL %s\n", n->sym->name);
        break;
    case A_ADDR:
        fprintf(stdout, "A_ADDR %s\n", n->sym->name);
        break;
    case A_DEREF:
        if (n->rvalue)
            fprintf(stdout, "A_DEREF rval\n");
        else
            fprintf(stdout, "A_DEREF\n");
        break;
    case A_SCALE:
        fprintf(stdout, "A_SCALE %d\n", n->size);
        break;
    case A_PREINC:
        fprintf(stdout, "A_PREINC\n");
        break;
    case A_PREDEC:
        fprintf(stdout, "A_PREDEC\n");
        break;
    case A_POSTINC:
        fprintf(stdout, "A_POSTINC %s\n", n->sym->name);
        break;
    case A_POSTDEC:
        fprintf(stdout, "A_POSTDEC %s\n", n->sym->name);
        break;
    case A_NEGATE:
        fprintf(stdout, "A_NEGATE\n");
        break;
    case A_INVERT:
        fprintf(stdout, "A_INVERT\n");
        break;
    case A_LOGNOT:
        fprintf(stdout, "A_LOGNOT\n");
        break;
    case A_TOBOOL:
        fprintf(stdout, "A_TOBOOL\n");
        break;
    case A_CASE:
        fprintf(stdout, "A_CASE %d\n", n->intvalue);
        return;
    case A_DEFAULT:
        fprintf(stdout, "A_DEFAULT\n");
        return;
    case A_SWITCH:
        fprintf(stdout, "A_SWITCH\n");
        return;
    default:
        fatald("Unknown dumpAST operator", n->op);
    }

    // General AST node handling
    if (n->left)
    {
        dumpAST(n->left, NOLABEL, level + 2);
    }

    if (n->right)
        dumpAST(n->right, NOLABEL, level + 2);
}
