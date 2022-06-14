#include "shell.h"
#include "symtab/symtab.h"

extern char **environ;

void initsh(void)
{
	char **p2 = environ,  *eq;
	int len, name;
	struct symtab_entry_s *entry;

	init_symtab();

	while (*p2)
	{
		eq = strchr(*p2, '=');
		if (eq)
		{
			len = eq - (*p2);
			name[len + 1];

			strncpy(name, *p2, len);
			name[len] = '\0';
			entry = add_to_symtab(name);

			if (entry)
			{
				symtab_entry_setval(entry, eq + 1);
				entry->flags |= FLAG_EXPORT;
			}
		}
		else
		{
			entry = add_to_symtab(*p2);
		}
		p2++;
	}

	entry = add_to_symtab("PS1");
	symtab_entry_setval(entry, "$ ");

	entry = add_to_symtab("PS2");
	symtab_entry_setval(entry, "> ");
}
