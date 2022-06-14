#ifndef NODE_H
#define NODE_H

/**
 * enum node_type_e - node types
 * @NODE_COMMAND:  simple command
 * @NODE_VAR: variable name (or simply, a word)
 * Description: node types
 */

enum node_type_e
{
	NODE_COMMAND,
	NODE_VAR,
};

/**
 * enum val_type_e - value type
 * @VAL_SINT: signed int
 * @VAL_UINT: unsigned int
 * @VAL_SLLONG: signed long long
 * @VAL_ULLONG: unsigned long long
 * @VAL_FLOAT: floating point
 * @VAL_LDOUBLE: long double
 * @VAL_CHR: char
 * @VAL_STR: str (char pointer)
 * Description: value type
 */

enum val_type_e
{
	VAL_SINT = 1,
	VAL_UINT,
	VAL_SLLONG,
	VAL_ULLONG,
	VAL_FLOAT,
	VAL_LDOUBLE,
	VAL_CHR,
	VAL_STR,
};

/**
 * union symval_u - a union symval
 * @sint: signed int
 * @uint: unsigned int
 * @sllong: signed long long
 * @ullong: unsigned long long
 * @sfloat: floating point
 * @ldouble: long double
 * @chr: char
 * @str: str (char pointer)
 * Description: a union symval
 */

union symval_u
{
	long               sint;
	unsigned long      uint;
	long long          sllong;
	unsigned long long ullong;
	double             sfloat;

	long double        ldouble;
	char               chr;
	char              *str;
};

/**
 * struct node_s - a node
 * @type:  type of this node
 * @val_type: type of this node's val field
 * @val:  value of this node
 * @children: number of child nodes
 * @first_child: first child node
 * @next_sibling: if this is a child node, keep
 * @prev_sibling: pointers to prev/next siblings
 * Description: a struct node_s node
 */

struct node_s
{
	enum   node_type_e type;
	enum   val_type_e val_type;
	union  symval_u val;
	int    children;
	struct node_s *first_child;
	struct node_s *next_sibling, *prev_sibling;
};

struct  node_s *new_node(enum node_type_e type);
void    add_child_node(struct node_s *parent, struct node_s *child);
void    free_node_tree(struct node_s *node);
void    set_node_val_str(struct node_s *node, char *val);

#endif /* NODE_H */
