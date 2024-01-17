#include "monty.h"

void free_memory(void)
{
	free_stack(globals_var.head);
	free_stack(globals_var.new_node);
	fclose(globals_var.file);
}
